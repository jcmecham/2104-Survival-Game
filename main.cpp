#include <iostream>
#include <algorithm>

#include <stdio.h>
#include <string.h>

#include "lands.h"
#include "player.h"
#include "colors.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice){
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n"){
        playerChoice = NORTH;
    } else if(input == "s"){
        playerChoice = SOUTH;
    } else if(input == "e"){
        playerChoice = EAST;
    } else if(input == "w"){
        playerChoice = WEST;
    } else {
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


void printMap(int MAPSIZE,int playerX,int playerY,Land* m[20][20]){
    std::map<std::string,int> LandMap  = {{"forest",1},{"desert",2},{"mountain",3},{"everglades",4},{"kingdom",5},{"volcano",6},{"island of Elves",7},{"lake",8}};

    cout << SetBOLD<<"-------------------------|Game Map|----------------------------|LANDS KEY:|-------"<<RESETTEXT<<endl;
    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            

            if(i ==playerY && j ==playerX){ //if player is at this position
                
                cout << " O ";
            }else {
                string currentLandType = m[j][i]->getShortDescription();
                switch(LandMap[currentLandType] ) // run-time
              {
                case 1:
                    cout << SetBackDRKGRN;
                    break;
                case 2:
                    cout << SetBackYEL;
                    break;
                case 3:
                    cout << SetBackBRN;
                    break;
                case 4:
                cout << SetBackLTGRN;
                    break;
                case 5:
                cout << SetBackWHT;
                    break;
                case 6:
                cout << SetBackORG;
                    break;
                case 7:
                cout << SetBackMAG;
                    break;
                case 8:
                cout << SetBackBLU;
                    break;
                default:
                    break;
              };

                cout << "   "<< RESETTEXT  ;
                
                if(j == MAPSIZE - 1 ){
                    
                    if(i== 1){
                        cout <<SetBackBRN<<SetBOLD<< "\t Mountain "<<RESETTEXT;
                    }else if(i== 3){
                        cout <<SetBackORG<<SetForeBLK<<SetBOLD<< "\t Volcano "<<RESETTEXT;
                    }else if(i== 5){
                        cout <<SetBackYEL<<SetForeBLK<<SetBOLD<< "\t Desert "<<RESETTEXT;
                    }else if(i== 7){
                        cout <<SetBackWHT<<SetForeBLK<<SetBOLD<< "\t Kingdom "<<RESETTEXT;
                    }else if(i== 9){
                        cout <<SetBackLTGRN<<SetForeBLK<<SetBOLD<< "\t Everglades "<<RESETTEXT;
                    }else if(i== 11){
                        cout <<SetBackDRKGRN<<SetBOLD<< "\t Forest "<<RESETTEXT;
                    }else if(i== 13){
                        cout <<SetBackBLU<<SetBOLD<< "\t Lakes "<<RESETTEXT;
                    }else if(i== 15){
                        cout <<SetBackMAG<<SetBOLD<< "\t Island of Elves "<<RESETTEXT;
                    }
                }
            }
        }
        cout <<endl;
    }
    cout <<endl<<endl;
}


int main(){
   
    const int  MAP_SIZE = 20;
    //initialize player
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST, 
                  MAP_SIZE/2, MAP_SIZE/2);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
        }
    }
    
    
        
    
    while(player.isAlive()){
        clearTerminal();
        
        cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl;
        player.newTurn();
        
        
        
        // Give description of surroundings
        int  x = player.getX();
        int  y = player.getY();
        
        cout << map[x][y]->getLongDescription() << endl << endl;
        cin.clear();
        string desc = map[x][y]->visit(player);
        
        cout << desc << endl << endl;
        
        
        
        
        cout << player.printStats() << endl << endl;
        
        if(player.hasWon){
            cout << "YOU WON!!! YOU ARE THE KING!!! "<<endl;
            break;
        }
        
        if(!player.isAlive()){
            cout << "\tYou died x_x"<<endl;
            break;
        }

        printMap(MAP_SIZE,x,y,map);
        
        int northYPos = y - 1;
        int southYPos = y + 1;
        int westXPos = x - 1;
        int eastXPos = x + 1;
        //Handling vertical boundry conditions
        if(y==0){
           northYPos = 19;
        }else if(y==19){
           southYPos = x==0;
        }
         //Handling Horizontal boundry conditions
        if(x==0){
            westXPos = 19;
        }else if(x==19){
            eastXPos = x==0;
        }
        
        
        cout << "To the north you see a " << map[x][northYPos]->getShortDescription() << endl;
        cout << "To the south you see a " << map[x][southYPos]->getShortDescription() << endl;
        cout << "To the east you see a " << map[eastXPos][y]->getShortDescription() << endl;
        cout << "To the west you see a " << map[westXPos][y]->getShortDescription() << endl;
         
        
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice){
            case NORTH:
                if(player.getY() != 0){
                player.setY(player.getY() - 1);
                    
                }else{
                   player.setY(19); 
                }
                break;
            case SOUTH:
            if(player.getY() != 19){
                player.setY(player.getY() + 1);
                    
                }else{
                   player.setY(0); 
                }
                
                break;
            case EAST:
                 if(player.getX() != 19){
                player.setX(player.getX() + 1);
                    
                }else{
                   player.setX(0); 
                }
                break;
            case WEST:
                if(player.getX() != 0){
                player.setX(player.getX() - 1);
                    
                }else{
                   player.setX(19); 
                }
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }

    }
    
    
    

    return 0;
}
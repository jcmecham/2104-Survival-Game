#include "lands.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* srand, rand */
#include <sstream>
#include <time.h> 

using namespace std;



Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case MOUTAIN:
            return new Mountain;
            break;
        case EVERGLADES:
            return new Everglades;
            break;
        case KINGDOM:
            return new Kingdom;
            break;
        case VOLCANO:
            return new Volcano;
            break;
        case ISLANDOFELVES:
            return new IslandOfElves;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst Thirst +2";
    p.setThirst(p.getThirst() + 2);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some! Hunger +1";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods! Health -1";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears! Health -2";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}

string Mountain::getShortDescription(){
    
    return "mountain";
}

string Mountain::getLongDescription(){
    return "You arrive at towering jagged mountains.";
}


string Mountain::visit(Player& p){
    srand (time(NULL));
    string description;
    
    cout << "While traversing the mountain tops you arrive at a bridge and a troll pops out and starts speaking "<<endl;

    cout <<endl<<"\t'To pass you must answer me riddle'"<< endl<<"\t'The rich need this, the poor have this and if you eat it you die'" <<endl<<endl ;
    
    cout << "Answer here:";
    
    char * answer;
    string test;
    
    
    
    std::cin >> test;
    answer = &test[0];
    
    if(!strcmp(answer,"nothing")){
        description =  "\n\t'Hmm...' The troll says 'you are smarter than you look, you shall pass'";

        if(rand()%100>=49){
            description +=  "\n You find the trolls food, Hunger +3\n";
            p.setHunger(p.getHunger() + 3);
        }

    }else{
      description =  "\n\t'WRONG!!! Time for you to die'\n\nThe troll says as he charges at you. He hits you with his club right before you stab him through the neck. Health -1";
      p.setHealth(p.getHealth()-1);
      
    }
    

    return description;
}

string Everglades::getShortDescription(){
    
    return "everglades";
}

string Everglades::getLongDescription(){
    return "You come upon a thick grassy everyglade, crawling with predators.";
}

string Everglades::visit(Player& p){
    string description = "You start hunting for alligators.";

    //50 50 chance if statement runs
    if(rand()%100>=49){
          description += "\nYou killed a huge alligator and feast on it. Hunger +5  Thirst +2\n";
          p.setHunger(p.getHunger() + 3);
          p.setThirst(p.getThirst() + 2);
      }else{
        description += "\nYou didn't find any gators but you find a clean stream and magic beans. Health +2 Thirst +1\n";
        p.setThirst(p.getThirst() + 1);
        p.setHealth(p.getHealth() + 2);
      }
    
    return description;
}

string Kingdom::getShortDescription(){
    
    return "kingdom";
}

string Kingdom::getLongDescription(){
    return "You find a stone path, when you following that stone path you see a castle in the distance.";
}


string Kingdom::visit(Player& p){
    string description = "You start walking towards the castle";

    int temp = rand() % 100;
    //50 50 chance if statement runs
    if(p.getHunger() < 2){
          description += "\nYou are starving so you rob a food stall/ Hunger +2\n";
          p.setHunger(p.getHunger() + 2);
    }else if(temp <= 33){
          description += "\nYou attack a knight and he kicks your ass. Health -2\n";
          p.setHealth(p.getHealth() - 2);
      }else if(temp <= 94){
          description += "\nA towns person hands you a water. Thirst +1\n";
          p.setThirst(p.getThirst() + 1);
      }else{
        description += "\nYou attack a knight , you steal his gear, sneak into the castle and kill the king. You are the king now. Health +100 Hunger +100 Thirst +100\n";
          p.setHealth(p.getHealth() + 100);
          p.setHunger(p.getHunger() + 100);
          p.setThirst(p.getThirst() + 100);
          p.hasWon = true;
      }

    return description;
}


string Volcano::getShortDescription(){
    
    return "volcano";
}

string Volcano::getLongDescription(){
    return "You find yourself at the bottom of a volcano, your hear a roar in the distance...";
}


string Volcano::visit(Player& p){
    int temp = rand() % 20;
    string description;
    if(temp <1){
        description = "You fight a dragon and kill him with a knife up the butt Health +5";
        p.setHealth(p.getHealth() + 5);
            
    }else{
        description = "You fight a dragon and it knocks you under a rock Health -1";
        p.setHealth(p.getHealth() - 1);
    }
    

    return description;
}

string IslandOfElves::getShortDescription(){
    
    return "island of Elves";
}

string IslandOfElves::getLongDescription(){
    return "You see a beautiful island not far from shore so you swim to it, upon arriving at the shores you see a group of small men approaching.";
}


string IslandOfElves::visit(Player& p){
    int hNum = rand() % 5;
    string description = "The men feed you and give you water Thirst +1 Hunger +" + to_string(hNum);
    
    
    
    p.setThirst(p.getThirst() + 1);
    p.setHunger(p.getHunger() + hNum);

    return description;
}



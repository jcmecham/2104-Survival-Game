#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

using namespace std;

class Player {
    public:
    Player(int health, int hunger, int thirst,
            int x, int y);
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
    int getHunger() const;
    int getThirst() const;
    int getHealth() const;
    void setThirst(int t);
    void setHunger(int h);
    void setHealth(int h);
    void newTurn();
    string printStats();
    bool isAlive() const;
    bool hasWon;
    
    static const int DEFAULT_HEALTH = 5;
    static const int DEFAULT_HUNGER = 10;
    static const int DEFAULT_THIRST = 5;
    
    private:
    int health;
    int hunger;
    int thirst;
    int x;
    int y;
};

#endif
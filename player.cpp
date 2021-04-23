#include "player.h"

Player::Player(int health, int hunger, int thirst,
        int x, int y){
    this->health = health;
    this->hunger = hunger;
    this->thirst = thirst;
    this->x = x;
    this->y = y;
    this->hasWon = false;
}

int Player::getX() const{
    return x;
}

int Player::getY() const{
    return y;
}

void Player::setX(int newX){
    x = newX;
}

void Player::setY(int newY){
    y = newY;
}

int Player::getHunger() const{
    return hunger;
}

int Player::getThirst() const{
    return thirst;
}

int Player::getHealth() const{
    return health;
}

void Player::setThirst(int t){
    if(t <= 0){
        health = 0;
        t = 0;
    }
    thirst = t;
        
    
}

void Player::setHunger(int h){
    if(h <= 0){
        health = 0;
        h = 0;
    }
    hunger = h;
    
}

void Player::setHealth(int h){
    if(h<=0)h=0;
    health = h;
}

void Player::newTurn(){
    hunger--;
    if(hunger < 0) hunger = 0;
    thirst--;
    if(thirst < 0) thirst = 0;
    
    if(hunger == 0 || thirst == 0){
        health--;
    }
}

string Player::printStats(){
    ostringstream ss;
    ss << "health: " << health << " ";
    ss << "hunger: " << hunger << " ";
    ss << "thirst: " << thirst;
    return ss.str();
}

bool Player::isAlive() const{
    return health > 0;
}
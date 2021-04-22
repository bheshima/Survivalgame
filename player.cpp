#include "player.h"
#include "lands.h"

Player::Player(unsigned int health, unsigned int hunger, unsigned int thirst,
        unsigned int x, unsigned int y){
    this->health = health;
    this->hunger = hunger;
    this->thirst = thirst;
    this->x = x;
    this->y = y;
}

unsigned int Player::getX() const{
    return x;
}

unsigned int Player::getY() const{
    return y;
}

void Player::setX(unsigned int newX){
    x = newX;
}

void Player::setY(unsigned int newY){
    y = newY;
}

unsigned int Player::getHunger() const{
    return hunger;
}

unsigned int Player::getThirst() const{
    return thirst;
}

unsigned int Player::getHealth() const{
    return health;
}

void Player::setThirst(unsigned int t){
    thirst = t;
}

void Player::setHunger(unsigned int h){
    hunger = h;
}

void Player::setHealth(unsigned int h){
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


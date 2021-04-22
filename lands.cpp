#include "lands.h"

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
         case CITY:
            return new City;
            break;

        case RIVER:
            return new River;
            break;

         case MOUNTAIN:
            return new Mountain;
            break;
         case SNOWYLAND:
            return new SnowyLand;
            break;

        case CAVE:
            return new Cave;
            break;

        default:
            return new Lake;
            break;
    }

}

string Lake::getShortDescription(){
    return "Lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){

    return "Forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";

    int chance = rand() % 100;

    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }

    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }


    return description;
}

string Desert::getShortDescription(){

    return "Desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";

    p.setThirst(p.getThirst() - 1);

    return description;
}

string City :: getShortDescription(){

             return "City";
}


string City::getLongDescription(){
    return"You have aarrive in the city where you can take a breath and seek for any help you need";
}

string City::visit(Player& p) {
    string description = "Luckly it happens that you meet a doctor in the city and helps to restore your health";

    int chance = rand() % 100;

    // chance of having more options in the city to help you with your health
    if (chance > 50) {
        description = "you get help with food and water";
       p.setHealth(p.getHealth() + 1);
       p.setHunger(p.getHunger() + 1);
       p.setThirst(p.getThirst() + 1);
        return description;
    }

    // Chance of meeting people
    if (chance < 10 && chance > 5) {
        description = "Unfortunately you just meet people who don't want to help";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}

string River::getShortDescription(){

    return "River";
}

string River::getLongDescription(){
    return "It happens that you runs into a river and found the drinkable water ";
}

string River::visit(Player& p){
    string description = "Even though River's water is not very clean but at least it helps you to hydrate";

    p.setThirst(p.getThirst() + 1);

    return description;
}


string Mountain :: getShortDescription(){

             return "Mountain";
}


string Mountain::getLongDescription(){
    return"You have aarrive in the city where you can take a breath and seek for any help you need";
}

string Mountain::visit(Player& p) {
    string description = "Wondering around and run into the mountain with randomly fruits spread everywhere or by hunting ";

    int chance = rand() % 100;

    // chance of getting enexpexted food
    if (chance > 50) {
        description = "you get food";
       p.setHealth(p.getHealth() + 1);
       p.setHunger(p.getHunger() + 1);
        return description;
    }

    // Chance of meeting people
    if (chance < 15 && chance > 10) {
        description = "The mountain blocks you to move forward and the only option is to go back in order to find a way ";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}

string SnowyLand :: getShortDescription(){

             return "Snowy Land";
}


string SnowyLand::getLongDescription(){
    return" you got lucky and found the frozen snow and get some freshened water";
}

string SnowyLand::visit(Player& p) {
    string description = "You eventually got water enrich your hydration";

    int chance = rand() % 100;

    // chance that the snow froze
    if (chance > 30) {
        description = "you get water";
       p.setThirst(p.getThirst() + 1);
        return description;
    }

    // Chance of sunny day
    if (chance < 10 && chance > 5) {
        description = "The snow is really frozen and you can't get nothing out of it";
         p.setThirst(p.getThirst() - 1);
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}

string Cave::getShortDescription() {
    return "Cave";
}

string Cave::getLongDescription() {
    return "You arrive at the cave, it's dark, but may be a good place to rest and hide.";
}

string Cave::visit(Player& p) {
    string description = "While entering, you notice a strange sound and you leave immediately unharmed.";

    int chance = rand() % 100;

    // Chance to find good shelter
    if (chance > 50) {
        description = "You found a suitible place to rest and take a nap.";
        p.setHealth(p.getHealth() + 2);
        return description;
    }

    // Chance to be crushed by a rock
    if (chance < 10 && chance > 5) {
        description = "You still can hear some strange sounds and decided to get out right away without enough rest .";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
}















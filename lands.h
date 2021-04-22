#ifndef LANDS_H
#define LANDS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;

enum LandTypes {LAKE, FOREST, DESERT, CITY, RIVER, MOUNTAIN, SNOWYLAND, CAVE, MAX_NUM_LANDS};

class Land {
    public:
    virtual string getShortDescription() = 0;
    virtual string getLongDescription() = 0;
    virtual string visit(Player &p) = 0;

    private:
};

class Lake : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};

class Forest : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};

class Desert : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};

class City : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};


class River : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};


class Mountain : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};

class SnowyLand : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};


class Cave : public Land {
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);

    private:
};

Land* getRandomLand(void);


#endif
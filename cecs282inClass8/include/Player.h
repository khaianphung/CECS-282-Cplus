#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Dice.h"

using namespace std;

class Player
{
    private:
        int score;
        string name;
    public:
        Player(string n, int s );
        void setName(string n);

        string getName(){return name;}
        void setScore(int s);
        int getScore(){return score;}
        void addPoint(int p);



};

#endif

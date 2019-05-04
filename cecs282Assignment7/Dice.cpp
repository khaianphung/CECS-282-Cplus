#include "Dice.h"
#include <cstdlib>
#include <ctime>
Dice::Dice()
{

public:{

    Dice( int s )
    {
        srand(time(NULL));
        sides = s;
        value = rand() % sides + 1;
    }


    int roll()
    {
        value = rand() % sides + 1;
        return value;
    }


    int getValue()
    {
        return value;
    }

    bool setValue( int val )
    {
        if ( val > 0 && val <= sides )
        {
            value = val;
            return true;
        }
        return false;
    }
};
//ctor



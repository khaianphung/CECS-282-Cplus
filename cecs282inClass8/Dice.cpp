#include "Dice.h"
#include <cstdlib>
#include <ctime>



Dice::Dice(int s){
    srand(time(NULL));
    sides = s;
    value = rand() % sides + 1;
}


int Dice::roll()
{
    value = rand() % sides + 1;
    return value;
}



bool Dice::setValue( int val )
{
    if ( val > 0 && val <= sides )
    {
        value = val;
        return true;
    }
    return false;
}





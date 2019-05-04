#ifndef DICE_H
#define DICE_H


class Dice
{
private:
    int sides;
    int value;

public:
    Dice(int s);
    int getSides()
    {
        return sides;
    }
    int getValue()
    {
        return value;
    }
    int roll();
    bool setValue( int val );
};








#endif // DICE_H

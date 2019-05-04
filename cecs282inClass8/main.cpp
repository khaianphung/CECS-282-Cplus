#include <iostream>
#include "Dice.cpp"
#include "Player.cpp"
using namespace std;

int main()
{
    //construct two dice
    Dice dice1(6);
    Dice dice2(6);
    Dice dice3(6);
    Player p("Pepe",0);
    bool play = true;
    while (play)
    {
//roll the dice
        dice1.roll();
        dice2.roll();
        dice3.roll();
//print and find out which player’s was higher
        cout << "Die1=" << dice1.getValue() << endl;
        cout << "Die2=" << dice2.getValue() << endl;
        cout << "Die3=" << dice3.getValue() << endl;
        if( dice1.getValue() == dice2.getValue()
                && dice2.getValue() == dice3.getValue())
        {
            cout<<"You got 3 of a kind"<<endl;
            cout<<"Score ="<<endl;
            p.addPoint(3);
        }
        if( dice1.getValue() == dice2.getValue()
                || dice2.getValue() == dice3.getValue()
                || dice1.getValue() == dice3.getValue())
        {
            cout<<"You got 2 of a kind"<<endl;
            cout<<"Score ="<<endl;
            p.addPoint(1);
        }
        if (dice1.getValue() == dice2.getValue()+1
                ||dice1.getValue() == dice3.getValue()+1
                ||dice2.getValue() == dice1.getValue()+1
                ||dice2.getValue() == dice3.getValue()+1
                ||dice3.getValue() == dice1.getValue()+1
                ||dice3.getValue() == dice2.getValue()+1)
        {
            cout<<"You got a series of 3"<<endl;
            cout<<"Score ="<<endl;
            p.addPoint(2);
        }
        cout<<"Play Again? (Y/N)"<<endl;
        string answer;
        cin>>answer;
        if(answer !="y" && answer !="Y")
        {
            play = false;
        }

    }

    cout<<"Final Score= "<<p.getScore()<<endl;
    return 0;
}

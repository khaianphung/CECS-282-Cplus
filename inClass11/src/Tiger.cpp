#include "Tiger.h"
#include <iostream>



using namespace std;

//constructor
    Tiger::Tiger(string n, int h):Cat(n,h)
{
    name =n ;
    hunger= h;
}

/* play with the feline
@return the damage
*/
int Tiger::play()
{
    if (hunger == 3)
    {
        cout<<"Hunger =3, Tiger attacks, -3hp"<<endl;
        return 3;

    }
    else if (hunger == 2)
    {
        cout<<"Hunger =2, Tiger attacks, -2hp"<<endl;
        hunger++;
        return 2;
    }
    else if (hunger == 1)
    {
        cout<<"Hunger =1, Tiger plays with you"<<endl;
        hunger++;
        return 0;
    }
}

/* feed with the feline
@return the damage
*/
int Tiger::feed()
{
    if(hunger==1)
    {
        cout<<"Tiger is full. It was bothered, so it attack you"<<endl;
        return 1;

    }
    else
    {
        cout<<"Tiger chill down"<<endl;
        hunger--;
        return 0;
    }
}

/* pet with the feline
@return the damage
*/
int Tiger::pet()
{
    if(hunger!=1)
    {
        cout<<"Tiger is hungry, it attacks you"<<endl;
        return 1;

    }
    if(hunger==1)
    {
        cout<<"Tiger purrrrrrr and fell asleep"<<endl;
        return 0;

    }
}


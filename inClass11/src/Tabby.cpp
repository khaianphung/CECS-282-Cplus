#include "Tabby.h"
#include <iostream>



using namespace std;

//constructor
Tabby::Tabby(string n, int h):Cat(n,h)
{
    name =n ;
    hunger= h;
}

/* play with the feline
@return the damage
*/
int Tabby::play()
{
    if (hunger == 3)
    {
        cout<<"Hunger =3, Tabby attacks, -3hp"<<endl;
        return 3;

    }
    else if (hunger == 2)
    {
        cout<<"Hunger =2, Tabby attacks, -2hp"<<endl;
        hunger++;
        return 2;
    }
    else if (hunger == 1)
    {
        cout<<"Hunger =1, Tabby plays with you"<<endl;
        hunger++;
        return 0;
    }
}

/* feed with the feline
@return the damage
*/
int Tabby::feed()
{
    if(hunger==1)
    {
        cout<<"Tabby is full. It was bothered, so it attack you"<<endl;
        return 1;

    }
    else
    {
        cout<<"Tabby chill down"<<endl;
        hunger--;
        return 0;
    }
}

/* pet with the feline
@return the damage
*/
int Tabby::pet()
{
    if(hunger!=1)
    {
        cout<<"Tabby is hungry, it attacks you"<<endl;
        return 1;

    }
    if(hunger==1)
    {
        cout<<"Tabby purrrrrrr and fell asleep"<<endl;
        return 0;

    }
}




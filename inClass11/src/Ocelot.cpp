#include "Ocelot.h"
#include <iostream>



using namespace std;

//constructor
Ocelot::Ocelot(string n, int h):Cat(n,h)
{
    name =n ;
    hunger= h;
}
/* play with the feline
@return the damage
*/
int Ocelot::play()
{
    if (hunger == 3)
    {
        cout<<"Hunger =3, Ocelot attacks, -3hp"<<endl;
        return 3;

    }
    else if (hunger == 2)
    {
        cout<<"Hunger =2, Ocelot attacks, -2hp"<<endl;
        hunger++;
        return 2;
    }
    else if (hunger == 1)
    {
        cout<<"Hunger =1, Ocelot plats with you"<<endl;
        hunger++;
        return 0;
    }
}
/* feed the feline
@return the damage
*/
int Ocelot::feed()
{
    if(hunger==1)
    {
        cout<<"Ocelot is full. It was bothered, so it attack you"<<endl;
        return 1;

    }
    else
    {
        cout<<"Ocelot chill down"<<endl;
        hunger--;
        return 0;
    }
}



/* pet with the feline
@return the damage
*/
int Ocelot::pet()
{
    if(hunger!=1)
    {
        cout<<"Ocelot is hungry, it attacks you"<<endl;
        return 1;

    }
    if(hunger==1)
    {
        cout<<"Ocelot purrrrrrr and fell asleep"<<endl;
        return 0;

    }
}




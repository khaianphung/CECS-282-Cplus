#ifndef OCELOT_H
#define OCELOT_H
#include "Cat.h"
class Ocelot: public Cat
{
public:
    Ocelot();
    Ocelot(string n, int h);
    /* play,feed , pet with the feline
    @return the damage
    */
    int play();
    int feed();
    int pet();

};


#endif // TIGER_H_INCLUDED

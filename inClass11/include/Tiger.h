#ifndef TIGER_H_INCLUDED
#define TIGER_H_INCLUDED
#include "Cat.h"
class Tiger: public Cat
{
public:
    Tiger();
    Tiger(string n, int h);
    /* play,feed , pet with the feline
    @return the damage
    */
    int play();
    int feed();
    int  pet();

};


#endif // TIGER_H_INCLUDED

#ifndef TABBY_H
#define TABBY_H
#include "Cat.h"
class Tabby: public Cat
{
public:
    Tabby();
    Tabby(string n, int h);
    /* play,feed , pet with the feline
    @return the damage
    */
    int play();
    int feed();
    int pet();

};


#endif // TIGER_H_INCLUDED

#include "Player.h"

#include <cstdlib>
#include <ctime>



Player::Player(string n, int s)
{
    setName(n);
    setScore(s);

}

void addPoint(int p){
    score += p;
}



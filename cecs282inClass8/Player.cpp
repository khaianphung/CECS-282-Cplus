#include "Player.h"

#include <cstdlib>
#include <ctime>



Player::Player(string n, int s)
{
    setName(n);
    setScore(s);

}

void Player::setName(string n)
{
    name = n;
}

void Player::setScore(int s)
{
    score = s;
}
void Player::addPoint(int p)
{
    score += p;
}



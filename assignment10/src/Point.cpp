#include <iostream>
#include "Point.h"

Point::Point()
{
    setX(0);
    setY(0);
}



Point::Point(int x,int y )//conatructor of class Point
{
 setX(x);
 setY(y);
}

void Point::setX(int x) //function update  X
{
    if(x<0)
    {
        std::cout << "Invalid value for x, Setting to default\n";
        this->x=0;
    }
    else
        this->x=x;
}

void Point::setY(int y)//function update Y
{
    if(y<0)
    {
        std::cout << "Invalid value for y, Setting to default\n";
        this->y=0;
    }
    else
        this->y=y;
}

int Point::getX() const //function return X
{
    return x;
}

int Point::getY() const //function return Y
{
    return y;
}

void Point::print() const //function print the value of X and Y
{
        std::cout <<"X:"<< this->x <<"  "<<"Y:" << this->y ;
}


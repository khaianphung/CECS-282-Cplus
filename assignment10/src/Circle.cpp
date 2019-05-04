#include "Circle.h"
#include "Point.h"
#include <iostream>

#define M_PI 3.14159265358979323846

Circle::Circle(const Point &l1,int radius)
{
    r=radius;
    p=l1;
}

double Circle::getArea()const
{
    return r*r*M_PI;
}

double Circle::getPerim ()const
{
    return 2*M_PI*r;
}

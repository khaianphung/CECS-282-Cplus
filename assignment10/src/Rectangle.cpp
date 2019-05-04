#include <iostream>
#include "Rectangle.h"




Rectangle::Rectangle(const Point &l, const Point &r)
{
    topLeft=l;
    buttomRight=r;

    Point tempP=topLeft;
    tempP.setY(topLeft.getY());
    tempP.setX(buttomRight.getX());
    length=getDist(topLeft,tempP);
    width=getDist(tempP,buttomRight);

}


double Rectangle::getArea()const
{

    return length*width;
}

double Rectangle::getPerim()const
{
    return (length+width)*2;
}

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle: public Shape
{
protected:


public:

    Rectangle(Point &aa, Point &bb);


    //caculate the area
    double calcArea();
    //caculate the perimeter
    double calcPerimeter();
    //overloaded cout<<
    //param1 ostream for cout
    //Fraction to cout
    //return the stream
    friend ostream &operator<<(ostream &out, Rectangle &p);
};
#endif

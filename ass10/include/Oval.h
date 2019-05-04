#ifndef OVAL_H
#define OVAL_H
#include <iostream>
#include "Point.h"
#include "Shape.h"
using namespace std;

class Oval: public Shape
{
protected:

public:

    Oval(Point &aa, Point &bb);


    //calculate the area
    double calcArea();
    //calculate the perimeter
    double calcPerimeter();
    //overloaded cout<<
    //Oval ostream for cout
    //Oval to cout
    //return the stream
    friend ostream &operator<<(ostream &out, Oval &p);
};
#endif

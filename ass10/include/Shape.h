#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "Point.h"
using namespace std;

class Shape
{
protected:
    Point a,  b;



public:

    Shape(Point &aa, Point &bb);
    //getters
    Point getPointA()
    {
        return a;
    }
    Point getPointB()
    {
        return b;
    }
    //setter
    void setPointA(Point &aa);
    void setPointB(Point &bb);
    //getters of width end height
    double getWidth()
    {
        return b.getX()-a.getX();
    }
    double getHeight()
    {
        return b.getY()-a.getY();
    }

    /*change size  the shape
    @param1 the horizontal change
    @param2 the verticle change
    */
    void scale(int horizontal, int vertical);
    /*move the shape
    @param1 the horizontal change
    @param2 the verticle change
    */
    void translate(int horizontal, int vertical);
    //pure virtual functions
    virtual double calcArea() = 0;
    virtual double calcPerimeter() = 0;


};
#endif

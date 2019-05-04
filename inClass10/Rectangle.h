#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

using namespace std;

class Rectangle
{
protected:
    int w, h;
public:
    Rectangle(int width, int height);
    int getWidth(){return w;}
    int getHeight(){return h;}
    double calcArea();
    double calcPerimeter();
    friend ostream &operator<<(ostream &out,Rectangle p);
    friend istream &operator>>(istream &in,Rectangle &p);
};

#endif // RECTANGLE_H

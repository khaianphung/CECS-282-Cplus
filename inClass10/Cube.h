#ifndef CUBE_H
#define CUBE_H

#include "Rectangle.h"


class Cube: public Rectangle {
protected: int d;
public:
    Cube(int width, int height, int depth);
    int getDepth(){return d;}
    double calcVol();
    double calcArea();
    double calcPerimeter();
    friend ostream &operator<<(ostream &out,Cube p);
    friend istream &operator>>(istream &in,Cube &p);
};


#endif // CUBE_H_INCLUDED

#ifndef Polygon_h
#define Polygon_h
#include "Shape.h"

class Polygon :public Shape
{
public:
    double getDist(const Point &p1,const Point &p2);
    //double getPerim() const{std::cout<<"  ";return 0 ;}   no need
    //double getArea() const {std::cout<<"   ";return 0 ;}
};

#endif

#ifndef Rectangle_h
#define Rectangle_h
#include "Point.h"
#include "Polygon.h"

class Rectangle:public Polygon
{
    public:

    Rectangle(const Point &l, const Point &r) ;
    double getArea()const;
    double getPerim()const;

    private:
        Point topLeft;
        Point buttomRight;
        int length ,width;
};

#endif

#ifndef Circle_h
#define Circle_h
#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
public:

    Circle(const Point &l1,int radius);
    double getArea()const;
    double getPerim()const;


private:
    int r;
    Point p;
};



#endif

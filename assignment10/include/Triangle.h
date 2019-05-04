#ifndef Triangle_h
#define Triangle_h
#include "Point.h"
#include "Polygon.h"

class Triangle : public Polygon
{
public:

Triangle(const Point &p1, const Point &p2,const Point &p3);

    double getArea()const;
    double getPerim()const;

private:
    Point p1;
    Point p2;
    Point p3;
    double edgeA,edgeB,edgeC;

};

#endif

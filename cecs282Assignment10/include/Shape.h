#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include "Point.h"
using namespace std;

class Shape {
protected: Point a,  b;
double w=b.getX()-a.getX();
double h=b.getY()-a.getY();


public:

	Shape(Point &a, Point &b);
	Point getPointA() { return a; }
	Point getPointB() { return b; }
	void setPointA(Point a);
	void setPointB(Point b);
	double getWidth(){return w;}
	double getHeight(){return h;}


	void scale();
	void translate();
	virtual double calcArea() = 0;
	virtual double calcPerimeter() = 0;

};
#endif

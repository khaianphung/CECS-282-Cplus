#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Triangle: public Shape {
protected: Point a, b;
public:
    double w,h;

	Triangle(Point a, Point b);



	double calcArea();
	double calcPerimeter();
	//overloaded cout<<
	//param1 ostream for cout
	//Fraction to cout
	//return the stream
	friend ostream &operator<<(ostream &out, Triangle p);
};
#endif

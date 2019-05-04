#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Triangle: public Shape {
protected:
public:
    double w,h;

	Triangle(Point &aa, Point &bb);



	double calcArea();
	double calcPerimeter();
	//overloaded cout<<
	//param1 ostream for cout
	//Fraction to cout
	//return the stream
	friend ostream &operator<<(ostream &out, Triangle &p);
};
#endif

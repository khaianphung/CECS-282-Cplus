#ifndef OVAL_H
#define OVAL_H
#include <iostream>
#include "Point.h"
#include "Shape.h"
using namespace std;

class Oval: public Shape {
protected:
    Point a, b;
public:

	Oval(Point &a, Point &b);



	double calcArea();
	double calcPerimeter();
	//overloaded cout<<
	//param1 ostream for cout
	//Fraction to cout
	//return the stream
	friend ostream &operator<<(ostream &out, Oval p);
};
#endif

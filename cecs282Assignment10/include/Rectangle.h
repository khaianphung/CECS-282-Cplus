#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle: public Shape {
protected: Point a, b ;

public:

	Rectangle(Point a, Point b);



	 double calcArea();
	 double calcPerimeter();
	 //overloaded cout<<
	 //param1 ostream for cout
	 //Fraction to cout
	 //return the stream
	 friend ostream &operator<<(ostream &out, Rectangle p);
};
#endif

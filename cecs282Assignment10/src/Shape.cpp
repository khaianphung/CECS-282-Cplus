//Point a, Point b
#include "Shape.h"

#include<math.h>
Shape::Shape(Point &aa, Point &bb) {
	a = aa;
	b = bb;
}

void Shape::scale(int x, int y) {
	this->b.x += x;
	this->b.y += y;
}

void Shape::translate(int x, int y) {
	this->a.x += x;
	this->a.y += y;

	this->b.x += a.x;
	this->b.y += a.y;
}

void Shape::setPointA(Point a) {
	this->a = a;
}

void Shape::setPointB(Point b) {
	this->b =b ;
}



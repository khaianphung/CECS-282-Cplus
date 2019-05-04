//Point a, Point b
#include "Rectangle.h"
#include<math.h>

Rectangle::Rectangle(Point a, Point b) {
	this->a = a;
	this->b = b;
}

double Rectangle::calcPerimeter(){
    return (w+h)*2;
}
double Rectangle::calcArea(){
    return (w*h);
}

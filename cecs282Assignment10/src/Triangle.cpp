//Point a, Point b
#include "Triangle.h"
#include <stdio.h>
#include <math.h>

Triangle::Triangle(Point a, Point b) {
	this->a = a;
	this->b = b;
}

double Triangle::calcPerimeter(){
    return (w+h)+sqrt(pow(w,2)+pow(h,2));
}
double Triangle::calcArea(){
    return (w*h)/2;
}


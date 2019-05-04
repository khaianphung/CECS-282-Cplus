//Point a, Point b
#include "Triangle.h"
#include <stdio.h>
#include <math.h>

Triangle::Triangle(Point &aa, Point &bb):Shape(aa,bb) {

}
/*calculate the perimeter
@return the result
*/
double Triangle::calcPerimeter(){
    double w = this->getWidth();
     double h = this->getHeight();
    return (w+h)+sqrt(pow(w,2)+pow(h,2));
}
/*calculate the area
@return the result
*/
double Triangle::calcArea(){
    double w = this->getWidth();
     double h = this->getHeight();
    return (w*h)/2;
}


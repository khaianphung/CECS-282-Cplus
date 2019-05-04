//Point a, Point b
#include "Oval.h"
#include "Point.h"
#include "Shape.h"
#include<math.h>
const double PI  =3.141592653589793238463;

Oval::Oval(Point &aa, Point &bb):Shape(aa,bb) {

}

double Oval::calcPerimeter(){
    return 2*PI*sqrt((pow(w,2)+pow(h,2))/2);
}
double Oval::calcArea(){
    return PI*w/2*h/2;
}



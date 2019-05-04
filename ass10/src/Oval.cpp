//Point a, Point b
#include "Oval.h"

#include<math.h>
const double PI  =3.141592653589793238463;

Oval::Oval(Point &aa, Point &bb):Shape(aa,bb) {

}
/*calculate the perimeter
@return the result
*/
double Oval::calcPerimeter(){
    double w = this->getWidth();
     double h = this->getHeight();
    return 2*PI*sqrt((pow(w,2)+pow(h,2))/2);
}
/*calculate the area
@return the result
*/
double Oval::calcArea(){
    double w = this->getWidth();
     double h = this->getHeight();
    return PI*w/2*h/2;
}



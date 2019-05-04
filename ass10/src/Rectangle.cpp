//Point a, Point b

#include "Rectangle.h"
#include<math.h>

Rectangle::Rectangle(Point &aa, Point &bb):Shape(aa,bb) {

}
/*calculate the perimeter
@return the result
*/
double Rectangle::calcPerimeter(){
    return (this->getWidth()+this->getHeight())*2;
}
/*calculate the area
@return the result
*/
double Rectangle::calcArea(){
    return (this->getWidth()*this->getHeight());
}

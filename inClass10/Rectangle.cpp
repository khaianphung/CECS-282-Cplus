#include "Rectangle.h"
Rectangle::Rectangle(int width, int height){
    w= width;
    h = height;
}
double Rectangle::calcArea(){
    return w*h;
}
double Rectangle::calcPerimeter(){
    return (w+h)*2;
}

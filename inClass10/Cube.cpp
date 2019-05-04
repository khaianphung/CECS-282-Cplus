#include "Cube.h"


Cube::Cube(int width, int height, int depth): Rectangle(width,height){
    d = depth;
    }
double Cube::calcVol(){
return w*h*d;
}
double Cube::calcArea(){
return w*h*2+w*d*4;
}
double Cube::calcPerimeter(){
    return (w+h)*4+4*d;
}








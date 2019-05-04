#include <cmath>
#include "Triangle.h"
#include <iostream>




Triangle::Triangle(const Point &x, const Point &y,const Point &z)
{
    p1=x;
    p2=y;
    p3=z;
    edgeA=getDist(p1,p2);  //חישוב אורך צלע 1
    edgeB=getDist(p2,p3);    //חישוב אורך צלע 2
    edgeC=getDist(p1,p3);  //חישוב אורך צלע 3

}


double Triangle::getArea()const
{
    double area,temp;
    temp= (edgeA+edgeB+edgeC)*(edgeA+edgeB-edgeC)*(edgeA-edgeB+edgeC)*(-edgeA+edgeB+edgeC); //חישוב שטח משולש ע"פ הנוסחה של נודלמן
    area = sqrt(temp);                      //חישוב שטח משולש ע"פ הנוסחה של נודלמן
    area=area*0.25;
    return area ;
}

double Triangle::getPerim ()const
{
    return edgeA+edgeB+edgeC;
}

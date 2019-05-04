    #ifndef Shape_h
#define Shape_h
#include "Point.h"
#include <iostream>


class Shape
{

  public:
    virtual double getArea()const=0;
    virtual double getPerim() const=0;
    virtual  ~Shape(){};
};

#endif

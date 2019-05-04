
#include "Point.h"

//constructor
Point::Point( int x, int y )

{
    (*this).x = x; //this -> x also works
    (*this).y = y;
}
//print the point x and y
void Point::printPoint()
{
    cout<< "(" << x << ", " << y << ")" << endl;
}

/*add a point to another point
@param1 the adding point
@return the new point
*/
Point Point::add( Point p )
{
    int xVal = 0, yVal = 0;
    xVal = (*this).x + p.x;
    yVal = (*this).y + p.y;
    Point result( xVal, yVal );
    return result;
}






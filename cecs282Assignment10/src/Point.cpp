
#include "Point.h"
#include<math.h>
//constructor
Point::Point(int x, int y)

{
	(*this).x = x; //this -> x also works
	(*this).y = y;
}
//print the point x and y
void Point::printPoint()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

/*add a point to another point
@param1 the adding point
@return the new point
*/
Point Point::add(Point p)
{
	int xVal = 0, yVal = 0;
	xVal = (*this).x + p.x;
	yVal = (*this).y + p.y;
	Point result(xVal, yVal);
	return result;
}
//overlodade *
//@param1: the multiplying number
//@return the new point
Point Point::operator* (double b)
{
	Point r(this->x*b, this->y*b);
	return r;
}


/*overloaded ++
increase x and y of a point by 1
@return the new point after increment
*/
Point Point::operator++ ()
{

	Point r(this->x + 1, this->y + 1);
	return r;
}
/*overloaded <
check if a point is less than another point
@return boolean value indicate less than
*/
bool Point::operator< (Point b)
{
	if (this->x < b.x)
	{
		return true;
	}
	return false;
}
/*overloaded >
check if a point is more than another point
@return boolean value indicate more than
*/
bool Point::operator> (Point b)
{
	if (this->x > b.x)
	{
		return true;
	}
	return false;
}

/*overloaded ==
check if a point is equal to  another point
@return boolean value indicate equal
*/
bool Point::operator== (Point b)
{
	if (this->x == b.x)
	{
		return true;
	}
	return false;
}





#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
protected:
	int x, y;
public:
	//constructor

	Point(int x, int y);
	/*
	adjust the id
	@param1 the adjusted amount
	*/


	/*get the balance
	@return the account balance
	*/
	int getX()
	{
		return x;
	}
	/*get the id
	@return the account number
	*/
	int getY()
	{
		return y;
	}
	/*deposit money to the account
	@param1 the amount of money deposit
	*/
	void printPoint();
	//add a point to another point
	//@param1: adding point
	//@return the summation point
	Point add(Point p);

	//overloaded *
	Point operator* (double b);

	//overloaded +
	Point operator+ (Point b);
	//overloaded ++
	Point operator++ ();
	//overloaded <
	bool operator< (Point b);
	//overloaded >
	bool operator> (Point b);

	bool operator== (Point b);
	//overloaded cin cout << >>
	friend ostream &operator<<(ostream &out, Point p);
	friend istream &operator>>(istream &in, Point &p);


};
#endif // POINT_H_INCLUDED

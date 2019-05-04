
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Oval.h"
#include "Triangle.h"



#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
/*
validate the valid entry
@param1 lower bound
@param2 uper bound
@result the valid integer
*/
int validate(int start, int endi)
{
    int input = 0;
    bool fail = true;

    while (fail)
    {

        //cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input <= endi && input >= start)
            {
                fail = false;
            }
            else
            {
                cout << "Invalid input: " << endl;
            }
        }
        else
        {
            cin.clear();//clear the wrong input
            string invalid;
            cin >> invalid;
            cout << "Invalid Input" << endl;
        }
    }
    return input;
}//validate
//print out the menu
void shapeMenu()
{
    cout << "1.Shape 1" << endl;
    cout << "2.Shape 2" << endl;
    cout << "3.Shape 3" << endl;
    cout << "4.Quit" << endl;

}

//print out the menu
void functionMenu()
{
    cout << "1.Scale" << endl;
    cout << "2.Translate" << endl;
    cout << "3.Calculate Area" << endl;
    cout << "4.Calculate Perimeter" << endl;
    cout << "5.Display Shape" << endl;
    cout << "6.Back to Shape Menu" << endl;

}
//overloaded << and >>
    ostream &operator<<(ostream &out, Rectangle &p)
    {
        //“P = (x,y), W=w, H=h”, where P = point1, w = width, h = height.
        //cout << "P=("p.getPointA().getX()<<","<<p.getPointA().getY()<<"), W="<<p.getWidth()<<"H="<<p.getHeight()<<endl;
        cout << "), W="<<p.getWidth()<<"H="<<p.getHeight()<<endl;
        return out;
    }

    ostream &operator<<(ostream &out, Oval &p)
    {
        //P = (x,y), W=w, H=h”, where P = point1, w = width, h = height.
        //cout << "P=("p.a.x<<","<<p.a.y<<"), W="<<p.w<<"H="<<p.h<<endl;
         cout << "), W="<<p.getWidth()<<"H="<<p.getHeight()<<endl;
        return out;
    }

    ostream &operator<<(ostream &out, Triangle &p)
    {
        //“P = (x,y), W=w, H=h”, where P = point1, w = width, h = height.
        //cout << "P=("p.a.x<<","<<p.a.y<<"), W="<<p.w<<"H="<<p.h<<endl;
        cout << "), W="<<p.getWidth()<<"H="<<p.getHeight()<<endl;
        return out;
    }


    /*
    istream &operator>>(istream &in, Point &p)
    {
    	cout << "Enter x and y values:" << endl;
    	p.x = validate(-99999, 99999);
    	p.y = validate(-99999, 99999);
    	return in;
    }
    */
    int main()
    {
        Point p1(0, 0);
        Point p2(3, 4);

        //cout << "Point 1:" << endl;

        bool play = true;
        while (play)
        {
            p1.printPoint();
            shapeMenu();
            int choice = validate(1, 8);
            switch (choice)
            {
            case 1:
            {
                bool play2 = true;
                while (play2)
                {
                    functionMenu();
                    int choice2 = validate(1,6);
                    if(choice2 ==1)
                    {

                    }
                    if(choice2 ==2)
                    {

                    }
                    if(choice2 ==3)
                    {

                    }
                    if(choice2 ==4)
                    {

                    }
                    if(choice2 ==5)
                    {

                    }
                    if(choice2 ==6)
                    {
                        play2 =false;
                    }
                }
                break;
            }
            case 2:
            {
                bool play2 = true;
                while (play2)
                {
                    functionMenu();
                    int choice2 = validate(1,6);
                    if(choice2 ==1)
                    {

                    }
                    if(choice2 ==2)
                    {

                    }
                    if(choice2 ==3)
                    {

                    }
                    if(choice2 ==4)
                    {

                    }
                    if(choice2 ==5)
                    {

                    }
                    if(choice2 ==6)
                    {
                        play2 =false;
                    }
                }
                break;
            }
            case 3:
            {
                bool play2 = true;
                while (play2)
                {
                    functionMenu();
                    int choice2 = validate(1,6);
                    if(choice2 ==1)
                    {

                    }
                    if(choice2 ==2)
                    {

                    }
                    if(choice2 ==3)
                    {

                    }
                    if(choice2 ==4)
                    {

                    }
                    if(choice2 ==5)
                    {

                    }
                    if(choice2 ==6)
                    {
                        play2 =false;
                    }
                }
                break;
            }



            case 4:
                {
                play = false;
                break;
            }
            }
        }

        return 0;
    }

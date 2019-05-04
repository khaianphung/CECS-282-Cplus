
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
void shapeChoiceMenu()
{
    cout<<"Which shape do you want?"<<endl;
    cout << "1.Rectangle" << endl;
    cout << "2.Triangle" << endl;
    cout << "3.Oval" << endl;

}

//print out the function menu
void functionMenu()
{
    cout << "1.Scale" << endl;
    cout << "2.Translate" << endl;
    cout << "3.Calculate Area" << endl;
    cout << "4.Calculate Perimeter" << endl;
    cout << "5.Display Shape" << endl;
    cout << "6.Back to Shape Menu" << endl;

}
/*overloaded <<
@param1 the out stream
@param2 the rectangle object reference
@return the outstream
*/
ostream &operator<<(ostream &out,  Rectangle &p)
{

    int x = p.getPointA().getX();
    int y = p.getPointA().getY();
    double w = p.getWidth();
    double h = p.getHeight();
    cout << "<Rectangle>P=("<<x<<","<<y<<"), W="<<w<<"H="<<h<<endl;

    return out;
}
/*overloaded <<
@param1 the out stream
@param2 the rectangle object reference
@return the outstream
*/
ostream &operator<<(ostream &out, Oval &p)
{
    int x = p.getPointA().getX();
    int y = p.getPointA().getY();
    double w = p.getWidth();
    double h = p.getHeight();

    cout << "<Oval>P=("<<x<<","<<y<<"), W="<<w<<"H="<<h<<endl;

    return out;
}
/*overloaded <<
@param1 the out stream
@param2 the rectangle object reference
@return the outstream
*/
ostream &operator<<(ostream &out, Triangle &p)
{
    int x = p.getPointA().getX();
    int y = p.getPointA().getY();
    double w = p.getWidth();
    double h = p.getHeight();
    cout << "<Triangle>P=("<<x<<","<<y<<"), W="<<w<<"H="<<h<<endl;
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


    //cout << "Point 1:" << endl;
    int SIZE = 3;

    Shape *arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Enter Shape "<<i+1<<endl;
        cout<<"Point 1"<<endl;
        cout<<"Enter x: "<<endl;
        int x = validate(-999,999);
        cout<<"Enter y: "<<endl;
        int y = validate(-999,999);
        Point p1(x, y);
        cout<<"Point 2"<<endl;
        cout<<"Enter x: "<<endl;
        x = validate(-999,999);
        cout<<"Enter y: "<<endl;
        y = validate(-999,999);
        Point p2(x, y);
        shapeChoiceMenu();
        int choice3 = validate(1,3);


        if( choice3 == 1)
        {
            arr[i] = new Rectangle(p1,p2);

        }

        else if( choice3 == 2)
        {
            arr[i] = new Triangle(p1,p2);

        }
        else if(choice3 == 3)
        {
            arr[i] = new Oval(p1,p2);

        }
    }
    bool play = true;
    while (play)
    {

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
                    cout<<"Enter w scale: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h scale: "<<endl;
                    double b=validate(0,100);
                    arr[0]->scale(a,b);

                }
                if(choice2 ==2)
                {
                    cout<<"Enter w translate: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h translate: "<<endl;
                    double b=validate(0,100);
                    arr[0]->translate(a,b);
                }
                if(choice2 ==3)
                {
                    cout<<"AREA = "<<arr[0]->calcArea()<<endl;
                }
                if(choice2 ==4)
                {
                    cout<<"PERIMETER = "<<arr[0]->calcPerimeter()<<endl;

                }
                if(choice2 ==5)
                {
                    if(dynamic_cast<Rectangle*>(arr[0]))
                    {
                        Rectangle *r = (Rectangle*) arr[0];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Oval*>(arr[0]))
                    {
                        Oval *r = (Oval*) arr[0];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Triangle*>(arr[0]))
                    {
                        Triangle *r = (Triangle*) arr[0];

                        cout<<*r<<endl;
                    }




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
                    cout<<"Enter w scale: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h scale: "<<endl;
                    double b=validate(0,100);
                    arr[1]->scale(a,b);
                }
                if(choice2 ==2)
                {
                    cout<<"Enter w translate: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h translate: "<<endl;
                    double b=validate(0,100);
                    arr[1]->translate(a,b);
                }
                if(choice2 ==3)
                {
                    cout<<"AREA = "<<arr[1]->calcArea()<<endl;
                }
                if(choice2 ==4)
                {
                    cout<<"PERIMETER = "<<arr[1]->calcPerimeter()<<endl;

                }
                if(choice2 ==5)
                {
                    if(dynamic_cast<Rectangle*>(arr[1]))
                    {
                        Rectangle *r = (Rectangle*) arr[1];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Oval*>(arr[1]))
                    {
                        Oval *r = (Oval*) arr[1];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Triangle*>(arr[1]))
                    {
                        Triangle *r = (Triangle*) arr[1];

                        cout<<*r<<endl;
                    }
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
                    cout<<"Enter w scale: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h scale: "<<endl;
                    double b=validate(0,100);
                    arr[2]->scale(a,b);
                }
                if(choice2 ==2)
                {
                    cout<<"Enter w translate: "<<endl;
                    double a=validate(0,100);
                    cout<<"Enter h translate: "<<endl;
                    double b=validate(0,100);
                    arr[2]->translate(a,b);
                }
                if(choice2 ==3)
                {
                    cout<<"AREA = "<<arr[2]->calcArea()<<endl;
                }
                if(choice2 ==4)
                {
                    cout<<"PERIMETER = "<<arr[2]->calcPerimeter()<<endl;

                }
                if(choice2 ==5)
                {
                    if(dynamic_cast<Rectangle*>(arr[2]))
                    {
                        Rectangle *r = (Rectangle*) arr[2];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Oval*>(arr[2]))
                    {
                        Oval *r = (Oval*) arr[2];

                        cout<<*r<<endl;
                    }
                    if(dynamic_cast<Triangle*>(arr[2]))
                    {
                        Triangle *r = (Triangle*) arr[2];

                        cout<<*r<<endl;
                    }
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



/*
    cout<<"x pos = "<<r.getPointA().getX()<<endl;
    cout<<"y pos = "<<r.getPointA().getY()<<endl;
    r.translate(2,2);
    cout<<"x pos = "<<r.getPointA().getX()<<endl;
    cout<<"y pos = "<<r.getPointA().getY()<<endl;

    cout<<"Weight= "<<r.getWidth()<<endl;
    cout<<"Height= "<<r.getHeight()<<endl;
    cout<<"AREA= "<<r.calcArea()<<endl;
    cout<<"PERIMETER= "<<r.calcPerimeter()<<endl;
    r.scale(3,3);
    cout<<"Weight= "<<r.getWidth()<<endl;
    cout<<"Height= "<<r.getHeight()<<endl;
    return 0;
}
*/

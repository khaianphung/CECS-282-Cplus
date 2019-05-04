#include "Point.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    bool fail= true;

    while (fail)
    {

        //cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input<= endi && input>=start )
            {
                fail = false;
            }
            else
            {
                cout<<"Invalid input: "<<endl;
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
void menu()
{
    cout<<"1.Add"<<endl;
    cout<<"2.Multiply"<<endl;
    cout<<"3.Increment"<<endl;
    cout<<"4.Equal To"<<endl;
    cout<<"5.Less Than"<<endl;
    cout<<"6.Enter a new Point"<<endl;
    cout<<"7.Display Point"<<endl;
    cout<<"8.Quit"<<endl;
}

//overloaded << and >>
ostream &operator<<(ostream &out, Point p)
{
    cout << "(" << p.x << ","<< p.y << ")";
    return out;
}
istream &operator>>(istream &in, Point &p)
{
    cout<< "Enter x and y values:"<<endl;
    p.x=validate(-99999,99999);
    p.y=validate(-99999,99999);
    return in;
}

int main()
{
    Point p1(0,0);
    Point p2(0,0);

    cout<<"Point 1:"<<endl;

    bool play = true;
    while (play)
    {
        p1.printPoint();
        menu();
        int choice = validate(1,8);
        switch (choice)
        {
        case 1:
        {
            cout<<"Adding"<<endl;
            cout<<"Enter point: "<<endl;



            cin>> p2;

            p1= p1.add(p2);
            //p3.printPoint();
            break;
        }
        case 2:
        {
            cout<<"Multiplying"<<endl;
            cout<<"Enter point: "<<endl;

            int mul;
            cin>>mul;
            p1 = p1*mul;

            break;
        }
        case 3:
        {
            cout<<"Increment"<<endl;

            p1= ++p1;

            break;
        }


        case 4:
        {
            cout<<"Equal to"<<endl;
            cout<<"Enter point: "<<endl;
            cin>>p2;
            if(p1 == p2){
                    cout<<"True"<<endl;
            }else{cout<<"False"<<endl;}
            break;
        }
        case 5:
        {
            cout<<"Less Than"<<endl;
            cout<<"Enter point: "<<endl;
            cin>>p2;
            if(p1 < p2){
                    cout<<"True"<<endl;
            }else{cout<<"False"<<endl;}
            break;
            break;
        }
        case 6:
        {
            cout<<"Enter a new point"<<endl;
            cin>>p1;

            break;
        }
        case 7:
        {
            cout<<p1;
            break;
        }
        case 8:
        {
            play = false;
            break;
        }
        }
    }

    return 0;
}

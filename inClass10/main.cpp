
#include "Rectangle.h"
#include "Cube.h"
#include <iostream>



using namespace std;

/*
validate if the value is valid
@param1 lower bound
@param2 upper bound
@return the valid input
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

//////////for rectangle
ostream &operator<<(ostream &out, Rectangle p)
{
    cout << "Rectangle->Width = "<<p.w<<",Height = "<<p.h<<endl;
    return out;
}
istream &operator>>(istream &in, Rectangle &p)
{

    cout<< "Enter width:"<<endl;
    p.w=validate(0,99999);
    cout<< "Enter height:"<<endl;
    p.h=validate(0,99999);

    return in;
}

///////////////overide for cube
ostream &operator<<(ostream &out, Cube p)
{
    cout << "Cube => Width ="<< p.w<<", Height = "<<p.h<<", Depth = "<<p.d<<endl;
    return out;
}
istream &operator>>(istream &in, Cube &p)
{

    cout<< "Enter width:"<<endl;
    p.w=validate(0,99999);
    cout<< "Enter height:"<<endl;
    p.h=validate(0,99999);
    cout<< "Enter depth:"<<endl;
    p.d=validate(0,99999);

    return in;
}

/*
display the menu
*/
void menu()
{
    cout<<"1.Rectangle Menu"<<endl;
    cout<<"2.Cube Menu"<<endl;

}
/*
display the rectangle menu
*/
void rectangleMenu()
{
    cout<<"1.Display Rectangle"<<endl;
    cout<<"2.Display Area"<<endl;
    cout<<"3.Display Perimeter"<<endl;
    cout<<"4.Back to the Menu"<<endl;

}

/*
display the cube menu
*/
void cubeMenu()
{
    cout<<"1.Display Cube"<<endl;
    cout<<"2.Display Area"<<endl;
    cout<<"3.Display Perimeter"<<endl;
    cout<<"4.Display Volume"<<endl;
    cout<<"5.Back to the Menu"<<endl;

}
int main()
{

    bool play = true;
    while(play)
    {
        menu();
        int choice = validate (1,3);
        if (choice ==1)
        {
            bool play2= true;
            Rectangle r(0,0);
            cin>>r;
            while(play2)
            {

                rectangleMenu();
                int choice2= validate(1,4);
                if(choice2 == 1)
                {
                    cout<<r;
                }
                if(choice2 == 2)
                {
                    cout<<"Area Rectangle = "<< r.calcArea()<<endl;
                }
                if(choice2 == 3)
                {
                    cout<<"Area Perimeter = "<<r.calcPerimeter()<<endl;
                }
                if(choice2 == 4)
                {
                    play2= false;
                }
            }
        }
        if (choice ==2)
        {
            Cube c(0,0,0);
            cin>>c;
            bool play2= true;
            while(play2)
            {

                cubeMenu();
                int choice2= validate(1,5);
                if(choice2 == 1)
                {
                    cout<<c;
                }
                if(choice2 == 2)
                {
                    cout<<"Area Cube = "<<c.calcArea()<<endl;
                }
                if(choice2 == 3)
                {
                    cout<<"Perimeter Cube = "<<c.calcPerimeter()<<endl;
                }
                if(choice2 == 4)
                {
                    cout<<"Volume Cube= "<<c.calcVol()<<endl;
                }
                if(choice2 == 5)
                {
                    play2= false;
                }
            }
        }
        if (choice ==3)
        {
            play =false;
        }
    }
    return 0;
}

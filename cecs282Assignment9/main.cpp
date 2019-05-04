#include "Fraction.h"
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
    cout<<"2.Subtract"<<endl;
    cout<<"3.Multiply"<<endl;
    cout<<"4.Divide"<<endl;
    cout<<"5.Test if Equal"<<endl;
    cout<<"6.Enter a new Fraction"<<endl;
    cout<<"7.Quit"<<endl;
}
/*find the gcd to simplify the fraction ( put here because need to simplify in here too)
@param1 numerator
@param2 denominator
@return the gcd
*/
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
//overloaded << and >>
ostream &operator<<(ostream &out, Fraction p)
{
    cout << "(" << p.num << "/"<< p.den << ")";
    return out;
}
istream &operator>>(istream &in, Fraction &p)
{

    cout<< "Enter numerator:"<<endl;
    p.num=validate(-99999,99999);
    cout<< "Enter denominator:"<<endl;
    p.den=validate(-99999,99999);
    while(p.den==0) {
            cout<<"Don't enter zero"<<endl;
            p.den=validate(-99999,99999);
    }
    int g= gcd(p.num,p.den);
    cout<<"g:"<<g<<endl;
    p.num = p.num/g;
    p.den = p.den/g;
    return in;
}


int main()
{
    Fraction p1(1,1);
    Fraction p2(4,2);



    bool play = true;
    while (play)
    {
        cout<<"Fraction 1:"<<endl;
        p1.printFraction();
        menu();
        int choice = validate(1,8);
        switch (choice)
        {
        case 1:
        {
            cout<<"Adding"<<endl;
            cout<<"Enter fraction: "<<endl;



            cin>> p2;

            cout<<"Sum: "<<p1+p2<<endl;
            //p3.printPoint();
            break;
        }
        case 2:
        {
            cout<<"Subtracting"<<endl;
            cout<<"Enter fraction: "<<endl;


            cin>>p2;
            cout<<"Result: "<<p1-p2<<endl;

            break;
        }
        case 3:
        {
            cout<<"Multiplying"<<endl;
            cout<<"Enter fraction: "<<endl;


            cin>>p2;
            cout<<"Result`: "<<p1*p2<<endl;

            break;

        }


        case 4:
        {
            cout<<"Divide"<<endl;
            cout<<"Enter fraction: "<<endl;
            cin>>p2;
            cout<<"Quotient: "<<p1/p2<<endl;
            break;
        }
        case 5:
        {
            cout<<"Equal To"<<endl;
            cout<<"Enter fraction: "<<endl;
            cin>>p2;
            if(p1 == p2)
            {
                cout<<"True"<<endl;
            }
            else
            {
                cout<<"False"<<endl;
            }
            break;

        }
        case 6:
        {
            cout<<"Enter a new fraction"<<endl;
            cin>>p1;

            break;
        }

        case 7:
        {
            play = false;
            break;
        }
        }
    }

    return 0;
}

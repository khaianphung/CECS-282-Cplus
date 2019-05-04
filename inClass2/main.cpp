/*
Khai Phung
02/03/2017
inClass2
*/
#include <iostream>
#include<iomanip>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    cout << "Enter the date in the format mm/dd/yy: ";
    string date;
    cin >> date;


    int mm = atoi(date.substr(0,2).c_str());
    int year = atoi(date.substr(6,4).c_str());
    if (mm==1 || mm==2)
    {
        mm+=12;
        year--;
    }
    int dd = atoi(date.substr(3,2).c_str());
    int YY = floor(year/100);
    int yy = year - YY*100;


    cout<<"mm"<<mm<<endl;
    cout<<"dd"<<dd<<endl;
    cout<<"yy"<<yy<<endl;
    cout<<"YY"<<YY<<endl;
    double weekDay = (dd + ((mm+1)*26)/10 + yy + yy/4 + YY/4 - 2*YY)%7;
    while(weekDay<0)
    {
        weekDay += 7;
    }
    cout<<weekDay<<endl;

    if(weekDay == 2 )
    {
        cout<<"Monday";
    }
    if(weekDay == 3 )
    {
        cout<<"Tuesday";
    }
    if(weekDay == 4)
    {
        cout<<"Wednesday";
    }
    if(weekDay == 5 )
    {
        cout<<"Thursday";
    }
    if(weekDay == 6 )
    {
        cout<<"Friday";
    }
    if(weekDay == 0 )
    {
        cout<<"Saturday";
    }
    if(weekDay == 1 )
    {
        cout<<"Sunday";
    }

    return 0;
}

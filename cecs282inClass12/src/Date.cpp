#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

//print out the date
void Date::printDate()
{
    cout<<month<<"/"<<day<<"/"<<year;
}


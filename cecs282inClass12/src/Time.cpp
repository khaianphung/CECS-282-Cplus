#include "Time.h"
#include <iostream>
using namespace std;
Time::Time( int h, int m, int s )
{
    hour = h;
    min = m;
    sec = s;
}


//print out the time
void Time::printTime()
{
    cout<<hour<<":"<<min<<":"<<sec;
}


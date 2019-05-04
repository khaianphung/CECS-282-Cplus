#include "Task.h"

#include <iostream>
using namespace std;
Task::Task( int d, int mo, int y, int h, int mi, int s,string t): Date(d, mo, y), Time(h, mi, s)
{
    taskName = t;
}

/*print out the date
*/

void Task::printDateTime()
{
    printDate();
    cout<< " ";
    printTime();
}


/*overload the < operator
@param1 the task object
@return the boolean indicate if this < than b
*/
bool Task::operator< (Task b)
{
        if(this->month  < b.month)
        {
            return true;
        }
        else if(this->month > b.month)
        {
            return false;
        }
    /*
    if(this->year < b.year)
    {
        return true;
    }
    else if (this->year > b.year)
    {
        return false;
    }
    else if (this->year == b.year)
    {
        if(this->month  < b.month)
        {
            return true;
        }
        else if(this->month > b.month)
        {
            return false;
        }
        else if(this->month == b.month)
        {

            if(this->day  < b.day)
            {
                return true;
            }
            else if(this->day > b.day)
            {
                return false;
            }
            else if(this->day == b.day)
            {
                if(this->hour  < b.hour)
                {
                    return true;
                }
                else if(this->hour > b.hour)
                {
                    return false;
                }
                else if(this->hour == b.hour)
                {
                    if(this->min  < b.min)
                    {
                        return true;
                    }
                    else if(this->min > b.min)
                    {
                        return false;
                    }
                    else if(this->min == b.min)
                    {
                        if(this->sec  < b.sec)
                        {
                            return true;
                        }
                        else if(this->sec > b.sec)
                        {
                            return false;
                        }
                        else if(this->sec == b.sec)
                        {
                            if(this->taskName.compare(b.taskName)<0)
                            {
                                return true;
                            }
                            else if(this->taskName.compare(b.taskName)>0)
                            {
                                return false;
                            }
                            else if(this->taskName.compare(b.taskName)==0)
                            {

                            }
                        }
                    }
                }
            }
        }
    }
*/
    return false;

}

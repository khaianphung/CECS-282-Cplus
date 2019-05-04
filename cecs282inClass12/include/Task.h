#ifndef TASK_H
#define TASK_H

#include "Date.h"
#include "Time.h"
#include<iostream>
using namespace std;
class Task :public Date, public Time
{


public:
    string taskName;
    //constructor
    Task( int d, int mo, int y, int h, int mi, int s , string t);
    //print out thedate and time
    void printDateTime();
    //get the taskname
    string getTaskName(){
        return taskName;
    }
    //print out the task
    void print(){
        cout<<taskName<<"-"<<month<<"/"<<day<<"/"<<year<<" "<<hour<<":"<<min<<":"<<sec<<endl;
    }

    //overload the < operator
    /*
    @param1 the task object
    @result the boolean value indicaate if this < than b
    */
    bool operator< (Task b);
};


#endif // TASK_H

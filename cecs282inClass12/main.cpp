#include <iostream>
#include "Date.h"
#include "Task.h"
#include "Time.h"
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
void selectionSort( Task &list )
{
    int SIZE = 5;

}
int main()
{
    int SIZE=5;
    int tryHard =5;
    tryHard = SIZE;


    Task *arr[SIZE];
    cout<<"Schedule"<<endl;
    arr[0] = new Task(29,4,2017,12,30,0,"A");
    arr[1] = new Task(3,5,2017,14,20,0,"B");
    arr[2] = new Task(29,4,2017,10,0,0,"C");
    arr[3] = new Task(28,4,2017,14,30,0,"D");
    arr[4] = new Task(29,4,2017,20,0,0,"E");
    /*
    for(int i =0; i<tryHard; i++)
    {
        //int d, int mo, int y, int h, int mi, int s , string t
        cout<<"Enter task "<<i+1<<" name:"<<endl;
        string t;
        cin>>t;

        cout<<"Enter year: "<<endl;
        int y= validate(0,9999);
        cout<<"Enter month: "<<endl;
        int m= validate(0,12);
        cout<<"Enter day: "<<endl;
        int d= validate(0,31);

        cout<<"Enter hour: "<<endl;
        int h= validate(0,23);
        cout<<"Enter minute: "<<endl;
        int mi= validate(0,59);
        cout<<"Enter sec: "<<endl;
        int s= validate(0,59);


        arr[i] = new Task(d,m,y,h,mi,s,t);
    }*/
    //first display
    cout<<"Before"<<endl;
    for(int i =0; i<tryHard; i++)
    {


        arr[i]->print();
    }
    //sort
     for(int i=0; i < SIZE; i++)
    {
        int lowest = i;
        for( int j= i +1; j< SIZE; j++)

        {
            if( *arr[j] < *arr[lowest])
            {
                lowest = j;
            }
        }
        Task *swap = arr[i];
        arr[i] = arr[lowest];
       arr[lowest] = swap;
    }

    cout<<"After"<<endl;
    for(int i =0; i<tryHard; i++)
    {


        arr[i]->print();
    }
    return 0;
}

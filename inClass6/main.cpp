/*
Khai Phung
CECS 282
inClass6
*/
#include <iostream>//scanner
#include <cstdlib>
#include <ctime>//to use random
#include <string>
#include <sstream>
#include<string.h>
#include <vector>
using namespace std;

/*
display the array
@param1 vector list to store the random integers
*/
void display(int *list, int n)
{
    for (int i= 0; i< n; i++)
    {
        cout<<list[i]<< ((i%10 == 9) ? ("\n") : (", "));

    }
}

/*
bubble sort the array
@param1 vector list to store the random integers
*/
void bubbleSort(int *list,int n)
{
    bool swapped = false;
    do
    {
        swapped = false;
        for( int i=0; i< n - 1; i++)
        {
            if( list[i] > list[i + 1] )
            {
                int swap = list[i];
                list[i] = list[i + 1];
                list[i+1] = swap;
                swapped = true;
            }
        }
    }
    while( swapped);
}


void swapping(int *list,int r1, int r2)
{
    int temp = list[r1];
    list[r1]=list[r2];
    list[r2]=temp;
}
/*shuffle 2 random ints
@param1 vector list to store the random integers
*/
void shuffle(int *list,int n )
{

    int r1,r2;
    for (int i =0; i<10*n ; i++)
    {


        r1 = rand() % 10 + 0;
        r2 = rand() % 10 + 0;

        swapping(list,r1,r2);

}
 display(list,n);
}

/*
find the maximum int
@param1 vector list to store the random integers
*/
int maximum(int *list,int n )
{
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        if(list[i]>maxi)
        {
            maxi=list[i];
        }
    }
    return maxi;
}

int checkMenuInput(int start, int endi)
{
    int input = 0;
    bool fail= true;

    while (fail)
    {

        cout<<"Enter a number: "<<endl;
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
}
int main()
{
    srand (time(NULL));
    int* arr = NULL;
    cout<<"Enter the size of the array:"<<endl;

    int n = checkMenuInput(1, 999999999);
    srand (time(NULL));
    arr = new (nothrow) int[n];
    for (int i = 0; i<n; i++)
    {

        int r1 = rand() % 100 + 1;
        arr[i] = r1;
    }

    bool play =true;
    while (play)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Display "<<endl;
        cout<<"2.Sort  "<<endl;
        cout<<"3.Shuffle  "<<endl;
        cout<<"4.Max  "<<endl;
        cout<<"5.Quit "<<endl;
        int choice = checkMenuInput(1, 5);
        switch(choice)
        {
        case 1:
        {
            display(arr,n);
            break;
        }
        case 2:
        {
            bubbleSort(arr,n);
            display(arr,n);
            break;
        }

        case 3:
        {
            shuffle(arr,n);
            display(arr,n);
            break;
        }

        case 4:
        {
            cout<<"MAX IS: "<<maximum(arr,n)<<endl;

            break;
        }
        case 5:
        {
            delete [] arr;
            play= false;
            break;
        }



        }

    }
    return 0;
}

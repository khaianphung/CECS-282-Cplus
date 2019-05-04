/*
Khai Phung
CECS 282
Assignment 4
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
To validate an input
@param1 start: Minimum input
@param2 endi: maximum input
@result int the valid input
*/
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

/*
assign integers into vector
@param1 v a vector saved to show unsorted vector
@param2 v1 a vector saved to show sorted vector

*/
void populateVector(vector <int> &v,vector <int> &v1)
{
    cout<<"Enter the size of the vector"<<endl;
    int size=checkMenuInput(1,100);

    int number;
    cout<<"Populate Vector "<<endl;
    srand (time (NULL));//start the seed
    for( int i = 0; i<size; i++)
    {
        number= rand() % 100 + 1 ; // random number between 1-100
        cout<<number<<endl;
        v.push_back(number);
        v1.push_back(number);
    }
}

/*
print out the unsorted vector
@param1 vector v1 which in the unsorted vector


*/
void printVector(vector <int> &v1)
{

    for (int i=0; i<(int)v1.size(); i++)
    {
        cout<<v1[i]<< ((i%10 == 9) ? ("\n") : (" "));

    }
}

/*
print out the sorted vector
@param1 vector v which in the sorted vector


*/
void selectionSort( vector <int> &list)
{
    for (int i=0; i< (int)list.size(); i++)
    {
        int lowest = i;
        for (int j= i +1 ; j<(int)list.size(); j++)
        {
            if(list[j]<list[lowest])
            {
                lowest = j;
            }
        }
        int swap = list[i];
        list[i] = list[lowest];
        list[lowest]= swap;
    }
}



/*
print out the sum of the integers in the vector
@param1 vector v which in the sorted vector
@return the summation of the integers in the vector

*/
int sum(vector <int> &v1)
{
    int sum = 0;
    for (int i = 0; i < (int)v1.size(); i++)
    {
        sum += v1[i];
    }
    return sum;
}

/*
print out the average of the integers in the vector
@param1 vector v which in the sorted vector
@return  double, the average of the integers in the vector

*/
double average(vector <int> &v1)
{
    return sum(v1)/(int)v1.size();
}

/*
print out the max of the integers in the vector
@param1 vector v which in the sorted vector
@return the maximum of the integers in the vector

*/
int maximum(vector <int> &v1)
{
    int maxi = 0;
    for (int i = 0; i < (int)v1.size(); i++)
    {
        if (v1[i] > maxi)
        {
            maxi = v1[i];
        }
    }
    return maxi;
}

/*
print out the minimum of the integers in the vector
@param1 vector v which in the sorted vector
@return the minimum of the integers in the vector

*/
int minimum(vector <int> &v1)
{
    int mini = v1[0];
    for (int i = 0; i < (int)v1.size(); i++)
    {
        if (v1[i] < mini)
        {
            mini = v1[i];
        }
    }
    return mini;
}


/*
print out the median which is the middle element of the integers in the vector
@param1 vector v which in the sorted vector
@return the median of the integers in the vector

*/
int median(vector <int> &v1)
{
    selectionSort(v1);
    if  (v1.size() % 2==0)
    {
        return (v1[v1.size()/2] + v1[(v1.size()/2)-1]) /2 ;
    }
    else
    {
        return v1[v1.size() /2];
    }

}

/*
print out the mode which is the most frequent element of the integers in the vector
@param1 vector v which in the sorted vector
@return the mode of the integers in the vector

*/
void mode(vector <int> &v1) // if there is more than one, return a vector containing the modes
{
    for (int i=0; i< (int)v1.size(); i++)
    {
        int lowest = i;
        for (int j= i +1 ; j<(int)v1.size(); j++)
        {
            if(v1[j]<v1[lowest])
            {
                lowest = j;
            }
        }
        int swap = v1[i];
        v1[i] = v1[lowest];
        v1[lowest]= swap;
    }

    vector <int> v2(100);
    vector <int> v3;
    for (int i=0; i<=v1.size(); i++)
    {
        v2[v1[i]]++;
    }



int maxi = 0;
for (int i=0; i<100; i++){//find the most frequent
    if (v2[i] > maxi)
        {
            maxi = v2[i];

        }
}
cout<<"The MAximum occurance time is: "<<maxi<<endl;
for (int i=0; i<100; i++){//push them into a vector
    if (v2[i] == maxi)
        {
            v3.push_back(i);
        }
}

    for(int i =0; i<v3.size(); i++)//display. v3 is the position
    {
        cout<<v3[i]<<endl;
        //cout<<v1[v3[i]]<< " Appear"<<maxi<< " times" <<endl;

    }





}



/*
print out the closest position of a integer in the vector
@param1 vector v which in the sorted vector
@return the position of the finding integer

*/
int finding(vector <int> &v1, int find)
{
    int low =0, high = v1.size() -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (v1[mid] == find)
        {
            return mid;

        }
        else if (v1[mid]< find)
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }
    }
    return -1;
}

int main()
{

    vector<int> v;
    vector <int> v1;
    bool play= true;


    bool inProgress= true;

    populateVector(v,v1);


    while (play)
    {
        cout<<"Menu Options: "<<endl;//DA MENU
        cout<<"1.Display unsorted list"<<endl;
        cout<<"2.Display sorted list"<<endl;
        cout<<"3.Display sum"<<endl;
        cout<<"4.Display average"<<endl;
        cout<<"5.Display maximum value"<<endl;
        cout<<"6.Display minimum value"<<endl;
        cout<<"7.Display median value"<<endl;
        cout<<"8.Display mode values"<<endl;
        cout<<"9.Find matching value"<<endl;
        cout<<"10.Quit"<<endl;
        int choose;
        choose = checkMenuInput(1,10);


        switch (choose)
        {
        case 1:

        {
            cout<<"Unsorted List: "<<endl;
            printVector(v);
            break;
        }
        case 2:
        {
            cout<<"Sorted List: "<<endl;
            selectionSort(v1);
            printVector(v1);
            break;
        }
        case 3:
        {

            cout<<"The sum is : "<<sum(v1)<<endl;
            break;
        }

        case 4:
        {

            cout<<"The average is: "<<average(v1)<<endl;
            break;
        }

        case 5:
        {
            cout<<"The max is : "<<maximum(v1)<<endl;

            break;
        }
        case 6:
        {
            cout<<"The min is : "<<minimum(v1)<<endl;

            break;
        }
        case 7:
        {
            cout<<"The median is : "<<median(v1)<<endl;

            break;
        }
        case 8:
        {
            //vector<int> x = mode(v1);
            cout<<"The mode is : "<<endl;

            mode(v1);

            /*
                        for (int i =0; i<x.size(); i++)
                        {
                            cout<<x[i]<<endl;
                        }
            */
            break;
        }
        case 9:
        {
            cout<<"What word do you want to find? "<<endl;
            int find=checkMenuInput(1,100);

            cout<<"The matching value is first found at : "<<finding(v1, find )<<endl;

            break;
        }

        case 10:
        {
            play = false;//STOP THE PROGRAM
            break;
        }

        default:
        {
            break;
        }
        }
    }

    return 0;
}

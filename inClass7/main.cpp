#include <iostream>
#include <fstream>

#include <string>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>


using namespace std;
struct Box
{
    int length;
    int width;
    int height;
}; //prints out the box’s data
//passed in by value
void printBox( Box b )
{
    cout<< "The length is:"<<b.length<< endl;
    cout<< "The width is:"<<b.width<< endl;
    cout<< "The height is:"<<b.height<< endl;
}//sets the values of a box
//passed in by reference (can change values)
void setDimentions(Box &b, int len, int wid, int high)
{
    b.length = len;
    b.width = wid;
    b.height = high;
}//calculates the volume of a box
//passed in by const reference (cannot change values)
int calcVolume( const Box &b )
{
    return b.length * b.width * b.height;
}//constructs user inputted box and returns it
Box createBox( )
{
    int len, wid, high;
    cout<< "Enter length, width, and height:";
    cin >> len >> wid >> high;
    Box b = { len, wid, high };
    return b;
}
int main()
{
    Box box = createBox();
    printBox(box);
    cout<< "Volume = " << calcVolume(box) << endl;
    setDimentions(box, 3, 4, 5);
    printBox(box);
    return 0;
}

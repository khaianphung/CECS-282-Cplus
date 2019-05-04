#include <iostream>

using namespace std;

void squared( int *p )
{
    *p *= *p;
}
int * getPtr( int &a )
{
    int *ptr = &a;
    return ptr;
}
int main()
{
    int x = 5;
    squared(&x);
    int *ptr = getPtr(x);
    cout<<&ptr;
}

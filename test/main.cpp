#include <iostream>

using namespace std;

int main()
{
    int x= 5;
    double y= 10.3;

    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"&x: "<<&x<<endl;
    cout<<"&y: "<<&y<<endl;

    int *ptrX = &x;
    double *ptrY = &y;
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"ptrX: "<<ptrX<<endl;
    cout<<"ptrY: "<<ptrY<<endl;


    cout<<endl;
    cout<<"x: "<<x<<endl;
    cout<<"&x: "<<&x<<endl;
    cout<<"ptrX: "<<ptrX<<endl;
    cout<<"*ptrX: "<<*ptrX<<endl;
    cout<<"&ptrX: "<<&ptrX<<endl;
    cout<<"sizeofX: "<<sizeof(x)<<endl;
    cout<<"sizeof(ptrX): "<<sizeof(ptrX)<<endl;
    cout<<"*ptrX + *ptrY"<<*ptrX + *ptrY<<endl;
    //cout<<"(*ptrX)++ "<<(*ptrX)++<<endl;

    cout<<endl;
    cout<<"*ptrX*2: "<<(*ptrX) *2<<endl;
    cout<<"*ptrY + 5.2: "<<(*ptrY) +5.2<<endl;
    cout<<"*ptrX + 10: "<<(*ptrX) +10 <<endl;

    cout<<endl;
    x= 5;
    y= 10.3;//comment or it will mess up addresses
    /*
    cout<<"ptrX: "<<ptrX<<endl;
    ptrX ++;
    cout<<"ptrX: "<<ptrX<<endl;
    cout<<"&X: "<<&x<<endl;
    *ptrX = 3;
    cout<<"X: "<<x<<endl;
    cout<<"ptrX: "<<*ptrX<<endl;
    */
    cout<<endl;
    cout<<"*ptrX++;"<<endl;
    x= 5;
    y= 10.3;
    int result =*ptrX++;
    cout<<"x "<<x<<endl;
    cout<<"&x "<<&x<<endl;
    cout<<"ptrX "<<ptrX<<endl;
    cout<<"*ptrX "<<*ptrX<<endl;

    cout<<endl;
    cout<<"*++ptrX"<<endl;
    x= 5;
    y= 10.3;
   ptrX = &x;
    result =*++ptrX;
    cout<<"x "<<x<<endl;
    cout<<"&x "<<&x<<endl;
    cout<<"ptrX "<<ptrX<<endl;
    cout<<"*ptrX "<<*ptrX<<endl;

    cout<<endl;
    cout<<"++*ptrX"<<endl;
    x= 5;
    y= 10.3;
    ptrX = &x;
    result =++*ptrX;
    cout<<"x "<<x<<endl;
    cout<<"&x "<<&x<<endl;
    cout<<"ptrX "<<ptrX<<endl;
    cout<<"*ptrX "<<*ptrX<<endl;
    return 0;
}

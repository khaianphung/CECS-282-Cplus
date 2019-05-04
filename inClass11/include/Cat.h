
#ifndef CAT_H
#define CAT_H
#include <iostream>

using namespace std;
class Cat{

protected:
    string name;
    int hunger;
public:


    Cat(string n, int h);
    //pure virtual function
    virtual int feed()=0;
    virtual int play()=0;
    virtual int pet()=0;
    /*
    overload the << operator
    @param1 the outstream
    @param2 the object cat
    @return the outstream
    */
    friend ostream &operator<<(ostream &out,Cat &p);

};


#endif // CAT_H_INCLUDED

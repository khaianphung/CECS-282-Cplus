#ifndef FRACTION_H
#define FRACTION_H



#include <iostream>

using namespace std;

class Fraction
{
private:
    int num;
    int den;
public:
    /*fidn the gcd of num and denominator to simplify the fraction
    *@param1 the num
    *@param2 the den
    *@return the gcd
    */
    int gcd(int a, int b);
    //constructor
    Fraction( int num, int den );
    /*get the numerator
    */
    int getNum()
    {
        return num;
    }
    /*get the denominator
    @return the denominator
    */
    int getDen()
    {
        return den;
    }
    /*printout the fraction in a/b form
    */
    void printFraction();

    Fraction add( Fraction p );
    //overloaded +
    //@param1 : fraction to do operation
    //@return result fraction
    Fraction operator+ (Fraction b);
    //overloaded -
    //@param1 : fraction to do operation
    //@return result fraction
    Fraction operator- (Fraction b);
    //overloaded *
    //@param1 : fraction to do operation
    //@return result fraction
    Fraction operator* (Fraction b);
    //overloaded /
    //@param1 : fraction to do operation
    //@return result fraction
    Fraction operator/ (Fraction b);
    //overloaded ==
    //@param1 : fraction to do operation
    //@return boolean value whether they are equal
    bool operator== (Fraction b);

    //overloaded cout<<
    //param1 ostream for cout
    //Fraction to cout
    //return the stream
    friend ostream &operator<<(ostream &out,Fraction p);
    //overloaded cin>>
    //param1 ostream for cin
    //Fraction to cin
    //return the stream
    friend istream &operator>>(istream &in,Fraction &p);


};


#endif // FRACTION_H_INCLUDED

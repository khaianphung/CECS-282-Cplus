
#include "Fraction.h"

/*find the gcd to simplify the fraction
@param1 numerator
@param2 denominator
@return the gcd
*/
int Fraction::gcd(int a, int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}
//constructor
Fraction::Fraction( int num, int den )

{
    int g= gcd(num,den);
    cout<<"g:"<<g<<endl;
    num = num/g;
    den = den/g;

    (*this).num = num; //this -> x also works
    if(den == 0)
    {
        cout<<"Please don't enter denominator = 0, it has been changed to 1"<<endl;
        den =1;
    }
    (*this).den = den;
}
//print the point x and y
void Fraction::printFraction()
{
    cout<< "(" << num << "/" << den << ")" << endl;
}

/*add a point to another point
@param1 the adding point
@return the new point
*/
Fraction Fraction::add( Fraction p )
{
    int xVal = 0, yVal = 0;
    xVal = (*this).num + p.num;
    yVal = (*this).den + p.den;
    Fraction result( xVal, yVal );
    return result;
}
//overlodade *

Fraction Fraction::operator* (Fraction b)
{
    Fraction r(this->num*b.num, this->den*b.den);
    return r;
}

Fraction Fraction::operator/ (Fraction b)
{
    Fraction r(this->num*b.den, this->den*b.num);
    return r;
}

/*overloaded +

   */
Fraction Fraction::operator+ (Fraction b)
{

    if(this->den == b.den)
    {
        Fraction r(this->num+b.num, this->den);
        return r;
    }
    else
    {
        Fraction r(this->num*b.den+b.num*this->den
                   , this->den*b.den);
        return r;
    }

}
//overloaded -
Fraction Fraction::operator- (Fraction b)
{

    if(this->den == b.den)
    {
         Fraction r(this->num-b.num, this->den);
        return r;
    }
    else
    {
         Fraction r(this->num*b.den-b.num+this->den
                   , this->den*b.den);
        return r;
    }

}

/*overloaded ==
    check if a point is equal to  another point
    @return boolean value indicate equal
    */
bool Fraction::operator== (Fraction b)
{
    if(this->num == b.num
            && this->den == b.den)
    {
        return true;
    }
    return false;
}






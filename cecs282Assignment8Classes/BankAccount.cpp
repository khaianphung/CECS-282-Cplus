#include "BankAccount.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
//constructor
BankAccount::BankAccount(double num)
{
    balance = 0;
    id = num;


}

//setter
void BankAccount::setID(int x)
{
    id =x;
}
/* deposit money to the account
    @param1 the amount of money deposit
    */
double BankAccount::deposit(double s)
{

    balance += s;
    return balance;

}
/* withrawal money to the account
    @param1 the amount of money withrawal
    */
double BankAccount::withrawal(double s)
{


    balance -= s;
    return balance;

}



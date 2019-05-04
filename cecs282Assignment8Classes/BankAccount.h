#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
private:
    int id;
    double balance;
public :
    //constructor
    BankAccount(double num);
    /*
    adjust the id
    @param1 the adjusted amount
    */
    void setID(int x);
    /*get the balance
    @return the account balance
    */
    double getBalance()
    {
        return balance;
    }
     /*get the id
    @return the account number
    */
    int getAccountNumber()
    {
        return id;
    }
    /*deposit money to the account
    @param1 the amount of money deposit
    */
    double deposit(double s);
    /*
    withrawal money to the account
    @param1 the amount of money withrawal
    */
    double withrawal(double s);


};

#endif // BANKACCOUNT_H

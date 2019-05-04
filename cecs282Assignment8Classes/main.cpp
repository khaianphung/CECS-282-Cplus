#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "BankAccount.h"
#include <vector>
using namespace std;
/*
validate the valid entry
@param1 lower bound
@param2 uper bound
@result the valid integer
*/
int validate(int start, int endi)
{
    int input = 0;
    bool fail= true;

    while (fail)
    {

        //cout<<"Enter a number: "<<endl;
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
}//validate

/*the main menu
*/
void mainMenu()
{
    cout<<"Main Menu"<<endl;
    cout<<"1.Access Account"<<endl;
    cout<<"2.Quit"<<endl;
}//mainMenu

/*The account menu
*/
void accountMenu()
{
    cout<< "1.Deposit funds"<<endl;
    cout<< "2.Withrawal funds"<<endl;
    cout<< "3.Check Account Balance"<<endl;
    cout<< "4.Put in Savings"<<endl;
    cout<< "5.Transfer Money"<<endl;
    cout<< "6.Go back to Menu"<<endl;

}//accountMenu

/*check the accountbalance
@param the bank account
@result the balance
*/
double checkBalance(BankAccount account)
{
    return account.getBalance();
}//checkBalance

/*transfer the money to another account
@param1 the amount of money transfer
@param2 the bank account used to transfer
@param3 the target*/
void transferFunds(double amount, BankAccount &acc, BankAccount &bcc)
{
    acc.withrawal(amount);
    bcc.deposit(amount);
}

/*accumulate the interest for the account
@param1 the bank account
@param2 the rate
@param3 the year saving
*/
void accrueInterest(BankAccount &acc, double r, int y)
{
    double interest = acc.getBalance()*pow((1+r),y)-acc.getBalance();
    cout<<"Interest: "<<interest<<endl;
    acc.deposit(interest);
}

/*find the bank account
@param1 the account number
@param2 the array of bank account
@return the bank account desired
*/
BankAccount findBankAccount(int num, BankAccount arr[])
{
    for (int i = 0; i<10; i++)
    {
        if (arr[i].getAccountNumber() == num)
        {
            return arr[i];
        }//if
    }//for
    return  BankAccount(-1);//because cannot use null
}//find bank account
int main()
{
    //srand(time(NULL));//seed
    BankAccount bArr[10] = {(0),(0),(0),(0),(0),(0),(0),(0),(0),(0)};
    for (int i =0; i<10; i++)
    {
        /* to randomize unique number
        int r = rand() %10 +100;

        if (i!=0)
        {
            while (findBankAccount(r,bArr).getAccountNumber() != -1)
            {
                r = rand() %10 +100;
            }
        }
        */
        bArr[i].setID(100+i);
        cout<<"Account "<<i<<":"<<bArr[i].getAccountNumber()<<endl;
    }

    cout<<"Welcome to Da Bank"<<endl;
    bool play = true;
    while (play)
    {
        mainMenu();
        int choice = validate(1,2);
        if (choice == 1)
        {
            cout<<"Enter ID number: "<<endl;
            int accID = validate(100,109);

            /*
            for (int i = 0 ; i<10 ; i++){
                if (bArr[i].getAccountNumber() == accID ){
                     curr = bArr[i];
                }
            }
            */
            bool play2= true;
            while(play2)
            {
                accountMenu();
                int choice2 = validate(1,6);
                switch(choice2)
                {

                case 1:
                {
                    cout<<"Enter amount to deposit: "<<endl;
                    int dep = validate(1,999999);
                    bArr[accID-100].deposit(dep);
                    cout<<"Account balance: "<<checkBalance(bArr[accID-100])<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Enter amount to withdraw: "<<endl;
                    int with = validate(1,checkBalance(bArr[accID-100]));
                    bArr[accID-100].withrawal(with);
                    cout<<"Account balance: "<<checkBalance(bArr[accID-100])<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Account balance: "<<checkBalance(bArr[accID-100])<<endl;
                    break;
                }
                case 4:
                {
                    accrueInterest(bArr[accID-100], 0.05, 5);
                    cout<<"Account balance: "<<checkBalance(bArr[accID-100])<<endl;
                    break;
                }
                case 5:
                {
                    cout<<"Enter account id to transfer: "<<endl;
                    int transferID = validate(100,109);



                    cout<<"Enter amount to transfer: "<<endl;
                    double transferMoney = validate(1,checkBalance(bArr[accID-100]));
                    cout<<transferID-100;
                    transferFunds(transferMoney, bArr[accID-100], bArr[transferID-100]);
                    cout<<"Account balance: "<<checkBalance(bArr[accID-100])<<endl;
                    break;
                }
                case 6:
                {
                    play2= false;//need to fix5, the target account doesnt receive money
                    break;

                }
                default:
                {
                    break;
                }
                }
            }
        }
        if (choice == 2)
        {
            play = false;
        }
    }//while play



    return 0;

}

//main

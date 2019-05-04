/*Khai Phung
01/27/2017
Project inclass1
Description: guess a random number
*/
#include <iostream>//scanner
#include <cstdlib>
#include <ctime>//to use random
using namespace std;

int main()
{
    srand (time (NULL));//start the seed
    int r1 = rand() % 100 + 1 ; // random number between 1-100
    bool fail = false;//initialize variables
    int tries = 1;
    int input = 0;
    while ( fail== false){//to make the program run continuously
      cout<<"Guess a number: ";
      if(cin >> input){
        if(input > r1 && input <=100){//if input > random number, tell it's too high
          cout<<"Too High.Guess again: "<<endl;
          tries++;//calculate the tries
        }else if (input< r1 && input >=0){//if input < random number, tell it's too low
          cout<<"Too low. Guess again: "<<endl;
          tries++;//calculate the tries
        }else if (input == r1){//if it corrects, stop teh program
          cout<<"Correct! You got it in "<<tries<<" times";
          fail = true;
          tries++;//calculate the tries
        }else{
            cout<<"Invalid.";
        }


      }else{
        cin.clear();//clear the invalid entry
        string invalid;
        cin >> invalid;
        cout<<"Invalid. Guess again"<<endl;
      }


    }
    return 0;
}

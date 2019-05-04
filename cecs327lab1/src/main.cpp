#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;


    struct Foo{
        //char pointArr[20];
        // char *pointArr;
        int arr[20];

        };

    void printMenu(){
        cout<<"Main Menu"<<endl;
        cout<<"1.Access Pointer"<<endl;
        cout<<"2.List deallocated memory(index)"<<endl;
        cout<<"3.Deallocate all memory"<<endl;
        cout<<"4.Exit the program"<<endl;
    }

    void printSubMenu(){
        cout<<"1.Print the first 10 char's in the chosen array"<<endl;
        cout<<"2.Delete all the char's associated with this pointer"<<endl;
        cout<<"3.Return to main menu"<<endl;

    }

    int main()
{
    Foo f;
    f.arr[0] = 2700;
    int length = sizeof(f.arr)/sizeof(int);
    //cout<<length<<endl;
    for (int i=0; i<length-1; i++){
        f.arr[i+1]=2*f.arr[i];
    }


    //int *pointArr;
    //pointArr = (int*)malloc(length);
    char *pointArr[20] ;//={"a","b","c"};
    //cout<<"Pointer arr size "<<sizeof(f.pointArr)/sizeof(char)<<endl;
    for(int i = 0; i < 20; ++i)
    {
        char x = 97 + rand() % 26;
        pointArr[i] = new char(x);
        *pointArr[i] =f.arr[i];

    }

/*
   for (int i = 0; i < length; i++) {

      //pointArr[i] = f.arr[i]; // assign the address of integer.
   }
*/

   //random character array
   /*
    for(int i=0; i<length; i++){
        char x = 97 + rand() % 26;
        f.pointArr[i]= toupper(x);
        //cout<<f.pointArr[i]<<endl;
        //f.pointArr[i]=x;
    }
*/
     //print the arrays


    cout<<"Char array"<<endl;
   for(int i=0; i<20 ; i++){
        cout<<*&pointArr[i]<<endl;
        //cout<<&f.pointArr[i]<<endl;

    }










    printMenu();
    cout<<"Enter an option:"<<endl;
    int choice;
    cin>>choice;
    bool replay = true;
    while (replay){
    if (choice == 1){
        //access pointer
        printSubMenu();
        bool replay2 = true;
        while(replay2){
            cout<<"Choose a submenu"<<endl;
            int choice2;
            cin>>choice2;
            if(choice2 == 1){
               //1.Print the first 10 char's in the chosen array

            }


            if(choice2 == 2){
              //2.Delete all the char's associated with this pointer"


            }
            if(choice2 == 3){
                //return to main menu
                replay2 = false;
            }
        }
    }
    if (choice == 2){
        //List deallocated memory(index)
    }
    if (choice == 3){
        //Deallocate all memory
    }
    if (choice == 4){
     //exit the program
        replay = false;
    }
    }
}


#include "Cat.h"
#include "Ocelot.h"
#include "Tabby.h"
#include "Tiger.h"
#include <iostream>



using namespace std;

/*
validate if the value is valid
@param1 lower bound
@param2 upper bound
@return the valid input
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

/*overlaod the << operator
@param1: the out stream
@param2 the object Cat
@return the outstream
*/
ostream &operator<<(ostream &out, Cat &p)
{
    if (p.hunger ==3)
    {
        cout << " is very hungry. Hungry level="<<p.hunger<<endl;
    }
    if (p.hunger ==2)
    {
        cout << " is slightly hungry. Hungry level="<<p.hunger<<endl;
    }
    if (p.hunger ==1)
    {
        cout << " is full. Hungry level="<<p.hunger<<endl;
    }

    return out;
}





/*
display the cat menu
*/
void catMenu()
{
    cout<<"Cat List"<<endl;
    cout<<"1.Tiger"<<endl;
    cout<<"2.Ocelot"<<endl;
    cout<<"3.Tabby"<<endl;
    cout<<"4.Quit"<<endl;

}
/*
display the interaction menu
*/
void interactionMenu()
{
    cout<<"Cat Interaction"<<endl;
    cout<<"1.Play"<<endl;
    cout<<"2.Feed"<<endl;
    cout<<"3.Pet"<<endl;
    cout<<"4.Choose another cat"<<endl;
}


int main()

{
    int hp = 10;
    bool play = true;
    Cat *arr[3];
    arr[0]= new Tiger("Tigger",3);
    arr[1]= new Ocelot("Ocelotte",2);
    arr[2]= new Tabby("Table",2);
    while(play)
    {
        catMenu();
        int choice = validate (1,4);
        if (choice ==1)
        {
            bool play2= true;


            while(play2)
            {
                if(hp <= 0){
                    cout<<"You dieded"<<endl;
                    play = false;
                    play2 = false;
                    break;
                }
                cout<<"YOUR HP= "<<hp<<endl;
                cout<<"Tiger"<<*arr[0]<<endl;
                interactionMenu();
                int choice2= validate(1,4);
                if(choice2 == 1)
                {
                    hp -= arr[0]->play();
                }
                if(choice2 == 2)
                {
                    hp -=arr[0]->feed();
                }
                if(choice2 == 3)
                {
                    hp -=arr[0]->pet();
                }
                if(choice2 == 4)
                {
                    play2= false;
                }
            }
        }
        if (choice ==2)
        {
            bool play2= true;

            while(play2)
            {
                if(hp <= 0){
                    cout<<"You dieded"<<endl;
                    play = false;
                    play2 = false;
                    break;
                }
                cout<<"YOUR HP= "<<hp<<endl;
                cout<<"Ocelotte"<<*arr[1]<<endl;
                interactionMenu();
                int choice2= validate(1,4);
                if(choice2 == 1)
                {
                    hp -=arr[1]->play();
                }
                if(choice2 == 2)
                {
                    hp -=arr[1]->feed();
                }
                if(choice2 == 3)
                {
                    hp -= arr[1]->pet();
                }
                if(choice2 == 4)
                {
                    play2= false;
                }
            }
        }

        if (choice ==3)
        {
            bool play2= true;

            while(play2)
            {
                if(hp <= 0){
                    cout<<"You dieded"<<endl;
                    play = false;
                    play2 = false;
                    break;
                }
                cout<<"YOUR HP= "<<hp<<endl;
                cout<<"Table"<<*arr[2]<<endl;
                interactionMenu();
                int choice2= validate(1,4);
                if(choice2 == 1)
                {
                    hp -=arr[2]->play();
                }
                if(choice2 == 2)
                {
                    hp -=arr[2]->feed();
                }
                if(choice2 == 3)
                {
                    hp -=arr[2]->pet();
                }
                if(choice2 == 4)
                {
                    play2= false;
                }
            }
        }
        if (choice ==4)
        {
            play =false;
        }
    }
    return 0;
}

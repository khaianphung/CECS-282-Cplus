/*Khai Phung
01/27/2017
Project Assignment1
Description: guess a random number
*/

////////////////////////////Still need to limit input, String is solved , but not double or exceed limits
#include <iostream>//scanner
#include <cstdlib>
#include <ctime>//to use random
using namespace std;

void visual(int r)
{

    string a=" ", b= " ",c =" ";
    if (r==1)
    {
        a="o";
    }
    else if (r==2)
    {
        b = "o";
    }
    else if (r==3)
    {
        c = "o";
    }
    cout<<"  __     __     __  "<<endl;
    cout<<" /  \\   /  \\   /  \\ "<<endl;
    cout<<"/ "<<a <<"  \\ / "<<b<<"  \\ /"<< c  <<"   \\ "<<endl;
}


int main()
{

    bool play = true;//initialize variables
    int gamePlayed=0, gameWon = 0,gameLost = 0 ;
    int input = 0;
    int money = 100, bet=0;
    while (play  == true)
    {

        cout<<"The Shell Game: "<<endl;
        cout<<"1.Play"<<endl;
        cout<<"2.Quit"<<endl;
        int choice = 0;
        cout<<"Enter option: ";



        bool yes= true;
        while (yes)
        {
            while (!(cin >> choice))
            {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid Entry. Please try again: ";
            }

            while (choice > 2 || choice <=0 )
            {
                cin.clear();

                cout << "Invalid Entry. Please try again: ";
                cin >> choice;
            }
            if (choice > 0 && choice <= 2)
            {
                yes= false;
            }

        }
        switch(choice)
        {
        case 1:
        {



            cout<<"You have: $"<<money<<endl;



            cout<<"How much do you wanna bet: "<<endl;
            yes=  true;
            while (yes)
            {
                while (  !(cin >> bet))
                {


                    cin.clear();
                    string invalid;
                    cin >> invalid;
                    cout << "Invalid Entry. Please try again: ";

                }

                while (bet > money || bet <=0)
                {
                    cin.clear();

                    cout << "Invalid Entry. Please try again: ";
                    cin >> bet;
                }
                if(bet >0 && bet <=money)
                {
                    yes= false;
                }
            }
            cout<<"  __     __     __  "<<endl;
            cout<<" /  \\   /  \\   /  \\ "<<endl;
            cout<<"/ 1  \\ / 2  \\ / 3  \\ "<<endl;
            cout<<"Choose a cup"<<endl;
            yes= true;
            while (yes)
            {
                while (!(cin >> input))
                {

                    cin.clear();
                    string invalid;
                    cin >> invalid;
                    cout << "Invalid Entry. Please try again: ";

                }
                while (input > 3 || input <1)
                {
                    cin.clear();

                    cout << "Invalid Entry. Please try again: ";
                    cin >> input;
                }
                if (input > 0 && input<4)
                {
                    yes = false;
                }
            }


            srand (time (NULL));//start the seed
            int r1 = rand() % 3 + 1 ; // random number between 1-100
            visual(r1);
            if(input > r1 && input <=3) //if input > random number, tell it's too high
            {

                cout<<"WRONG,you lose $"<<bet<<endl;
                money -= bet;

                gameLost++;


            }
            else if (input< r1 && input >=0)  //if input < random number, tell it's too low
            {

                cout<<"WRONG,you lose $"<<bet<<endl;
                money -= bet;


                gameLost++;
            }
            else if (input == r1)  //if it corrects, stop the program
            {

                cout<<"Correct! You won: $"<<bet<<endl;
                money = money + bet;
                gameWon ++;

            }

            if (money < 1)
            {
                cout<<"You lost all your money"<<endl;
                play = false;
                cout<<"Statistics: ";
                cout<<"Games Played: "<<gamePlayed<<endl;
                cout<<"Games Won: "<<gameWon<<endl;
                cout<<"Games Lost: "<<gameLost<<endl;
                cout<<"You won "<<(double) gameWon/gamePlayed*100<<"% of the games"<<endl;
                cout<<"You won $ "<<money-100<<" total"<<endl;
                break;
            }




            gamePlayed ++;
            break;
        }
        case 2:
        {
            play = false;
            cout<<"Statistics: ";
            cout<<"Games Played: "<<gamePlayed<<endl;
            cout<<"Games Won: "<<gameWon<<endl;
            cout<<"Games Lost: "<<gameLost<<endl;
            if (gamePlayed > 0)
            {
                cout<<"You won "<<(double) gameWon/gamePlayed*100<<"% of the games"<<endl;
            }
            else
            {
                cout<<"You haven't played any game "<<endl;
            }
            cout<<"You won $ "<<money-100<<" total"<<endl;
            break;
        }

        }

    }
    return 0;
}


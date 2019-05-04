#include <iostream>
#include <fstream>

#include <string>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>



using namespace std;

/*
read the maze text file
@param1 arr: the array to store the maze
@param2 choice of which maze the player chose
*/
void readMaze(string arr[][15],int choice)
{
    string ch ;
    ifstream file;
    if (choice==1)
    {
        cout<<"MAZE 1"<<endl;
        file.open ("Maze1.txt");
    }
    if (choice==2)
    {
        cout<<"MAZE 2"<<endl;
        file.open ("Maze2.txt");
    }
    if (choice==3)
    {
        cout<<"MAZE 3"<<endl;
        file.open ("Maze3.txt");
    }



    string line = " ";

    while(!file.eof())
    {
        for(int i =0; i<10; i++)
        {
            getline(file,line);
            for(int j =0; j<15; j++)
            {
                arr[i][j] = line[j];//row = j
            }
        }
    }
    file.close();

}

/*
display the maze
@param1 arr: the array to store the maze

*/
void displayMaze(string arr[][15])
{
    int ROW = 10;
    int COL = 15;
    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            cout<<arr[i][j]<< ((j%15 == 14) ? ("\n") : (""));

        }
    }
}

/*
to check the valid input
@param1: lower bound
@param2: upper bound
@return int the valid input
*/
int checkMenuInput(int start, int endi)
{
    int input = 0;
    bool fail= true;

    while (fail)
    {

        cout<<"Enter a number: "<<endl;
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
}

/*
to search the location of start position
@param1 arr the array to store the maze
@param2 current X location
@param3 current Y location
*/
void searchForStart(string arr[][15], int &curX, int &curY)
{
    int row = 10;
    int col = 15;
    for(int i =0; i<row; i++)
    {
        for(int j =0; j<col; j++)
        {
            if( arr[i][j] == "s")
            {
                arr[i][j]= "*";
                curX=i;
                curY=j;
            }
        }
    }
}

/*
display the CHOOSE MAZE MENU

*/
void displayMazeMenu()
{

    cout<<"Choose difficulty: "<<endl;

    cout<<"1.MAZE1 "<<endl;
    cout<<"2.MAZE2 "<<endl;
    cout<<"3.MAZE3 "<<endl;
    cout<<"4.Quit "<<endl;
}

/*
display the CHOOSE DIRECTION MENU

*/
void displayDirectionMenu()
{

    cout<<"Options: "<<endl;

    cout<<"1.Up "<<endl;
    cout<<"2.Down "<<endl;
    cout<<"3.Left "<<endl;
    cout<<"4.Right "<<endl;
    cout<<"Move: "<<endl;
}

/*
Move the thing
@param1 choice2: the direction move
@param2 arr to store the maze array
@param3 curX current X location
@param4 curY current Y location

*/
void moving(int choice2, string arr[][15], int &curX, int &curY)
{

    arr[curX][curY]="_";
    if (choice2==1)
    {
        curX--;
    }
    if (choice2==2)
    {
        curX++;
    }
    if (choice2==3)
    {
        curY--;
    }
    if (choice2==4)
    {
        curY++;
    }
    if(arr[curX][curY]=="f")
    {

    }
    else
    {
        arr[curX][curY]="*";
    }
}

/*
boolean whether the next move is valid or not. IF not dont move
@param1 choice2: the direction move
@param2 arr to store the maze array
@param3 curX current X location
@param4 curY current Y location
@return whether it is ok to move or not

*/
bool checkSpace(string arr[][15], int curX, int curY)
{
    if (arr[curX][curY]== " " ||arr[curX][curY]== "_" ||arr[curX][curY]== "f")
    {
        return true;
    }
    return false;
}

/*
boolean if the player reach the finish point

@param1 arr to store the maze array
@param2 curX current X location
@param43 curY current Y location
@return whether the game is finished

*/
bool checkFinish(string arr[][15], int curX, int curY)
{
    if (arr[curX][curY]== "f")
    {
        cout<<"===================YOU WON======================"<<endl;
        return  false;
    }

    return true;
}

int main()
{

    int ROW = 10;
    int COL = 15;
    string arr[10][15];





    bool play= true;
    while (play)
    {
        displayMazeMenu();
        int choice = checkMenuInput(1,4);
        if (choice == 4)
        {

            play=false;
            break;
        }

        readMaze(arr, choice);
        /*
        while(!file.eof())
        {
            for(int i =0; i<10; i++)
            {
                getline(file,line);
                for(int j =0; j<15; j++)
                {
                    arr[i][j] = line[j];//row = j
                }
            }
        }
        */

        srand (time(NULL));

        int curX=0;
        int curY=0;
        cout<<"Location: "<<curX<<","<<curY<<endl;
        searchForStart(arr, curX, curY);


        bool play2= true;
        while(play2)
        {
            cout<<"Location: "<<curX<<","<<curY<<endl;
            displayMaze(arr);

            displayDirectionMenu();
            int choice2=checkMenuInput(1,4);

            switch (choice2)
            {
            case 1: //up
            {
                int nextMoveX = curX-1;
                int nextMoveY = curY;
                if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                {

                    moving(choice2,arr,curX,curY);
                    play2=checkFinish(arr, curX, curY);

                }
                else
                {
                    cout<<"CANNOT MOVE INTO WALL"<<endl;
                }

                break;

            }
            case 2: //down
            {
                int nextMoveX = curX+1;
                int nextMoveY = curY;
                if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                {

                    moving(choice2,arr,curX,curY);
                    play2=checkFinish(arr, curX, curY);

                }
                else
                {
                    cout<<"CANNOT MOVE INTO WALL"<<endl;
                }
                break;
            }
            case 3: //left
            {
                int nextMoveX = curX;
                int nextMoveY = curY-1;
                if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                {


                    moving(choice2,arr,curX,curY);
                    play2=checkFinish(arr, curX, curY);

                }
                else
                {
                    cout<<"CANNOT MOVE INTO WALL"<<endl;
                }
                break;
            }
            case 4: //right
            {
                int nextMoveX = curX;
                int nextMoveY = curY+1;
                if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                {

                    moving(choice2,arr,curX,curY);
                    play2=checkFinish(arr, curX, curY);
                }
                else
                {
                    cout<<"CANNOT MOVE INTO WALL"<<endl;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }



    }
    return 0;

}

#include <iostream>
#include <fstream>

#include <string>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include <stack>
#include <queue>
#include"Point.h"

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
    bool fail = true;

    while (fail)
    {

        //cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input <= endi && input >= start)
            {
                fail = false;
            }
            else
            {
                cout << "Invalid input: " << endl;
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
string strWord(int index, string line)
{
    int count = 0; // number of read words
    string word; // the resulting word
    for (int i = 0 ; i < line.length(); i++)   // iterate over all characters in 'line'
    {
        if (line[i] == ' ')   // if this character is a space we might be done reading a word from 'line'
        {
            if (line[i+1] != ' ')   // next character is not a space, so we are done reading a word
            {
                count++; // increase number of read words
                if (count == index)   // was this the word we were looking for?
                {
                    return word; // yes it was, so return it
                }
                word =""; // nope it wasn't .. so reset word and start over with the next one in 'line'
            }
        }
        else   // not a space .. so append the character to 'word'
        {
            word += line[i];
        }
    }
}

/*
find the row of the matrix
@param 1 the choice of file to choose
*/
int findRow(int choice)
{

    string ch ;
    ifstream file;
    if (choice==1)
    {

        file.open ("Maze1.txt");
    }
    if (choice==2)
    {

        file.open ("Maze2.txt");
    }
    if (choice==3)
    {

        file.open ("Maze3.txt");
    }
    if (choice==4)
    {

        file.open ("Maze4.txt");
    }
    string line = " ";
    int ROW = 0;

    while (!file.eof())   // do the following as long as there is something to read from the file
    {
        getline(file, line); // read a line from the file and put the value into 'line'
        ROW=atoi(strWord(1, line).c_str()); // if the first word in 'line' equals 'id' ..

        break; // exits the while loop
    }


    return ROW;
}

/*
find the col of the matrix
@param 1 the choice of file to choose
*/
int findCol(int choice)
{

    string ch ;
    ifstream file;
    if (choice==1)
    {

        file.open ("Maze1.txt");
    }
    if (choice==2)
    {

        file.open ("Maze2.txt");
    }
    if (choice==3)
    {

        file.open ("Maze3.txt");
    }
    if (choice==4)
    {

        file.open ("Maze4.txt");
    }
    string line = " ";
    int COL = 0;
    while (!file.eof())   // do the following as long as there is something to read from the file
    {
        getline(file, line); // read a line from the file and put the value into 'line'
        COL=atoi(strWord(3, line).c_str()); // if the first word in 'line' equals 'id' ..

        break; // exits the while loop
    }
    return COL;
}
/*
read the maze text file
@param1 arr: the array to store the maze
@param2 choice of which maze the player chose
*/


char** readMaze(int choice, int ROW, int COL)
{

    char** arr = new char*[ROW];
    for(int i = 0; i < ROW; ++i)
    {
        arr[i] = new char[COL];

    }

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
    if (choice==4)
    {
        cout<<"MAZE 4"<<endl;
        file.open ("Maze4.txt");
    }
    string line = " ";
    while(!file.eof())
    {
        getline(file,line);//ignore the first three


        for(int i =0; i<ROW; i++)
        {
            getline(file,line);
            for(int j =0; j<COL; j++)
            {
                arr[i][j] = line[j];//row = j


            }
        }
    }

    file.close();
    return arr;

}

/*
display the maze
*/
void displayMaze(char **arr, int ROW, int COL)//display weird number
{

    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            cout<<arr[i][j]<< ((j%COL+1 == COL) ? ("\n") : (""));

        }
    }
}





void displayMazeMenu()
{
    cout<<"Choose difficulty: "<<endl;
    cout<<"1.MAZE1 "<<endl;
    cout<<"2.MAZE2 "<<endl;
    cout<<"3.MAZE3 "<<endl;
    cout<<"4.MAZE4 "<<endl;
    cout<<"5.Quit "<<endl;
}
void displayDirectionMenu()
{

    cout<<"Options: "<<endl;
    cout<<"1.Up "<<endl;
    cout<<"2.Down "<<endl;
    cout<<"3.Left "<<endl;
    cout<<"4.Right "<<endl;
    cout<<"5.Leave it to the dfs "<<endl;
    cout<<"Move: "<<endl;
}
void solvingMethodMenu()
{
    cout<<"1.DFS"<<endl;
    cout<<"2.BFS"<<endl;
    cout<<"3.Solve maze by yourself"<<endl;
    cout<<"4.Back to Maze Choosing"<<endl;
}


/*
search for the letter 's' with stand for starting point
@param the array store the maze
@param the row
@param the collumn
*/

Point searchForStart(char **arr,int ROW, int COL)//, int &curX, int &curY
{

    for(int i =0; i<ROW; i++)
    {
        for(int j =0; j<COL; j++)
        {
            if( arr[i][j] == 's')
            {
                arr[i][j]= 's';
                return Point(i,j);
            }
        }
    }
}

/*
move the character
@param 1choice the direction
@param 2 the array store the maze
@param 3 the x location of the character
@param 3 the y location of the character
*/
void moving(int choice2, char **arr, int &curX, int &curY)
{

    arr[curX][curY]='.';
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
    if (choice2==5)
    {
        //should move backward
    }

    if(arr[curX][curY]=='f')
    {

    }
    else
    {
        arr[curX][curY]='s';
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
bool checkSpace(char **arr, int curX, int curY)

{
    if (curX <0 || curY<0||arr[curX][curY]=='.'||arr[curX][curY]=='*')
    {
        return false;
    }
    if (arr[curX][curY]== ' '  ||arr[curX][curY]== 'f')
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
bool checkFinish(char **arr, int curX, int curY)
{
    if (arr[curX][curY]== 'f')
    {
        cout<<"===================YOU WON======================"<<endl;
        return  false;
    }

    return true;
}

/*
use dfs to find the path
@param1 the stack
@param2 the array that store the maze
*/
bool mazeSolvingAlgorithmDFS( stack<Point> &points, char **arr)//,int &curX, int &curY
{

    int curX=points.top().getX() ;
    int  curY=points.top().getY();
    cout<<"CUR X: "<<curX<<endl;
    cout<<"CUR Y: "<<curY<<endl;
    //points.pop();
    if(arr[curX][curY] =='f')
    {
        //return Point(curX,curY);
        return true;
    }
    else
    {
        //arr[curX][curY]='.';

        if(checkSpace(arr,curX-1,curY)==true) //up
        {


            moving(1,arr,curX,curY);
            points.push(Point(curX,curY));


        }
        else if(checkSpace(arr,curX+1,curY)==true) //down
        {

            moving(2,arr,curX,curY);
            points.push(Point(curX,curY));

        }
        else if(checkSpace(arr,curX,curY-1)==true) //left
        {


            moving(3,arr,curX,curY);
            points.push(Point(curX,curY));

        }
        else if(checkSpace(arr,curX,curY+1)==true) //right
        {


            moving(4,arr,curX,curY);
            points.push(Point(curX,curY));

        }

        else //how to move backward?
        {
            points.pop();
            Point temp = points.top();
            arr[curX][curY]='.';
            curX=temp.getX();
            curY=temp.getY();

        }

        return false;
    }
}



/*
dfs method
@param1 the point
@param2 the row
@param3 the collumn
@param4 the stack to store where the character have passed
*/
void dfs(Point p, char**arr, int ROW, int COL, stack<Point> &points )
{
    int curX = p.getX();
    int curY = p.getY();
    bool play4 =false;
    while (play4 ==false)
    {
        displayMaze(arr,ROW,COL);
        cout<<endl;
        play4= mazeSolvingAlgorithmDFS(points,arr);//,curX,curY
    }
}

bool mazeSolvingAlgorithmBFS( queue<Point> &deq, char **arr)//,int &curX, int &curY
{
    int curX=deq.back().getX() ;
    int  curY=deq.back().getY();

    //points.pop();
    if(arr[curX][curY] =='f')
    {

       return true;
    }

    else
    {
        //arr[curX][curY]='.';
        int s = deq.size();
        int x = curX;
        int y = curY;

            cout<<" X: "<<x<<endl;
            cout<<" Y: "<<y<<endl;
            cout<<"Problem:"<<arr[x-1][y]<<endl;
        if(checkSpace(arr,x-1,y)==true) //up
        {

            curX= x;
            curY = y;
             cout<<"CUR X: "<<curX<<endl;
            cout<<"CUR Y: "<<curY<<endl;
            moving(1,arr,curX,curY);
            //deq.push_back(Point(curX,curY));


        }
        /*
         if(checkSpace(arr,x+1,y)==true) //down
        {
            curX= x;
            curY = y;
            moving(2,arr,curX,curY);
            deq.push_back(Point(curX,curY));

        }
*/
         if(checkSpace(arr,x,y-1)==true) //left
        {


            curX= x;
            curY = y;
            cout<<"NEW CUR X: "<<curX<<endl;
            cout<<"NEW CUR Y: "<<curY<<endl;
            moving(3,arr,curX,curY);
            //deq.push_back(Point(curX,curY));

        }
/*
         if(checkSpace(arr,x,y+1)==true) //right
        {

            curX= x;
            curY = y;
            moving(4,arr,curX,curY);
            deq.push_back(Point(curX,curY));

        }

        else //how to move backward?
        {
            points.pop();
            Point temp = points.top();
            arr[curX][curY]='.';
            curX=temp.getX();
            curY=temp.getY();

        }

        */

        return false;
    }






}
void bfs(Point p, char**arr, int ROW, int COL, queue<Point> &deq)
{
 int curX = p.getX();
    int curY = p.getY();
    bool play4 =false;
    while (play4 ==false)
    {
        displayMaze(arr,ROW,COL);
        cout<<endl;
        play4= mazeSolvingAlgorithmBFS(deq,arr);//,curX,curY
    }
}
int main()
{

    /*

    for(int i = 0; i < ROW; i++)
        delete arr[i];
    delete arr;
    return 0;
    */







    stack<Point> points;
    queue<Point> deq;
    bool play = true;
    while (play)
    {
        displayMazeMenu();
        int choice = validate(1,5);
        int ROW = findRow(choice);
        int COL = findCol(choice);
        cout<<"ROW:"<<findRow(choice)<<endl;
        cout<<"COL:"<<findCol(choice)<<endl;
        char** arr = new char*[ROW];
        for(int i = 0; i < ROW; ++i)
        {
            arr[i] = new char[COL];

        }
        arr= readMaze(choice, ROW, COL);

        bool play2 = true;
        while(play2)
        {
            Point p(0,0);
            p = searchForStart(arr,ROW,COL);
            points.push(p);
            //deq.push_back(p);


            solvingMethodMenu();
            int choice2 = validate(1,4);
            if(choice2== 1)
            {
                dfs(p, arr,  ROW,  COL, points );

            }
            if(choice2== 2)
            {
                 bfs(p, arr,  ROW,  COL, deq );






            }
            if(choice2== 3) //solve it yourself
            {


                int curX = p.getX();
                int curY = p.getY();
                bool play3= true;
                while(play3)
                {

                    cout<<"Location: "<<curX<<","<<curY<<endl;
                    displayMaze(arr,ROW,COL);

                    displayDirectionMenu();
                    int choice3=validate(1,5);

                    if(choice3==1) //up
                    {
                        int nextMoveX = curX-1;
                        int nextMoveY = curY;

                        if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                        {

                            moving(choice3,arr,curX,curY);
                            play3=checkFinish(arr, curX, curY);

                        }
                        else
                        {
                            cout<<"CANNOT MOVE INTO WALL"<<endl;
                        }
                    }
                    if(choice3==2) //down
                    {
                        int nextMoveX = curX+1;
                        int nextMoveY = curY;
                        if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                        {

                            moving(choice3,arr,curX,curY);
                            play3=checkFinish(arr, curX, curY);

                        }
                        else
                        {
                            cout<<"CANNOT MOVE INTO WALL"<<endl;
                        }

                    }
                    if(choice3==3) //left
                    {
                        int nextMoveX = curX;
                        int nextMoveY = curY-1;
                        if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                        {


                            moving(choice3,arr,curX,curY);
                            play3=checkFinish(arr, curX, curY);

                        }
                        else
                        {
                            cout<<"CANNOT MOVE INTO WALL"<<endl;
                        }
                    }
                    if(choice3==4) //right
                    {
                        int nextMoveX = curX;
                        int nextMoveY = curY+1;
                        if (checkSpace(arr,nextMoveX,nextMoveY)== true)
                        {

                            moving(choice3,arr,curX,curY);
                            play3=checkFinish(arr, curX, curY);
                        }
                        else
                        {
                            cout<<"CANNOT MOVE INTO WALL"<<endl;
                        }
                    }
                    if (choice3==5){
                        Point p(0,0);
                        p = searchForStart(arr,ROW,COL);
                        points.push(p);
                        dfs(p, arr,  ROW,  COL, points );
                    }


                }


            }

            if(choice2== 4)
            {
                play2 = false;

            }


        }
    }


}

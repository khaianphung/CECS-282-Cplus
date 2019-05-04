#include <iostream>
#include <vector>
using namespace std;

/*
reset the canvas to all zeros
@param1 the size of the array
@param2 the using number of elements
@return int[pointer][pointer] the array
*/
void resetCanvas(int canvas[30][30],int &SIZE)
{

    for (int i =0; i< SIZE; i++)
    {
        for (int j =0; j< SIZE; j++)
        {
            canvas[i][j]= 0 ;
        }
    }


}

/*display the canvas
@param 1 the array
@param 2 the size of the array
@param 3 the using number of element
*/

void displayCanvas(int canvas[30][30],int &SIZE)
{

    for (int i =0; i< SIZE; i++)
    {
        for (int j =0; j< SIZE; j++)
        {
            cout<<canvas[i][j]<< ((j%30 == 29) ? ("\n") : (""));
        }
    }

}

/*check if input if legit
@param1 beginnning limiter
@param2 ending limiter
*/
int checkInput(int start, int endi)
{
    int input = 0;
    bool fail= true;

    while (fail)
    {

        // cout<<"Enter a number: "<<endl;
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


/*create rectangle structure
*/
struct Rectangle
{
    int xLoc;
    int yLoc;
    int width;
    int height;


};

/*
show the rectangle on the canvas
@param1: the structure rectangle
@param2: the canvas array
@param3 the size of the array
@param4 the number of element used
@param5 which rectangle is that?
*/
void editRectangle( Rectangle &b, int canvas[30][30],int &SIZE, int which)
{

    for (int i =b.xLoc; i< b.xLoc+b.width; i++)
    {
        for (int j =b.yLoc; j< b.yLoc+b.height; j++)
        {
            canvas[i][j]=which;

        }
    }


}



/*create the rectangle by input needed infor
*/
Rectangle createRectangle( )
{


    cout<< "Enter width:";
    int wid = checkInput(0,30);
    cout<< "Enter height:";
    int hei = checkInput (0,30);
    cout<< "Enter X Loc:";
    int xLoc = checkInput(0,30-hei);
    cout<< "Enter Y Loc:";
    int yLoc = checkInput(0,30-wid);
    Rectangle b = {yLoc,xLoc, hei, wid };
    return b;
}

/*resize the rectangle
@param1 the rectangle object
@param2 the canvas array
*/
void resizing(Rectangle &b,  int canvas[30][30],  Rectangle recArr[], int quantity, int SIZE, int which)
{
    resetCanvas(canvas,SIZE);
    for (int i =0; i<quantity; i++)
    {
        if (i == which-1 )
        {
            cout<< "Enter width:";
            int widthNew = checkInput(1,30);
            if (widthNew+b.xLoc > 30)
            {
                cout<<"Invalid input: "<<endl;
                widthNew = checkInput(1,30-widthNew);
            }
            cout<< "Enter height:";
            int heightNew = checkInput(1,30);
            if (heightNew+b.xLoc > 30)
            {
                cout<<"Invalid input: "<<endl;
                heightNew = checkInput(1,30-heightNew);
            }
            b.width = heightNew;
            b.height = widthNew;
        }
        //recArr[i]=createRectangle();
        editRectangle(recArr[i], canvas,SIZE,i+1);
        //displayCanvas(canvas,SIZE);
    }

    /*
    for (int i =b.xLoc; i< b.xLoc+b.width; i++)
    {
        for (int j =b.yLoc; j< b.yLoc+b.height; j++)
        {
            canvas[i][j]=0;

        }
    }
    */



}

/*translate the rectangle
@param1 the rectangle object
@param2 the canvas array
*/
void translate(Rectangle &b,  int canvas[30][30],  Rectangle recArr[], int quantity, int SIZE, int which)
{
    resetCanvas(canvas, SIZE);
    for (int i =0; i<quantity; i++)
    {
        if (i == which-1)
        {
            cout<< "Enter X increment:";
            int xNew = checkInput(0,30-b.width+1);
            cout<< "Enter Y increment:";
            int yNew = checkInput(0,30-b.height+1);
            recArr[i].xLoc = recArr[i].xLoc+xNew;
            recArr[i].yLoc = recArr[i].yLoc+yNew;
        }
        //recArr[i]=createRectangle();
        editRectangle(recArr[i], canvas,SIZE,i+1);
        //displayCanvas(canvas,SIZE,elNum);
    }
    /*
    for (int i =b.xLoc; i< b.xLoc+b.width; i++)
    {
        for (int j =b.yLoc; j< b.yLoc+b.height; j++)
        {
            canvas[i][j]=0;

        }
    }
    */

}


int main()
{
    int SIZE = 30;

    int canvas[30][30];
    resetCanvas(canvas,SIZE);


    cout<<"Enter number of rectangle(1-5): "<<endl;
    int quantity = checkInput(1,5);
    Rectangle recArr[quantity];

    for (int i =0; i<quantity; i++)
    {

        recArr[i]=createRectangle();
        editRectangle(recArr[i], canvas,SIZE,i+1);
        displayCanvas(canvas,SIZE);
    }

    bool play = true;
    ///////////////////////
    while(play)
    {
        cout<<"Option "<<endl;
        cout<<"1.Translate rectangle"<<endl;
        cout<<"2.Resize rectangle "<<endl;
        cout<<"3.Quit "<<endl;
        int choice = checkInput(1,3);
        switch(choice)
        {
        case 1:
        {
            cout<<"Which rectangle in "<<quantity<<"?"<<endl;
            int which = checkInput(1,quantity);
            translate(recArr[which-1],canvas,recArr, quantity,SIZE, which);
            editRectangle(recArr[which-1], canvas,SIZE, which);
            displayCanvas(canvas,SIZE);
            break;
        }
        case 2:
        {
            cout<<"Which rectangle in "<<quantity<<"?"<<endl;
            int which = checkInput(1,quantity);
            resizing(recArr[which-1],canvas,recArr, quantity,SIZE, which);
            editRectangle(recArr[which-1], canvas,SIZE, which);
            displayCanvas(canvas,SIZE);
            break;
        }
        case 3:
        {
            play = false;
            break;
        }
        default:
        {
            break;
        }
        }

    }

    return 0;
}

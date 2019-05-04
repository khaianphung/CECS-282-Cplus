#include <iostream>
#include <stack>
#include <fstream>
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


/*
read the  text file
@param1 the stack  to store the data
@param2 file name
*/
void readFile(stack<string> &s,string fileName)
{

    fstream file;
    string input;
    file.open(fileName.c_str(), ios::in);//have to use c string because it only accept cstring
    if( file)
    {
        while( getline(file, input) )
        {
            cout << input << endl;
            s.push(input);
        }
        file.close();
    }
    else
    {
        cout << "Could Not Open File."<< endl;
    }
}

/*
display the data in reversed order
@param1  the stack to store the data

*/
void displayReversed(stack<string> &s)
{

    stack<string> tempStack;

    fstream file;
    file.open("reversed.txt", ios::out | ios::app);
    if(file){
        file<<"Write reversed into a file" <<endl;
        while( !s.empty( ) )
    {
        string item = s.top();
        cout<<item<<endl;
        file<<item<<" ";
        s.pop( );
        tempStack.push(item);

    }
    file.close();
    } else{
    cout<<"Error Opening File"<<endl;
    }
}



void menu()
{
    cout<<"Menu"<<endl;
    cout<<"1.Read text file"<<endl;
    cout<<"2.Store reverse in file"<<endl;
    cout<<"3.Quit"<<endl;
}

int main()
{
    stack<string> values;
    bool play = true;
    while (play)
    {
        menu();
        int choice  = validate(1,4);
        if ( choice == 1)
        {
            readFile(values,"file.txt");
        }
        if ( choice == 2)
        {
            displayReversed(values);
        }
        if ( choice == 3)
        {
            play = false;
        }
    }
    return 0;
}

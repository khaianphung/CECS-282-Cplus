#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include <cstdlib>
using namespace std;



/*
create the dynamic array with zeroes
@return the dynamic array
*/
int *initializeArray(int &SIZE, int &elNum)
{


    int *dArray = new int[SIZE];
    for (int i = 0; i<SIZE; i++)
    {

        dArray[i] = 0;

    }
    return dArray;

}

/*Display the dynamic array
*/
void displayArray(int *arr,int &SIZE, int &elNum)
{
    for (int i = 0; i<SIZE; i++)
    {

        cout<<arr[i]<<" ";

    }
}

/*
double the size of the dynamic array
@param 1 : the dynamic array

*/
void increaseSize(int *&dArray,int &SIZE, int &elNum)
{
    SIZE = SIZE+1;
    int * tempArr = new int[SIZE];
    for (int i = 0; i < elNum; i++)
    {
        tempArr[i] = dArray[i];
    }

    delete[] dArray;
    dArray = tempArr;
    //initializeArray(SIZE,elNum );

}

/*
add the value at the end of the array
@param1 : the number to add
@param2 : the dynamic array
*/
void addValue(int num, int *&dArray,int &SIZE, int &elNum)
{
    if (elNum >= SIZE)
    {
        increaseSize(dArray,SIZE, elNum);
    }
    dArray[elNum] = num;
    elNum++;
}




/*
insrt the element into the array
@param 1: the numberto insert
@param 2: the index you want to insert
@param 3: the dynamic array
*/
void inserting(int num, int index, int*&dArray,int &SIZE, int &elNum)
{

    if (elNum >= SIZE)
    {
        increaseSize(dArray,SIZE, elNum);
    }
    for(int i = 0; i<elNum; i++)
    {

        if (i == index)
        {
            for(; i<elNum; i++)
            {
                dArray[i+1] = dArray[i];
            }

        }

    }
    dArray[index] = num;
    elNum++;
}

/*
remove the element from the array
@param1 : the index you want to remove
@param2 : the dynamic array
*/
void removing(int index, int *&dArray,int &SIZE, int &elNum)
{
    for(int i = 0; i<elNum; i++)
    {
        if (i == index)
        {

            for(; i<elNum; i++)
            {
                dArray[i] = dArray[i+1];
            }

        }


    }
    elNum--;

}

/*
swap 2 element
@param1 : first element
@param2 : second element
@param3 : the dynamic array
*/
void swapping(int a, int b,int *&dArray)
{
    int swapi = a;
        a = b;
        b = swapi;

}

/*
sort the array

@param  the dynamic array
*/
void selectionSort( int *&dArray ,int &SIZE, int &elNum)
{
    cout<<"SIZE: "<<SIZE<<endl;
    for(int i=0; i < elNum; i++)
    {
        int lowest = i;
        for( int j= i +1; j< elNum; j++)
        {
            if( dArray[j] < dArray[lowest])
            {
                lowest = j;
            }
        }//cout<<dArray[lowest];

        int swapi = dArray[i];
        dArray[i] = dArray[lowest];
        dArray[lowest] = swapi;

    }
}


/*
validate the input
@param1 : start integer
@param2 : end integer
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
}


/*
read the datas from the file
@param1 the dynamic array
*/
void reading(int *&dArray,int &SIZE, int &elNum)
{

    cout<<"Enter file to read: "<<endl;
    cout<<"File 1"<<endl;
    cout<<"File 2"<<endl;
    cout<<"File 3"<<endl;
    int choice = validate(1,3);


    ifstream file;
    if (choice==1)
    {
        cout<<"File 1: "<<endl;
        file.open ("file1.txt");
    }
    if (choice==2)
    {
        cout<<"File 2: "<<endl;
        file.open ("file2.txt");
    }
    if (choice==3)
    {
        cout<<"File 3: "<<endl;
        file.open ("file3.txt");
    }


    string input ;
    string line = " ";

    if( file)
    {
        while( getline(file, input, '-') )
        {
            int a = atoi(input.c_str());
            cout<<a<< " ";
            addValue(a,dArray,SIZE, elNum);

        }
        file.close();
    }
    else
    {
        cout << "Could Not Open File."<< endl;
    }

}

void reset(int *&dArray){
 delete[] dArray;
     dArray = NULL;
}
int main()
{
    int SIZE = 10;
    int elNum = 0;
    int *arr= initializeArray(SIZE,elNum );

    bool play = true;
    while (play)
    {
        cout<<"Menu: "<<endl;
        cout<<"1.Add from file "<<endl;
        cout<<"2.Display content "<<endl;
        cout<<"3.Add new value to end "<<endl;
        cout<<"4.Insert new value"<<endl;
        cout<<"5.Sort value "<<endl;
        cout<<"6.Remove value"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"8.Reset"<<endl;
        int choice = validate(1,8);
        switch(choice)
        {
        case 1:
        {
            reading(arr,SIZE, elNum);

            break;
        }
        case 2:
        {
            displayArray(arr,SIZE,elNum);
            break;
        }
        case 3:
        {
            cout<<"Enter value to add:";
            int num = validate(-99999,99999);
            addValue(num,arr,SIZE,elNum);
            break;
        }
        case 4:
        {
            cout<<"Enter value to add:";
            int num = validate(-99999,99999);
            cout<<"Enter index, must be less than "<<elNum<<":" ;
            int index = validate(0,elNum);
            inserting(num, index, arr,SIZE, elNum);
            break;
        }
        case 5:
        {
            selectionSort(arr, elNum,SIZE);
            displayArray(arr,SIZE, elNum);
            break;
        }
        case 6:
        {
            cout<<"Enter index, must be less than "<<elNum<<":" ;
            int index = validate(-1,elNum);
            removing(index,arr,SIZE, elNum);
            break;
        }
        case 7:
        {
            play= false;
            break;
        }
        case 8:
        {
            reset(arr);
            break;
        }

        }
    }




delete[] arr;
     arr = NULL;
    return 0;
}

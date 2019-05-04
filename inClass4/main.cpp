
#include <iostream>//scanner
#include <cstdlib>
#include <ctime>//to use random
#include <string>
#include <sstream>
#include<string.h>
#include <vector>
using namespace std;

/*find the valid input for menu
@return the valid input
*/
int checkMenuInput()
{
    int input = 0;
    bool fail= true;

    while (fail)
    {

        cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input<= 6 && input>=1 )
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
print out the vector in unsorted format
@param1 vector v1 of words

*/
void printVector(vector <string> &v1)
{

    for (int i=0; i<(int)v1.size(); i++)
    {
        cout<<v1[i]<<" ";
        if(i+1 %5 == 0){
            cout<<endl;
        }
    }
}

/*
print out the vector in sorted format
@param1 vector v1 of words

*/
void selectionSort( vector <string> &list)
{
    for (int i=0; i< (int)list.size(); i++)
    {
        int lowest = i;
        for (int j= i +1 ; j<(int)list.size(); j++)
        {
            if(list[j].compare(list[lowest])<0)
            {
                lowest = j;
            }
        }
        string swap = list[i];
        list[i] = list[lowest];
        list[lowest]= swap;
    }
}

/*
print out the size of the vector
@param1 vector v1 of words
@return the size

*/
int findSize(vector <string> &v1){
return (int) v1.size();
}

/*
print out the frequency of a word in the vector
@param1 vector v1 of words
@return the frequency of a word

*/
int findFrequency(vector <string> &v1){
cout<<"Enter a word to find its frequency in vector: "<<endl;
            string datWord;
            cin >> datWord;
            int frequency = 0;
            for (int i = 0; i <(int)v1.size(); i++)
            {
                if(v1[i] == datWord)
                {
                    frequency++;
                }
            }
            return frequency;
}

/*
find a word in the vector
@param1 vector v1 of words
@return int output that says whether it found the word

*/
int findWord(vector <string> &v1){
cout<<"Enter a word to find : "<<endl;
            string datWord;
            cin >> datWord;

            for (int i = 0; i <(int)v1.size(); i++)
            {
                if(v1[i] == datWord)
                {
                    return i;

                }


            }
            return -1;
}
int main()
{

    string word;
    vector<string> v;
    vector <string> v1;
    bool play= true;

    cout<<"Populate Vector "<<endl;
    bool inProgress= true;
    while (inProgress)
    {
        cout<<"Enter word: "<<endl;
        cin>>word;
        if (word == "q"){
            break;
        }
        v.push_back(word);
        v1.push_back(word);
    }


    while (play)
    {
        cout<<"Menu Options "<<endl;
        cout<<"1.Display unsorted list"<<endl;
        cout<<"2.Display sorted list"<<endl;
        cout<<"3.Display number of words"<<endl;
        cout<<"4.Frequency of a word"<<endl;
        cout<<"5.Find word"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<endl;
        cout<<"Choose an option: ";
        int choose;
        choose = checkMenuInput();


        switch (choose)
        {
        case 1:
        {
            printVector(v);
            break;
        }
        case 2:
        {

            selectionSort(v1);
            printVector(v1);
            break;
        }
        case 3:
        {
            cout<<"The number of word is : "<<findSize(v1)<<endl;
            break;
        }

        case 4:
        {

            cout<<"Its frequency is: "<<findFrequency(v1)<<endl;
            break;
        }

        case 5:
        {
            int location = findWord(v1);

            if (location != -1){
                cout<<"Word Found at: "<<location<<endl;
            }
            else if (location == -1){
             cout<<"Word not found"<<endl;
            }
        break;
        }

        case 6:
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

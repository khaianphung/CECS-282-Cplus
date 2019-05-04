#include <iostream>

using namespace std;

void inputRange()
{

    cout<<"Enter upper bound: "<<endl;
    int upper;
    cin>>upper;
    cout<<"Enter lower bound: "<<endl;
    int lower;
    cin>>lower;
}

int checkRange(){
    inputRange();
    int input = 0;
    bool fail= true;
    int i =0 ;
    while (fail)
    {
        cout<<"Index "<<i<<endl;

        cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input<= upper && input>=lower )
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

i++;
    }


    return input;

}

void filling(int ar[]){

    for (int i =0 ; i<10; i++)
    {
        ar[i]=checkRange();
    }

}

void menu()
{
    cout<<"Menu: "<<endl;
    cout<<"1.Display Numbers"<<endl;
    cout<<"2.Display Reversed"<<endl;
    cout<<"3.Display Sum"<<endl;
    cout<<"4.Display Average"<<endl;
    cout<<"5.Display Maximum"<<endl;
    cout<<"6.Search for a Value"<<endl;
    cout<<"7.Quit"<<endl;
}

int  validate()
{
    int input = 0;
    bool fail= true;
    while (fail)
    {
        cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input<= 7 && input>=1 )
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

void display(int ar[])
{
    cout<<"Display Array:"<<endl;
    for (int i=0; i<sizeof(ar); i++)
    {
        cout << " [" << ar[i] <<"]"  ;
    }
    cout<<endl;

}

void displayReverse(int ar[])
{
    cout<<"Reverse Array: "<<endl;
    for (int i=sizeof(ar)-1; i>=0; i--)
    {
        cout << " [" << ar[i] <<"]" ;
    }

}

void sum(int ar[])
{

    cout<<"Display Sum:"<<endl;
    int sum =0;
    for(int i =0; i<sizeof(ar); i++)
    {
        sum +=ar[i];
    }
    cout<<"The sum is : "<<sum;
    cout<<endl;
}

void average(int ar[])
{
    int sum=0;
    for(int i =0; i<sizeof(ar); i++)
    {
        sum +=ar[i];
    }
    cout<<"Display Average: "<<endl;
    double average = sum / sizeof(ar);
    cout<<"The average: "<<average<<endl;
    cout<<endl;
}

void maximum(int ar[])
{
    int maxi=ar[0];
    for(int i =0; i<sizeof(ar); i++)
    {
        if(ar[i]>maxi)
        {
            maxi = ar[i];
        }

    }
    cout<<"The max is: "<<maxi;
    cout<<endl;

}

void finding(int ar[])
{
    int maxi=ar[0];
    for(int i =0; i<sizeof(ar); i++)
    {
        if(ar[i]>maxi)
        {
            maxi = ar[i];
        }

    }
    cout<<"The max is: "<<maxi;
    cout<<endl;
}
int main()
{
    int ar[10];

    filling(ar);
    bool play =true;
    while (play)
    {

        menu();
        int option;
        cout<<"Enter an option: ";

        validate();


        switch(option)
        {
        case 1:
        {
            display(ar);
            break;


        }

        case 2:
        {
            displayReverse(ar);
            break;

        }

        case 3:
        {
            sum(ar);
            break;
        }

        case 4:
        {
            average(ar);
            break;
        }

        case 5:
        {
            maximum(ar);
            break;
        }

        case 6:
        {
            finding(ar);
            break;
        }
        case 7:
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






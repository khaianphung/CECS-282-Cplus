/*
Khai Phung
013234752
CECS 282
Professor Shannon
*/
#include <iostream>
#include <iomanip>
using namespace std;

/*
Calculate the subtotal by  adding the price of ham, soda and french fries
@param h number of ham
@param s number of soda
@param f number of french fries
*/


double getSubTotal(double price, int quantity)
{

    return price * quantity;
}

/*
Calculate the tax by multiply the subtotal with 0.09
@param subtotal is the subtotal
*/
double getTax (double subTotal)
{
    double tax = subTotal*0.09;
    return tax;
}

/*
Calculate the total by substract the tax from the subtotal
@param1 subtotal is the subtotal
@param2 tax is the tax after reduction

*/
double totalCalc (double subTotal, double tax)
{
    double total = subTotal - tax;

    return total;
}

/*
display the menu

*/
void menu()
{
    cout<<"MacDoogle's:"<<endl;//Menu
    cout<<"1. Hamburger = $1.50"<<endl;
    cout<<"2. Soda      = $1.15"<<endl;
    cout<<"3. Fries     = $1.25"<<endl;
    cout<<"4. Complete Order."<<endl;
}

/*validate the input if it's in range and is an int
return int values */
int validateMenu()
{
    int input = 0;
    bool fail= true;
    while (fail)
    {
        cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input<= 4 && input>=1 )
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
/*validate the input if it's in range and is an int
@return int value*/
int qtyVal()
{
    int input = 0;
    bool fail= true;
    while (fail)
    {
        cout<<"Enter a number: "<<endl;
        if (cin >> input)
        {
            if (input > 0 )
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

/*vaccumulate the subtotal
@param 1 = money of the order right now
@param 2 = subtotal right now
@return double value
*/
double accum(double cash, double sub)
{
    double subtotal = sub;
    subtotal += cash;
    return subtotal;

}
/*
display the final menu
@param1 qty: the total nunmber of items
@param2 subTotal : the total money after tax
@param3 tax : the tax
*/
void receipt(int qty, double subTotal, double tax)
{
// calculate the tax
cout<<"+---------------------+"<<endl;
    cout<<"|Welcome to MacDoogles|"<<endl;
    cout<<"|# of Items: "<<qty<<"        |"<<endl;
    std::cout<<"|Subtotal  : $"<<subTotal<<"    |"<<endl;
    std::cout<<"|TAX       : $"<<tax<<"    |"<<endl;
    std::cout<<"|Total Cost: $"<<totalCalc(subTotal,tax)<<"    |"<<endl;//calculate the total
    cout<<"|Enjoy Your Meal! "<<"    |"<<endl;
    cout<<"|Have a MacDoogle Day!"<<"|"<<endl;
cout<<"+---------------------+"<<endl;

}
int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);//set the decimal point to 2
    int subTotal=0,qty=0;//initialize
    bool play = true;// to end when user enter 4
    while(play)
    {

        menu();



        int choice = validateMenu();






        switch(choice)
        {
        case 1://when user wants hamburger
        {
            cout<<"Enter the number of hamburgers"<<endl;
            int h = qtyVal();
            subTotal += getSubTotal(1.5, h);
            qty += h;
            break;
        }
        case 2:
        {
            cout<<"Enter the number of sodas"<<endl;//when user wants soda
            int s = qtyVal();

            subTotal += getSubTotal(1.15,s);
            qty += s;
            break;
        }

        case 3:
        {
            cout<<"Enter the number of fries"<<endl;
            int f = qtyVal();

            subTotal += getSubTotal(1.25,f);
            qty += f;
            break;
        }

        case 4:
        {
            double tax =getTax(subTotal);

            receipt(qty, subTotal, tax);
            play = false;//end the program



        }
        default:
        {
            break;
        }
        }

    }
    return 0;
}




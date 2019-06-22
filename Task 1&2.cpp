#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

    int NumItem;
    string Desc;
    double Price;
    int buyerNum;
	int bidProd;
	double bidPrice;
	bool cond = true;
	char choice = 'Y';


int main()
{

    while(NumItem<10)   // fetching number of products to be auctioned
    {
        std::cout << "Please enter the number of items to be auctioned \n Must be greater than 10: " << std::endl;
        std::cin >> NumItem;
    }

    int ItemNumber[NumItem];    //Declaring arrays
    double ReservePrice[NumItem];
    string ProductDescription[NumItem];
    double MaxBid[NumItem];
    int numOfBids[NumItem];
    int buyerOfProd[NumItem];

   for(int counter=0 ; counter<NumItem ; counter++)
    {
        ItemNumber[counter] = {counter}; // automatically assigns unique number to each Product
        cout << "Please enter product description of  item: " << counter << endl;
        cin >> Desc;
        ProductDescription[counter] = {Desc}; // assigns product description to each ItemNumber
        cout << "Please enter reserve price of item: " << counter << endl;
        cin >> Price;
        ReservePrice[counter] = {Price}; // assigns price to each ItemNumber

    }
     while(cond == true)
	{
		for(int i = 0 ; i<NumItem ; i++)
		{
			cout << ItemNumber[i] << "      " << ProductDescription[i] << "     " << ReservePrice[i] << endl;
		}
		cout << "Do you want to bid?[Y/N]" << endl;
		cin >> choice;
		choice = putchar(toupper(choice));
		if(choice == 'Y')
		{
			cout << "Please enter  buyer number: " << endl;
			cin >> buyerNum;
			cout << "Please enter product number of item you want to bid on: " << endl;
			cin >> bidProd;
			cout << "Please enter a bid greater than $" << MaxBid[bidProd] << endl;
			cin >> bidPrice;
			if (bidPrice>MaxBid[bidProd])
			{
				MaxBid[bidProd] = bidPrice;
				numOfBids[bidProd]++;
			}
			else
			{
				cout << "Enter a bid greater than $" << MaxBid[bidProd] << endl;
			}
		}
		else if (choice == 'N')
		{
			cond = false;
		}
	}

}

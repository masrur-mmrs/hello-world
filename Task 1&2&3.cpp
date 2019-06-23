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
	int Sold;
	int NotSold;
	int NoBid;
	double bidPrice;
	bool cond = true;
	char choice = 'Y';


int main()
{
	/*
		
		TASK_1
		
	*/

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
    double total[NumItem];
	string Status[NumItem];

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
    /*
		
		TASK_2
		
	*/
	for (int i = 0; i < NumItem; i++) // initialises maximum bid of every item //
		{
			MaxBid[i]={0};
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
		cout << endl;
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
			if (MaxBid[bidProd]>=ReservePrice[bidProd])
			{
			buyerOfProd[bidProd] = buyerNum;
			}
		}
		else if (choice == 'N')
		{
			cond = false;
		}
	}
	/*
		
		TASK_3
		
	*/

	for (int i = 0; i < NumItem; ++i)
	{
		if (MaxBid[i]>=ReservePrice[i])
		{
			total[i] = MaxBid[i]*1.1;
			Sold++;
			Status[i] = "Sold";
			cout << "Item #" << ItemNumber[i] << " is sold to buyer number #" << buyerOfProd[i] << " for $" << total[i] << endl;
		}
		else if (MaxBid[i]>0 && MaxBid[i]<ReservePrice[i])
		{
			NotSold++;
			Status[i]="Not Sold";
			cout << "Item #" << ItemNumber[i] << " couldn't reach its reserve price." << endl;
		}
		else if (MaxBid[i]==0)
		{
			NoBid++;
			Status[i] = "No Bid";
			cout << "Item #" << ItemNumber[i] << " didn't recieve any bids." << endl;
		}
	}
	cout << setw(30) << "SUMMARY" << setw(30) << endl;
	cout << setw(30) << "Items sold: " << Sold << setw(30) << endl;
	cout << setw(30) << "Items that could'nt reach reserve price: " << NotSold << setw(30) << endl;
	cout << setw(30) << "Items with no bids: " << NoBid <<setw(30) << endl;

}

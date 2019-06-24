#include <iostream>

using namespace std;


int main()
{
    while(true)
    {
    float a;
    float b = 1;
    float n;

    cout << "Please enter value of n" << endl;
    cin >> n;

    a=1+(1/n);

    for(int counter = 0 ; counter<n ; counter++)
    {
        b*=a;
    }

    cout << b << endl;
    }
    return 0;
}

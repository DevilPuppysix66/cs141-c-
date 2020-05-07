#include<iostream>
#include<string>

using namespace std;


int outputs(float[]);
float prices[10] = {0};
string product;



int main()
{
	cout << "welcome to the price finder program.";
	while(1 == 1)
	{
		for(int x = 0; x < 10; x++)
                {
                        prices[x] = 0;
                }

		cout << "\n\nEnter a product name: ";
		cin >> product;

		if(product == "DONE")
		{
			cout << "\nThank you for using the program\n";
			break;
		} 
		for(int x = 0; x < 10; x++)
		{
			cout << "Enter price: ";
			cin >> prices[x];
			if(prices[x]== -1)
				break;
		}
		outputs(prices);
	}
	
	
	
	
	return 0;
}

int outputs(float prices[])
{
	float max = 0;
	float min ;
	float num = 0;
	float range = 0;
	float ave = 0;
	for(int x = 0; x < 10; x++)
        {
                if(prices[x] > 0)
               	{
			if(x == 0)
				min = prices[x];
			num = num+1;
			ave = ave + prices[x];

			if(prices[x] > max)
				max = prices[x];
			if(prices[x] < min)
				min = prices[x];
		}	
	}
	ave = ave / num;
	range = max - min;
	if(num == 0)
		ave = 0;	
	cout << "\nNumber of valid prices: " << num;
	cout << "\nMaximum: $" << max;
	cout << "\nMinimum: $" << min;
	cout << "\nRange: $" << range;
	cout << "\nAverage: $" << ave;

	return 0;
}

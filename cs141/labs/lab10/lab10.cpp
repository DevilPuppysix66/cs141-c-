#include<iostream>
#include<string>
#include<fstream>

using namespace std;



struct Location
{
	string BuildingName;
	int FloorLevel;

};

struct Drink
{
	string DrinkName;
	float DrinkSize;
	float DrinkPrice;

};

struct VendingMachine
{
	Location location;
	Drink drinks[10];

};
              
int main()
{
	VendingMachine AllVendingMachines[5];
	ifstream indata;
	int i = 0;
	int j = 0;
	indata.open("vendingmachinedata.txt");


	while(indata >> AllVendingMachines[i].location.BuildingName >> AllVendingMachines[i].location.FloorLevel >> AllVendingMachines[i].drinks[j].DrinkName >> 
			AllVendingMachines[i].drinks[j].DrinkSize >> AllVendingMachines[i].drinks[j].DrinkPrice) 
		{
			j++;
			if(j == 10)
			{
				i++;
				j = 0;
			}
		}
	
	while(1)
	{
		string choice;
        	string buildingname;
        	int floorlevel;
        	string drinkname;
        	float drinksize;
		int x = 1;
		cout << "\nMenu options include:\nBUY(enter data to purchase drink)\nSHOW(all invetories)\nEXIT(exits program)\n";
		cin >> choice;
		if(choice == "BUY")
		{
			cout << "Please enter building name, floor level, drink name and drink size\n";
			cin >> buildingname >> floorlevel >> drinkname >> drinksize;
	                for(i = 0; i < 5; i++)
	                {
	                        for(j = 0; j < 10; j++)
	                        {
	                                if(AllVendingMachines[i].location.BuildingName == buildingname && AllVendingMachines[i].location.FloorLevel == floorlevel && AllVendingMachines[i].drinks[j].DrinkName == drinkname && AllVendingMachines[i].drinks[j].DrinkSize == drinksize)
					{
						AllVendingMachines[i].drinks[j].DrinkSize = 0;
						x = 0;
						break;
					}	
	                        }
				if(x == 0)
				{
					cout << "Purchase successful\n";
					break;
				}	
	                }
			if(x == 1)
				cout << "EEROR: out of stock or invalid input\nPlease try again\n";
		}
	
		else if(choice == "EXIT")
			break;
	 
		else if(choice == "SHOW")
		{
			for(i = 0; i < 5; i++)
			{
				for(j = 0; j < 10; j++)
				{
					cout << AllVendingMachines[i].location.BuildingName << " " << AllVendingMachines[i].location.FloorLevel << " " << AllVendingMachines[i].drinks[j].DrinkName << " " <<
	                	        AllVendingMachines[i].drinks[j].DrinkSize << " " << AllVendingMachines[i].drinks[j].DrinkPrice << endl;
				}
			}
		}	


	}
	return 0;
}

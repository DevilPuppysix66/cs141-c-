#include<iostream>
#include<string>

using namespace std;





int main()
{
	int start;
	string myStr = "the quick brown fox jumped right over the lazy dog.";
	string var;
	start = 0;
	int end;
	end = myStr.length();	
	int location;

	cout << "\nEnter a word or character: ";
	cin >> var;
	
	end = myStr.length();
        myStr = myStr.substr(start,end);
        location =  myStr.find(var);
        start = myStr.find(var) + 1;
	
	if(location == -1)
	{
		cout << "Not found\n";
	}

	else if(location != -1)
	{		
		cout << location;
	}

	while(location != -1)
	{
		location = location + 1;
		end = myStr.length();
		myStr = myStr.substr(start,end);		
		location = location +  myStr.find(var);
		start = myStr.find(var) + 1;
		if(myStr.find(var) == -1)
		{
		break;
		}
		cout <<","<< location;
	}
	
	cout << "\n\n";
	
	return 0;
}

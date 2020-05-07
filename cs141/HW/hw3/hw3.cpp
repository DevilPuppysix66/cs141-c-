#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int cond;
string first;
string middle;
string last;
string zip;
string state;
string phone;

//function declaration
int firstvalid(string);
int middlevalid(string);
int lastvalid(string);
int statevalid(string);
int zipvalid(string);
int phonevalid(string);


int main()
{
//first name validation
        do
        {
                cond = 0;
                cout << "\nplease enter first name\n";
                cin >> first;
                cond = firstvalid(first);
        }while(cond == 1);


//middle name validation
        do
        {
                cond = 0;
                cout << "\nplease enter middle name or enter none\n";
                cin >> middle;
                cond = middlevalid(middle);
        }while(cond == 1);


//last name validation
        do
        {
                cond = 0;
                cout << "\nplease enter last name\n";
                cin >> last;
                cond = lastvalid(last);
        }while(cond == 1);


//state validation
        do
        {
                cond = 0;
                cout << "\nplease enter state abreviation\n";
                cin >> state;
                cond = statevalid(state);
        }while(cond == 1);


// zip code validation
        do
        {
                cond = 0;
                cout << "\nplease enter zip code\n";
                cin >> zip;
                cond = zipvalid(zip);
        }while(cond == 1);


// phone code validation
        do
        {
                cond = 0;
                cout << "\nplease enter phone number\n";
                cin >> phone;
                cond = phonevalid(phone);
        }while(cond == 1);


        cout << "\n" << "Results Ok! \n";
        return 0;

}


//first name function
int firstvalid(string first)
{
	int check = 0;
	int check2 = 0;
	int y = (first.length()-1);
	if(first.length() >= 2 && first.length() <= 10 && first[0] != '-' && first[y] != '-')
                {
                        for(int x = 0; x <= (first.length()-1); x++)
                        {
                                
                                if(x == 0 || check == 1)
                                {
					check = 0;
                                        if(isupper(first[x])==0)
                                                {
                                                        cond = 1;
                                                }
                                }
				else if(first[x]== '-' && check2 == 0)
				{
					check = 1;
					check2 = 1;
				}
                                else
                                {
                                        if(islower(first[x])==0)
                                        {
                                                cond = 1;
                                        }
                                }

                        }
                }
                else
                {
                        cond = 1;
                        cout << "invalid input\n";
                }
                if(cond == 1)
                {
                        cout << "invalid input\n";
                }
	return cond;
}


//middlename function
int middlevalid(string middle)
{
	if(middle == "none")
	{
	
	}
	else if(middle.length() >= 2 && middle.length() <= 10)
		{
                        for(int x = 0; x <= (middle.length()-1); x++)
                        {
                                if(isalnum(middle[x])==0)
                                {
                                        cond = 1;
                                }

                                if(x == 0)
                                {
                                        if(isupper(middle[x])==0)
                                        {
                                                cond = 1;
                                        }
                                }
                                else
                                {
                                        if(islower(middle[x])==0)
                                        {
                                                cond = 1;
                                        }
                                }

                        }
                }
                else
                {
                        cond = 1;
                        cout << "invalid input\n";
                }
                if(cond == 1)
                {
			cout << "invalid input\n";
                }
	return cond;
}


//lastname function
int lastvalid(string last)
{
	int check = 0;
	int check2 = 0;
	if(last.length() >= 2 && last.length() <= 10 && last[0] != '-' && last[(last.length()-1)] != '-')
                {
                        for(int x = 0; x <= (last.length()-1); x++)
                        {
                                
                                if(x == 0 || check == 1)
                                {
					check = 0;
                                        if(isupper(last[x])==0)
                                                {
                                                        cond = 1;
                                                }
                                }
				else if(last[x]== '-' && check2 == 0)
				{
					check = 1;
					check2 = 1;
				}
                                else
                                {
                                        if(islower(last[x])==0)
                                        {
                                                cond = 1;
                                        }
                                }

                        }
                }
                else
                {
                        cond = 1;
                        cout << "invalid input\n";
                }
                if(cond == 1)
                {
                        cout << "invalid input\n";
                }
	return cond;
}


//state function
int statevalid(string state)
{
	if(state.length() == 2)
                {
                        for(int x = 0; x <= (state.length()-1); x++)
                        {

                                if(isupper(state[x])==0)
                                {
                                        cond = 1;
                                }
                        }
                }
                else
                {
                        cond = 1;
                        cout << "invalid input\n";
                }
                if(cond == 1)
                {
                        cout << "invalid input\n";
                }
	return cond;
}


//zipcode function
int zipvalid(string zip)
{
	ifstream indata;
	string validcode;
	indata.open("zipcodes.txt");
	if(zip.length() == 5)
                {
                        for(int x = 0; x <= (zip.length()-1); x++)
                        {
                                if(islower(zip[x])==1 || isupper(zip[x]==1))
                                {
                                        cond = 1;
                                }
                                if(isdigit(zip[x])==0)
                                {
                                        cond = 1;
                                }
                                if(isalnum(zip[x])==0)
                                {
                                        cond = 1;
                                }

                        }
                }
                else
                {
                        cond = 1;
                        cout << "invalid input\n";
                }
                if(cond == 1)
                {
                        cout << "invalid input\n";
                }
	int validzip = 0;
	while(!indata.eof() && validzip == 0)
	{
		indata >> validcode;
		if(zip.substr(0,3) == validcode)
		{
			validzip = 1;
		}
	}
	if(validzip == 0)
	{
		cond = 1;
	}
	if(cond == 1)
	{
		cout << "invalid input\n";
	}
	indata.close();
	return cond;
}


//phonenumber function
int phonevalid(string phone)
{
	if(phone.length() == 12 || phone.length() == 14)
	{
		if(phone.length() == 12)
		{
			for(int x=0; x <= (phone.length()-1);x++)
			{
				if(x == 3 || x == 7)
				{
					if(phone[x] == '-')
					{
					}
				}
				else
				{
					if(isdigit(phone[x]) == 0)
					{
						cond = 1;
					}
				}
			}
		}
		else if(phone.length() == 14)
		{
			for(int x=0; x <= (phone.length()-1);x++)
			{
				if(x == 0)
				{
					if(phone[x] == '(' )
					{
					}
				}
				else if(x == 4)
				{
					if(phone[x] == ')' )
					{
					}
				}
				else if(x == 5 || x == 9)
				{
					if(phone[x] == '-')
					{
					}
				}
				else
				{
					if(isdigit(phone[x]) == 0)
					{
						cond = 1;
					}
				}
			}
		}
	}
	else
        {
                cond = 1;
                cout << "invalid input\n";
        }
        if(cond == 1)
        {
                cout << "invalid input\n";
        }
	return cond;
}






























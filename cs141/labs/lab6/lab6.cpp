#include<iostream>
#include<string>


using namespace std;
int cond;
string first;
string second;
string zip;
string state;


int main()
{
	do
	{
		cond = 0;
		cout << "\nplease enter first name\n";
		cin >> first;
                if(first.length() >= 2 && first.length() <= 10)
		{
			for(int x = 0; x <= (first.length()-1); x++)
			{	
				if(isalnum(first[x])==0)
                                {
					cond = 1;
                                }

				if(x == 0)
				{
					if(isupper(first[x])==0)
						{
							cond = 1;	
						}	
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
	}while(cond == 1);


	do
        {
                cond = 0;
                cout << "\nplease enter last name\n";
                cin >> second;
                if(second.length() >= 2 && second.length() <= 10)
                {
                        for(int x = 0; x <= (second.length()-1); x++)
                        {
				if(isalnum(second[x])==0)
                                {
                                        cond = 1;
                                }

                                if(x == 0)
                                {
                                        if(isupper(second[x])==0)
                                        {
                                                cond = 1;
                                        }
                                }
                                else
                                {
                                        if(islower(second[x])==0)
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
        }while(cond == 1);


	do
        {
                cond = 0;
                cout << "\nplease enter state abreviation\n";
                cin >> state;
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
        }while(cond == 1);


	do
        {
                cond = 0;
                cout << "\nplease enter zip code\n";
                cin >> zip;
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
        }while(cond == 1);


	cout << "\n" << first << "\n" << second << "\n" << state << "\n" << zip << "\n";
	return 0;

}

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

string emailgen(string, string);

int main()
{

	
	ifstream namelist;
	string first;
	string last;
	string email;
	namelist.open("employeeNames.txt");	
	ofstream emaillist;
	emaillist.open("employeesData.txt");

	while(!namelist.eof())
	{
		namelist >> first >> last;
		if(namelist.eof())
			break;
		email = emailgen(first,last);
		emaillist << first << " " << last << " " << email << endl;
	}
		
	namelist.close();	
	emaillist.close();
	return 0;
}

string emailgen(string first,string last)
{
	ifstream namelist;	
        string emailp1;
        string emailp2;
        string email;
	string emailp3 = "@company.com";
        ofstream emaillist;
	
                emailp1 = tolower(first[0]);
                emailp2 = last.substr(0,7);
                emailp2[0] = tolower(emailp2[0]);
                email = emailp1 + emailp2 + emailp3;      
	return email;
}

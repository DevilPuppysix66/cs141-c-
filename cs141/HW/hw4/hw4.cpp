#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

//cout << "test1\n";

vector<pair<string,string> > readnames();
vector<string> readpasswords();
vector<string> randpasswords(vector<string>&);
int writepass(vector<string>&, vector<pair<string,string> >&);

//vector<string> passwords;
//vector<pair<string,string> > names;
//vector<string> randpass;

int main()
{
	vector<pair<string,string> > names = readnames();
	vector<string> passwords = readpasswords();
	vector<string> randpass = randpasswords(passwords);
	writepass(randpass, names);
//	writepass(randpasswords(readpasswords()), readnames());
	return 0;
}

vector<pair<string,string> > readnames()
{
	vector<pair<string,string> > names;
	ifstream indata;
	indata.open("employees.txt");
	
	while (true) 
	{
        	pair<string, string> name;
        	if(!(indata >> name.first >> name.second))
            		break;
        	names.push_back(name);
//		cout << name.first << " " << name.second << endl;
        }
	
	indata.close();
	
	return names;
}

vector<string> readpasswords()
{
	vector<string> passwords;	
	ifstream indata;
        indata.open("passwords.txt");
	string password;
	int x = 0;
        while(true)
        {       
                if (!(indata >> password))
                        break;
                passwords.push_back(password);
//		cout << password << endl;
	x = x +1;
        }
//	cout << x << endl;
	indata.close();
	return passwords;
}

vector<string> randpasswords(vector<string>& passwords)
{	
	vector<string> randpass;
	vector<int> randnum;
	srand (time(NULL));
	int num = 0;
	int i;
	int p = 0;
	num = rand() % 50 + 0;
	randnum.push_back(num);
	
	while(randnum.size() < 50)
	{
		i = 0;
		num = rand() % 50 + 0;
		for(int x = 0; x < randnum.size(); x++)
		{
			if(randnum[x] == num) 
				i = 1;
		}
		if(i == 0)
		{
			randnum.push_back(num);
//			cout << num << endl;
//			p = p+1;
//			cout << p << endl;
		}	
//	cout << "TEST\n";
	}
	for(int x = 0; x < 50; x++)
	{
		
//		cout << "TEST\n";
		int reference = randnum[x];
//		cout << randnum[x]<< endl;
		randpass.push_back(passwords[reference]);
//		cout << "TEST2\n";
		p = p+1;
//		cout << p << endl;
	}
	return randpass;
}

int writepass(vector<string>& randpass, vector<pair<string,string> >& names)
{
//	cout << "test\n";
	ofstream outdata;
	outdata.open("empPasswords.txt");
	for(int i = 0; i < randpass.size();i++)
	{
//	cout << names[i].first << " " << names[i].second << " " << randpass[i] << endl;
	outdata << names[i].first << " " << names[i].second << " " << randpass[i] << endl;
	}
	outdata.close();
	return 0;
}

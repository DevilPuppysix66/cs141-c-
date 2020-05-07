#include<iostream>
#include<fstream>
#include<string>


using namespace std;



string readData();
int computeShift(string);
string decodeData(string, int);
int writeData(string);




int main()
{
	
	string encoded = readData();
	//cout << encoded;
	int shift = computeShift(encoded);
	string msg = decodeData(encoded, shift);
	writeData(msg);
	

	return 0;
}

string readData()
{
	ifstream file;
	string filename;
	string fileData;
	string encoded;
	int cond = 1;

	while(cond == 1)
	{
		cond = 0;
		cout << "Enter file name:";
		cin >> filename;	
		file.open(filename.c_str());
	
		if(!file)
		{
			cout << "file could not be opened\n";
			cond = 1;
		}
	}

	file >> fileData;

	while(!file.eof())
	{
		encoded = encoded + fileData + " ";
		file >> fileData;
	}
	file.close();
	
	return encoded;
}


int computeShift(string encoded)
{
	int shift;
        int max = 0; 
	long counter[100] = {0};
        int result;   
	string charnum = "abcdefghijklmnopqrstuvwxyz";
	int char1=0;
	int count = 0;
	for(int x=0;x < encoded.length();x++) 	
	{
		if(isupper(encoded[x])||islower(encoded[x]))
		{
			encoded[x] = tolower(encoded[x]);  
	 		char1 = charnum.find(encoded[x]);
	 		counter[char1] = counter[char1] + 1; 
		}
	}
	for(int x=0;x<100;x++)
	{
		if(max < counter[x])	
		{
			max = counter[x];
			result = x;
		}
	}
	shift = result-5+1;
	//cout << shift;
	return shift;
}


string decodeData(string encoded, int shift)
{
	string msg = encoded;
	string charnum = "abcdefghijklmnopqrstuvwxyz";
        for(int x=0;x < encoded.length();x++)
        {
                if(islower(encoded[x])||isupper(encoded[x]))
                {
                        encoded[x] = tolower(encoded[x]);
			int reference = charnum.find(encoded[x])-shift;
			if(reference<0)
			{		
			reference = 26 + reference;
			}
			msg[x] = charnum[reference];
			
		}
	}

	cout << msg;
	return msg;
}


int writeData(string msg)
{
	ofstream file;
        string filename;
        string fileData = msg;
        string encoded;
        
                cout << "Enter output file name:";
                cin >> filename;
                file.open(filename.c_str());

        file << fileData;
        file.close();


	return 0;
}


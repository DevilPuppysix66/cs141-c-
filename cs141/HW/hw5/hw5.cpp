#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int readData(string);
float hoursWorked(float, float, float, float);
float breakLength(float, float, float, float);
float overTimeHours(float[][4], int);
float totalDayPay(float, float, float, float, char, int);
int writeData(string);

struct Person
{
	string first;
	string second;
	string last;
};

struct Wage
{
	float wage;
	char ote; // overtime eligibility
	float otwage;
};

struct TimeCard
{
	float hours; // hours worked each day
	float blength; // b is short for break
	float totalhours; //for the week
	float othours; //overtime hours for the whole week
	float totalpay;// total pay for week
};

struct Employee
{
	Person empname;
	Wage empwage;
	string manager1;  // first name
	string manager2;  // middle name
	string manager3;  // last name
	string dpt; // department
	TimeCard timecard[5];
};

enum Days {Mon, Tue, Wed, Thu, Fri};
Employee payroll[20];

int main()
{
	ifstream indata;
	string filename;
	while(1)
	{
		cout << "Please enter input file name\n";
		cin >> filename;
		indata.open(filename.c_str());
		if(indata)
		{
			break;
		}
		else
		{
			cout << "ERROR invalid filename\n\n";
		}
	}

	readData(filename);
	
	cout << "please enter output file name\n";
	cin >> filename;

	writeData(filename);

	return 0;
}

int readData(string filename)
{
	float clocktime[5][4];
	float c1;
	char a;
	float c2;
	float c3;
	float c4;
        float c5;
        float c6;
        float c7;
        float c8;

	int x = 0;
	int i = 0;
	ifstream indata;
	indata.open(filename.c_str());
//	cout << "test2\n";
	
	while(indata >> payroll[i].empwage.wage >> payroll[i].empwage.ote >> payroll[i].empwage.otwage >> payroll[i].empname.first >> payroll[i].empname.second >> payroll[i].empname.last >> payroll[i].dpt >> payroll[i].manager1 >>
	                payroll[i].manager2 >> payroll[i].manager3 >> c1 >> a >> c2 >> c3 >> a >> c4 >> c5 >> a >> c6 >> c7 >> a >> c8)
	{
	//	cout << "test1\n";			
		clocktime[x][0] = c1 + (c2 / 60.0);
		clocktime[x][1] = c3 + (c4 / 60.0);
		clocktime[x][2] = c5 + (c6 / 60.0);
		clocktime[x][3] = c7 + (c8 / 60.0);
		
	//	cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << " " << c6 << " " << c7 << " " << c8 << endl;
	
		float clockin1 = c1+(c2/60);
                float clockout1 = c3+(c4/60);
                float clockin2 = c5+(c6/60);
                float clockout2 = c7+(c8/60);
//		cout << clockin1 << " " << clockout1 << " " << clockin2 << " " << clockout2 << endl;
		payroll[i].timecard[x].blength = breakLength(clockin1, clockout1, clockin2, clockout2);
		payroll[i].timecard[x].hours = hoursWorked(clockin1, clockout1, clockin2, clockout2);
		
//		cout << i;
		x++;
		if(x == 5)
		{
			
                        
			//hoursWorked(clockin1, clockout1, clockin2, clockout2);
                	//breakLength(clockin1, clockout1, clockin2, clockout2);
	                overTimeHours(clocktime, i);
        	        totalDayPay(payroll[i].timecard[0].totalhours, payroll[i].timecard[0].othours, payroll[i].empwage.wage, payroll[i].empwage.otwage, payroll[i].empwage.ote, i);
			x = 0;
			i++;
                }
		
	}
	indata.close();
	return 0;
}

float hoursWorked(float clockin1, float clockout1, float clockin2, float clockout2)
{
	float hoursworked = clockout1 - clockin1 + clockout2 - clockin2;
//	cout << hoursworked << endl; 
	return hoursworked;
}


float breakLength(float clockin1, float clockout1, float clockin2, float clockout2)
{
	float breaklength = clockin2 - clockout1;
	return breaklength;
}


float overTimeHours(float clockin1[][4], int i)
{
	float totalhours = 0;
	
//	if(payroll[i].empwage.ote == 'Y')
//	{
		for(int x = 0; x < 5; x++)
		{
			totalhours = totalhours + payroll[i].timecard[x].hours; 
		}
		for(int x = 0; x < 5; x++)
                {
			payroll[i].timecard[x].totalhours = totalhours;
			if(payroll[i].empwage.ote == 'Y')
			{
        	        //	payroll[i].timecard[x].totalhours = totalhours;
				if(totalhours > 37.5)
				{
					payroll[i].timecard[x].othours = totalhours - 37.5;  
				}
				else
				{
					payroll[i].timecard[x].othours = 0;
				}
			}
			else
			{
				for(int x = 0; x < 5; x++)
				{
					payroll[i].timecard[x].othours = 0;
              			}
			}
		}
//	}
//	else
//	{
//		for(int x = 0; x < 5; x++)
//		{
//			payroll[i].timecard[x].othours = 0;
//		}
//	}
	return 0;
}


float totalDayPay(float tothours, float othours, float wage, float otwage, char ote, int i)
{
	if(payroll[i].empwage.ote == 'Y')
	{
		if(payroll[i].timecard[0].othours >= 0)
		{
			for(int x = 0; x < 5; x++)
	                {
        	                payroll[i].timecard[x].totalpay =  37.5 * payroll[i].empwage.wage + (payroll[i].timecard[x].othours)*payroll[i].empwage.wage*payroll[i].empwage.otwage;
                	}
		}
	}
	else
	{
		for(int x = 0; x < 5; x++)
		{
			payroll[i].timecard[x].totalpay =  payroll[i].timecard[x].totalhours * payroll[i].empwage.wage;
		}
	}
	return 0;
}


int writeData(string filename)
{
	ofstream outdata;
	outdata.open(filename.c_str());
	outdata << "<payroll>\n";
	for(int i = 0; i<20; i++)
	{
		outdata << "	<employee>\n";
		outdata << "		<name>" << payroll[i].empname.first << " "; 
		if(payroll[i].empname.second != "NONE")
		{
			outdata << payroll[i].empname.second << " ";
		}
		outdata << payroll[i].empname.last << "</name>\n";
		outdata << "		<department>" << payroll[i].dpt << "</department>\n";
		outdata << "		<payrate>" << payroll[i].empwage.wage << "</payrate>\n";
		outdata << "		<hours>" << payroll[i].timecard[0].totalhours << "</hours>\n";
		outdata << "		<overhours>" << payroll[i].timecard[0].othours << "</overhours>\n";
		outdata << "		<pay>" << payroll[i].timecard[0].totalpay << "</pay>\n"; 
		outdata << "	</employee>\n";
	}
	outdata << "</payroll>\n";
	outdata.close();
	return 0;
}

#include<iostream>

//fibonacci breaks after input of more than 92
//factorial breaks after input of more than 20
int main()
{
	short input;
	long fib1;
	long fib2;
	long fib3;
	long fact;
	short n;
	char loop;
	loop = 1;
	
	while(loop == 1)
	{
		std::cout << std::endl;
		std::cout << "Please enter a number to generate Fibonacci numbers and factorials: ";
		
		//take input
		std::cin >> input;
		std::cout << std::endl;
	
		//verify input > 0
		if(input < 0)
		{
			std::cout << "ERROR: Input is negative and cannot create factorials or fibonacci numbers";
			std::cout << std::endl;
		}

		//check if input = 0
		else if(input == 0)
		{
			std::cout << "ERROR: Input is 0 and cannot generate Fibonacci numbers, but the factorial of 0 is 1."; 
			std::cout << std::endl;
		}
	
		//generate fibonachi numbers and factorial
		else
		{
			//reset
			fib1 = 1;
			fib2 = 0;
	
			std::cout<< "The first " << input << " Fibonacci numbers are:";
			n = input;
		
			//fibonacci loop
			while(n > 0)
			{
				fib3 = fib1 + fib2;
				std::cout << " " << fib3;
				fib1 = fib2;
				fib2 = fib3;
				
				n = (n-1);
			}
		
			//factorial loop
			std::cout << ", and the factorial is ";
			n = input;
			fact = 1;
			while(n > 0)
			{
				fact = fact * n;
				n = (n-1);
			}

			std::cout << fact <<std::endl;
		}
	}

	return 0;

}

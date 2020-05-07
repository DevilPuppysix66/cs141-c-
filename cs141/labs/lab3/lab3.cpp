#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>

int main()

{
	float num1;
	float num2;
	char operation;
	float result;
	char cont;
	
	//create instructions for calculator use
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to cs141 calculator" << std::endl;
        std::cout << std::endl; 
        std::cout << "Allowed operations include" <<std::endl;
	std::cout << std::endl;
        std::cout << "Addition(+)"<<std::endl;
	std::cout << "Subtraction(-)"<<std::endl;
	std::cout << "Multiplication(*)"<<std::endl;
	std::cout << "Division(/)"<<std::endl;
	std::cout << "Exponential(^)"<<std::endl;
	std::cout << std::endl;
	std::cout << "Enter operations in the following format" << std::endl;
	std::cout << "firstnumber operation secondnumber, for example" << std::endl;
	std::cout << "6 + 5" << std::endl;

	cont = 'y';
		
	// i want testing to be easy
	while(cont == 'y')
        {
	
		std::cout << "You may now enter your operation"<<std::endl;
        	std::cout << std::endl;
	
		//take inputs
		std::cin >> num1 >> operation >> num2;
		
				//things that didnt work
				//std::cin.clear();
				//std::cin.ignore(10,'/n');
				//if(isdigit('num1') == 1 && isdigit('num2') == 1)  i couldnt get this to work so i made it a comment
				//{
		

		if(operation == '+')   //addition
			{
				result = num1 + num2;
				std::cout << num1 << " + " << num2 << " = " << result << std::endl;
			}

			else if(operation == '-')   //subtraction
			{
				result = num1 - num2;
                		std::cout << num1 << " - " << num2 << " = " << result << std::endl;
			}
	
			else if(operation == '*')   //multiplication
	        	{
				result = num1 * num2;
	                	std::cout << num1 << " * " << num2 << " = " << result << std::endl;
	        	}
	
			else if(operation == '/')   //division
	        	{
				if(num2 != 0)
				{
					result = num1 / num2;
                			std::cout << num1 << " / " << num2 << " = " << result << std::endl;
				}
	
				else
				{
					std::cout << "ERROR STOP!! ... that's illegal..." << std::endl;
				}
	        	}

			else if(operation == '^')   //exponent
	        	{
				result = pow(num1, num2);
	                	std::cout << num1 << " ^ " << num2 << " = " << result << std::endl;
	        	}

			else
			{
				std::cout << "ERROR Unknown Operation" <<std::endl;
			}
		//}
		
		//else
		//{
		//	std::cout << "ERROR Invalid number input" << std::endl;
		//}
	
	std::cout << "to continue press y, to quit type n" <<std::endl;
	std::cin >> cont;
	}

	return 0;
}

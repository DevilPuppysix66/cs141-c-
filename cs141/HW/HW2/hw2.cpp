#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>

int main()

{
        float num1;
        float num2;
        std::string operation;
        float result;
        char cont;
	std::string overflow;
	
        //create instructions for calculator use
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Welcome to cs141 calculator" << std::endl;
        std::cout << std::endl;
        std::cout << "Allowed operations include" <<std::endl;
        std::cout << std::endl;
        std::cout << "Addition(+ or plus)"<<std::endl;
        std::cout << "Subtraction(- or minus)"<<std::endl;
        std::cout << "Multiplication(* or multiply)"<<std::endl;
        std::cout << "Division(/ or divide)"<<std::endl;
        //std::cout << "Exponential(^)"<<std::endl;
        std::cout << std::endl;
	std::cout << "to quit enter (-1 x -1) or (-1 quit -1)\n\n";
        std::cout << "Enter operations in the following format" << std::endl;
        std::cout << "firstnumber operation secondnumber, for example" << std::endl;
        std::cout << "6 + 5 or 6 plus 5" << std::endl;

        cont = 'y';

        // i want testing to be easy
        while(cont == 'y')
        {

                std::cout << "You may now enter your operation"<<std::endl;
                std::cout << std::endl;

                //take inputs
                std::cin >> num1 >> operation >> num2;
			//	getline(std::cin, overflow);
			//	if(overflow.empty())
			//	{
			//		std::cout << "its empty";
			//		
			//	}
			//	else
			//	{
			//	std::cout << overflow;
			//	break;
			//	}
		//std::cout <<"num1="<< num1 <<"operation="<< operation <<"num2="<< num2 <<"overflow="<< overflow << std::endl;
                                //things that didnt work
                                //std::cin.clear();
                                //std::cin.ignore(10,'/n');
                                //if(isdigit('num1') == 1 && isdigit('num2') == 1)  i couldnt get this to work so i made it a comment
                                //{

		if (operation == "x"||operation == "quit")
                {
                        if(num1 == -1 && num2 == -1)
                        {
                                std::cout << "program terminated" << std::endl;
				break;
                        }
                	
			else
			{
				//nothing lmao 
			}
		}
	                else if(operation == "+"||operation == "plus")   //addition
                        {
                                result = num1 + num2;
                                std::cout <<"Result of " <<  num1 <<" "<< operation <<" "<< num2 << " is " << result << std::endl;
                        }

                        else if(operation == "-"||operation == "minus")   //subtraction
                        {
                                result = num1 - num2;
                                std::cout <<"Result of " <<  num1 <<" "<< operation <<" "<< num2 << " is " << result << std::endl;
                        }

                        else if(operation == "*"||operation == "multiply")   //multiplication
			{
                                result = num1 * num2;
                                std::cout <<"Result of " <<  num1 <<" "<< operation <<" "<< num2 << " is " << result << std::endl;
                        }

                        else if(operation == "/"||operation == "divide")   //division
                        {
                                if(num2 != 0)
                                {
                                        result = num1 / num2;
                                        std::cout <<"Result of " <<  num1 <<" "<< operation <<" "<< num2 << " is " << result << std::endl;
                                }

                                else
                                {
                                        std::cout << "ERROR STOP!! ... that's illegal..." << std::endl;
                                }
                        }

                       // else if(operation == '^')   //exponent
                       // {
                       //         result = pow(num1, num2);
                       //         std::cout << num1 << " ^ " << num2 << " = " << result << std::endl;
                       // }
			
			
                        else
                        {
                                std::cout << "ERROR Unknown Operation" <<std::endl;
                        }
		
                //}

                //else
		//{
                //      std::cout << "ERROR Invalid number input" << std::endl;
                //}

        }

        return 0;
}


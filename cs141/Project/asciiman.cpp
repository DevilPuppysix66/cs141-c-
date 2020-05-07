#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<vector>
#include<cstdlib>

using namespace std;

string randword(int);
int readfiles();
void asciiman(int);


struct category
{
	string hint1;
	string hint2;
	string word;
};

struct Categories
{
	int currentwordnum;
	category theme[10];
	vector<int> usedwords;
};

Categories categories[5];


string Themes[5] = {"Movies", "Vegetables", "Fruits", "States", "Countries"};

int main()
{
	//read in categories from files
	readfiles();
	
	//main game loop
	
	string gameword;
	int choice;
	while(1)
	{
		// provide list of categories  Movies, Songs, Fruits, States,Countries

		while(1)
		{
			cout << "Welcome to asciiman hangman please choose a category from the following:\n" << "0.Movies \n1.Vegatables \n2.Fruits \n3.States \n4.Countries\n";
			cin >> choice;
			cin.clear();
			if(categories[choice].usedwords.size() < 10)
			{
				if(choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4)
				{
					break;
				}
				else
				{
					cout << "ERROR invalid category choice, Please try again.";
				}
			}
			else
			{
				cout << "Error: out of words in category please choose different category\n";
			}
		}
	
		//pick word from category that was selected/show dashes to show length
	
		gameword = randword(choice);
		string secretword = "";
		int currentwordnum = categories[choice].currentwordnum;
//		cout << currentwordnum;
		
		for(int x = 0; x < gameword.length(); x++)
		{
			secretword = secretword + '-';
		}
		//cout << endl << secretword << endl;
		int counter  = 6;
		int misses = 0;

		//should display number of tries left then ask for a letter input

		string guesses = "";
		char guess;
		while(counter != 0)
		{		
			cout << endl <<"Total incorrect guesses remaining = " << counter << endl;
			asciiman(misses);
			cout << "Category: " << Themes[choice] << endl;
			cout << "Letters guessed: " << guesses << endl << endl;
			cout << "Word (" << secretword.length() << " letters):" << endl << endl << secretword << endl << endl;
			if(counter == 2 || counter == 1)
                        {
                                cout << "Hint 1: " << categories[choice].theme[currentwordnum].hint1 << endl;
                        }
                        if(counter == 1)
                        {
                                cout << "Hint 2: " << categories[choice].theme[currentwordnum].hint2 << endl;
                        }

			cout << "Guess a letter\n";
			while(1)
			{
				cin >> guess;
				cin.clear();
				if(isupper(guess) || islower(guess))
				{
					tolower(guess);
					break;
				}
				else
				{
					cout << "invalid guess, please try again \n\n";
				}
			}
			guesses = guesses + guess + ',';
			int correct = 0;
			for( int x = 0; x < gameword.length(); x++)
			{
				if(gameword[x] == guess)
				{
					secretword[x] = gameword[x];
					correct = 1;
				}
			}
			if(correct == 0)
			{
				counter = counter - 1;
				misses = misses + 1;
			}
				
			//on second to last and last guess provide hint for the word and second hint for the word respectively
			
			//check if user won the game
//		cout << "Hint 1: " << categories[choice].theme[currentwordnum].hint1 << endl;
			if(secretword == gameword)
			{
				cout << "Congragulations you win" << endl;
				cout << gameword << endl << endl;
				break;
			}
		}
		if(counter == 0)
			asciiman(misses);
		// ask user to countine if yes re-loop program from start

		char cont;
		while(1)
		{
			cout << "Do you want to play again? (Y/N): ";
			cin  >> cont;
			cin.clear();
			tolower(cont);
			if(cont == 'y' || cont == 'n')
				break;
			else
				cout << "invalid input\n\n";
		}
		if(cont == 'N')
			break;
	}
	return 0;
}




string randword(int choice)
{
        srand (time(NULL));
        int num = 0;
        int i;

        i = 0;
        num = rand() % 10 + 0;
        for(int x = 0; x < categories[choice].usedwords.size(); x++)
        {
                if(categories[choice].usedwords[x] == num)
                         i = 1;
        }
        if(i == 0)
        {
                categories[choice].usedwords.push_back(num);
		categories[choice].currentwordnum = num;
        }
//	cout <<  categories[choice].theme[num].word;
       	return categories[choice].theme[num].word;
}

int readfiles()
{	
	string word;
	string hint1;
	string hint2;
	ifstream indata;
	int j = 0;
	string replacement;
	for(int x = 0; x<5; x++)
	{
		j = 0;
		string filename = Themes[x] + ".txt";
		indata.open(filename.c_str());
		while(indata >> word >> hint1 >> hint2)
		{
			//cout << word << " " << hint1 << " " << hint2 << endl;
			for(int k = 0; k < word.length(); k++)
			{
				if(word[k] == '_')
					word[k] = ' ';
			}
			categories[x].theme[j].word = word;
	//		cout << word << " ";
			replacement = "";
			
			for(int k = 0; k < hint1.length(); k++)            
			{                                                   
        			if(hint1[k] == '_')                           
                			replacement = replacement + ' ';    
        			else                                        
                			replacement = replacement + hint1[k];
			}                                                   
			categories[x].theme[j].hint1 = replacement;
	//		cout << replacement << " ";          
			replacement = "";                                 
			
			for(int k = 0; k < hint2.length(); k++)            
			{                                                   
        			if(hint2[k] == '_')                           
                			replacement = replacement + ' ';    
        			else                                        
                			replacement = replacement + hint2[k];
			}                                                   
			categories[x].theme[j].hint2 = replacement;
	//		cout << replacement << " " << endl;          
			replacement = "";                                 
			j++;
		}
		indata.close();
	}
	return 0;
}


void asciiman(int misses)
{
	if(misses == 0)
		cout << endl << endl << "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n\n";
	else if(misses == 1)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n      |\n      |\n      |\n=========\n\n";
	else if(misses == 2)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n  |   |\n      |\n      |\n=========\n\n";
	else if(misses == 3)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n /|   |\n      |\n      |\n=========\n\n";
	else if(misses == 4)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n /|\\  |\n      |\n      |\n=========\n\n";
	else if(misses == 5)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n /|\\  |\n /    |\n      |\n=========\n\n";
	else if(misses == 6)
		cout << endl << endl << "  +---+\n  |   |\n  o   |\n /|\\  |\n / \\  |you lose\n      |\n=========\n\n";
}

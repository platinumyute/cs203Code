// --------------------------------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim, Tabish CS 203 Lab 06
// Description: this program uses a class  which finds all the prime numbers 
//				up to a max number input by the user
// --------------------------------------------------------------------------------

#include "array.cpp"

int main()
{
	char userContinue;
	int userInput;
	
	do
	{
		cout << "Enter a number [0-5000] to find prime numbers: "; 
		cin >> userInput;

		prime *p = new prime(userInput);
		p->LoadArrayWithPrimes();
		p->print();
		
		delete p;
		
		cout << endl;
		cout << "enter 'y' or 'Y' to continue: ";
		cin  >> userContinue;
		cout << endl;
		
	} while(userContinue == 'y' || userContinue == 'Y');
	
	system("pause");
	return 0;
}



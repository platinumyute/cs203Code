#ifndef array_h
#define array_h

#include <iostream>
#include <cmath>
#include <iomanip>


//width for iomanip setw
const int w = 7;	


using namespace std;

//start of prime class prototype
class prime
{
	private:
		int userInput;
		int numOfPrimes;
		int *array;
	
	public:
		//constructors
		prime();
		prime(int userInput);
		
		
		void LoadArrayWithPrimes();
		void print();
		
		//set to private later
		bool isPrime(int value);	
		int GetPrimeCount();
		
		
		//deconstructors;
		~prime();
		
};
// end of prototype

//**********************************
//start of prime class definitions
//**********************************

prime::prime()
{
	userInput = 0;
}

prime::prime(int userInput)
{
	this->userInput = userInput;
}

int prime::GetPrimeCount()
{
	int count = 0;
	for(int i = 2; i < userInput; i++)
	{
		if(isPrime(i))
			count++;
	}
	return count;
}

void prime::LoadArrayWithPrimes()
{
	//get number of primes
	int primeCount = GetPrimeCount();
	
	//allocate dynamic array
	this->array = new int[primeCount];
	
	//set object's primecount
	this->numOfPrimes = primeCount;
	
	//set starting point for finding primes
	int primeStart = 2;
	
	//loops to find each prime values, and puts it in the array
	for(int i= 0; i < primeCount; i++)
	{
		while(!isPrime(primeStart)) 
			primeStart++;
		
		this->array[i] = primeStart;
		primeStart++;
	}
}

void prime::print()
{
	int offset = 0;
	int lineCount = 0;
	
	if(this->numOfPrimes > 100)
		offset = this->numOfPrimes - 100;
		
	for(int i = offset; i < this->numOfPrimes; i++)
	{
		if(lineCount % 10 == 0)
		{
			cout << endl;
			lineCount = 0;
		}
		
		cout << setw(w) << this->array[i];
		lineCount++;
	}
}

//determines is x is a prime number
bool prime::isPrime(int x)
{
	if(x <= 1)
 		return false;
 	
	else if(x == 2)
		return true;		
	
	else
	{
		double rox = sqrt(x);
		for(int i = 2; i <= rox;  i++ )
		{
			if( (x % i) == 0)
				return false;
		}
		return true;	
	}
}

prime::~prime()
{
	delete [] this->array;
}
#endif

// ------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim CS 203 Lab 03
// Description: this program will create a file on the main directory with R records of the type Data.
// ------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std; 

const int LINE = 6;
const int w = 5;

void printFile(ifstream  *fin);
void computeMean(ifstream *fin);


int main(int argc, char *argv[])
{	
	ifstream fin(argv[1]);
	cout << argc <<endl;
	printFile(&fin);
	
	computeMean(&fin);
}

void computeMean(ifstream *fin)
{
	int count = 0;
	double sum = 0;
	double mean;
	int value;
	
	while(*fin)
	{
		*fin >> value;
		
		if(*fin)
		{
			sum += value;
			count++;
		}
	}
	mean = sum / count;
	cout << "mean is " << mean  << endl;
	
	//reposition the read pointer back to the beginning of the file
	fin->clear();
	fin->seekg(ios::beg);
}

void printFile(ifstream  *fin)
{
	int count =1;
	int value;
	while(*fin)
	{
		*fin >> value;
		if(*fin)
		{
			cout << setw(w) << value << setw(w);
			if(count % 10 == 0)
			{
				cout << endl << setw(w); 
			}
			count++;
		}
	}
	
	//reposition the read pointer back to the beginning of the file
	fin->clear();
	fin->seekg(ios::beg);
}


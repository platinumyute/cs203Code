// ------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim CS 203 Lab 03
// Description: this program will read a text file from the command line and calculate a statistic based on the input file.
// ------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std; 

// our width for the setw function 
const int w = 5;

void printFile(ifstream  *fin);
double computeMean(ifstream *fin);
double computeStandardDeviation(ifstream  *fin);
void printMeanAndDeviation(ifstream *fin);

int main(int argc, char *argv[])
{	
	ifstream fin(argv[1]);
	if(fin)
	{
		printFile(&fin);
		printMeanAndDeviation(&fin);
	}
	else
	{
		cout << "File does not exist." << endl;
	}
}

void printMeanAndDeviation(ifstream *fin)
{
	double mean = computeMean(fin);
	cout << "The mean is: " << mean << endl;
	
	double sDev = computeStandardDeviation(fin);
	cout << "The standard deviation is: " << sDev << endl;
}

double computeMean(ifstream *fin)
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
	
	//reposition the read pointer back to the beginning of the file
	fin->clear();
	fin->seekg(ios::beg);
	return mean;
}

void printFile(ifstream  *fin)
{
	int count = 1;
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
	cout << endl;
	
	//reposition the read pointer back to the beginning of the file
	fin->clear();
	fin->seekg(ios::beg);
}

double computeStandardDeviation(ifstream  *fin)
{
	int count = 0;
	double mean = computeMean(fin);
	double value;
	double sum = 0;
	double sDev;
	while(*fin)
	{
		*fin >> value;
		
		if(*fin)
		{
			value = pow(value - mean, 2);
			sum += value;
			count++;
		}
	}
	sum = sum / count;
	sDev = sqrt(sum);
	return sDev;
} 

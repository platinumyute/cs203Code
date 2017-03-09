// ------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim CS 203 Lab 02
// Description: this program will create a file on the main directory with R records of the type Data.
// ------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std; 

struct Data {
	int id;
	char gender;
	int credits;
};

char getRandomGender();
int getRandomValue(int min, int max);

int main()
{
	const char* file_name = "data.bin";
	srand(time(NULL));
	int numOfRecords;
	
	//Gets number of records to be created
	cout << "please enter the number Records to be created [20 - 60]: ";
	cin >> numOfRecords;
	
	//creates a binary output stream
	ofstream fout(file_name, ios::binary);
		
	//creates the amount of records and writes it to the output file;
	//id: 000 – 1000; gender: m, f;  credits: 0 – 124; 

	for(int i=0; i < numOfRecords; i++)
	{
		Data R;
		R.id = getRandomValue(0, 1000);
		R.credits = getRandomValue(0, 124);
		R.gender = getRandomGender();
		fout.write((char*) &R, sizeof(Data));
	}	
	
	fout.close();
	
	//opens a new binary input stream
	ifstream fin(file_name, ios::binary);
	
	int creditSum = 0;
	double creditAvg;
	
	// iterates through the records and sums all credits
	for(int i=0; i < numOfRecords; i++)
	{
		Data R;
		fin.read((char *) &R, sizeof(Data) );
	
		creditSum += R.credits;
	}
	
	fin.close();
	
	creditAvg = creditSum / numOfRecords;
	
	cout << "The file 'data.bin' processed " << numOfRecords << " records and the average number of credits is " << creditAvg << endl; 
	
	return 0;
}

int getRandomValue(int min, int max)
{
	int value = (min + (rand() % (max + 1 - min)));
	return value;
}

char getRandomGender()
{
	int rGen= rand() % 2;
	char gender;
	
	if(rGen == 0)
	{
		gender = 'm';
	}
	else
	{
		gender = 'f';
	}
	return gender;
}

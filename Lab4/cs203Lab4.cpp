// ---------------------------------------------------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim CS 203 Lab 04
// Description: this program will display a number based menu for the user to select a geometric object,
//				collects the required measurements, and calculates the volume of the object they select.
// ----------------------------------------------------------------------------------------------------
#include "geometrics.h"

//prototypes
void SelectedCube();
void SelectedSphere();
void SelectedCylinder();

int main()
{
	int choice;
	char con;
	string errorMessage = "invalid number entered";
	do
	{
		//displays a number based menu for user to enter selection
		cout << "please enter the number for the geometric shape to calculate " << endl;
		cout << "1. Cube" << endl;
		cout << "2. Sphere" << endl;
		cout << "3. Cylinder" << endl;
		cout << "->";
		
		cin >> choice;
		if(choice > 0)
		{
			switch(choice)
			{
				case 1:
					SelectedCube();
					break;
				case 2:
					SelectedSphere();
					break;
				case 3:
					SelectedCylinder();
					break;
				default:
					cout << errorMessage << endl;
					break;
			}
		}
		else
		{
			cout << errorMessage << endl;
		}
		
		// asks user to continue
		cout << endl <<"do you want to continue?...enter 'y' or 'Y': ";
		cin >> con;
		cout << endl;
		
	} while(con == 'y' || con == 'Y');
}

//function definitons
void SelectedCube()
{
	Cube *cb = new Cube;
	string errorMessage = "cannot enter a number of zero or less";
	double side;
	double volume;
	
	cout << "please enter the length of cube Side: ";
	cin >> side;
	
	if(side > 0)
	{
		cb->setSide(side);
		cb->CalculateVolume();
		cb->PrintVolume();
	}
	else
	{
		cout << errorMessage << endl;
	}
	
	delete cb; 
}

void SelectedSphere()
{
	Sphere *sp = new Sphere;
	string errorMessage = "cannot enter a number of zero or less";
	double radius;
	double volume;
	
	cout << "please enter length of radius: ";
	cin >> radius;
	
	if(radius > 0)
	{
		sp->setRadius(radius);
		sp->CalculateVolume();
		sp->PrintVolume();
	}
	else
	{
		cout << errorMessage << endl;
	}
	
	delete sp;
}
void SelectedCylinder()
{
	Cylinder *cy = new Cylinder;
	string errorMessage = "cannot enter a number of zero or less";
	double radius;
	double height;
	double volume;
	
	cout << "please enter cylinder radius: ";
	cin >> radius;
	
	if(radius > 0)
	{		
		cout << "please enter cylinder height: ";
		cin >> height;
		
		if(height > 0)
		{
			cy->setRadius(radius);
			cy->setHeight(height);
			cy->CalculateVolume();
			cy->PrintVolume();
		}
		else
		{
			cout << errorMessage << endl;
		}	
	}
	else
	{
		cout << errorMessage << endl;
	}
	
	delete cy;
}          

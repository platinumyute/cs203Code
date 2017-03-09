// ------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim CS 203 Lab 01
// Description: computes the distance and slope of two points using only pointers to a structure and two functions.
// ------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std; 

struct point {
	double x1;
	double y1;
	double x2;
	double y2;
	double d;
	double m;
};

void calculateDistance(point *p);
void calculateSlope(point *p);

int main()
{
	point *p = new point;
	
	cout << "please enter x1: ";
	cin >> p->x1;
	
	cout << "please enter y1: ";
	cin >> p->y1;
	
	cout << "please enter x2: ";
	cin >> p->x2;
	
	cout << "please enter y2: ";
	cin >> p->y2;
	
	calculateDistance(p);
	calculateSlope(p);
	
	if(p->m != -99)
	{
		cout << "The distance between (" << p->x1 << ","<< p->y1 << ") and (" << p->x2 << ","<< p->y2 << ") is " << p->d << " and the slope is " << p->m << endl;
	}
	else
	{
		cout << "The distance between (" << p->x1 << ","<< p->y1 << ") and (" << p->x2 << ","<< p->y2 << ") is " << p->d << " but there is no slope " << endl;
	}
	return 0;
}

void calculateDistance(point *p)
{
	double dx = (p->x2 - p->x1);
	double dy = (p->y2 - p->y1);	
	p->d = sqrt(pow(dx, 2) + pow(dy, 2));
}

void calculateSlope(point *p)
{
	double dx = (p->x2 - p->x1);
	double dy = (p->y2 - p->y1);
	if((dx) == 0)
	{
		p->m = -99;
	}
	else if(dy == 0)
	{
		p->m = 0;	
	}
	else
	{
		p->m = dy/dx;
	}
}

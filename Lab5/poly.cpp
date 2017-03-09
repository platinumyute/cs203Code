#include "poly.h"
#include <iostream>

using namespace std;

//*************************************
//start of polynomial class definitons
//*************************************

Polynomial::Polynomial()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

Polynomial::Polynomial(Polynomial *p)
{
	this->a = p->a;
	this->b = p->b;
	this->c = p->c;
	this->d = p->d;
}

Polynomial::Polynomial(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

Polynomial* Polynomial::add(Polynomial *p)
{
	Polynomial *pr = new Polynomial;
	
	pr->a = this->a + p->a; 
	pr->b = this->b + p->b; 
	pr->c = this->c + p->c; 
	pr->d = this->d + p->d; 
	return pr;
}

Polynomial* Polynomial::subtract(Polynomial *p)
{
	Polynomial *pr = new Polynomial;
	pr->a = this->a - p->a; 
	pr->b = this->b - p->b; 
	pr->c = this->c - p->c; 
	pr->d = this->d - p->d; 
	return pr;
}

void Polynomial::print()
{
	cout << "Polynomial result is:" << endl;
	cout << "x^3: " << this->a << endl;
	cout << "x^2: " << this->b << endl;
	cout << "x^1: " << this->c << endl;
	cout << "x^0: " << this->d << endl;
}

//************************************
//end of polynomial class definitons
//************************************

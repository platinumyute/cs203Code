#include <iostream>

using namespace std;



//*****************************
//start of class prototypes
//**************************

class Polynomial
{
	private:
		int a;
		int b;
		int c;
		int d;
		
	public:
		Polynomial();
		Polynomial(Polynomial*);
		Polynomial(int, int, int, int);
		Polynomial * add(Polynomial*);
		Polynomial * subtract(Polynomial*);
		void print();
};

//*****************************
//end of class prototypes
//**************************


//*****************************
//start of class definitons
//**************************

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
	cout << "x3 = " << this->a  << " x2 = " << this->b << " x = " << this->c << " constant = " << this->d << endl;
}

//*****************************
//end of class definitons
//*****************************


//*****************************
//Functions prototypes
//*****************************

Polynomial* getInput();


int main()
{
	int choice = 0;
	cout << "Would you like to add or subtract?" << endl;
	cout << "1. Add" << endl;
	cout << "2. Subtract" << endl;
	cin >> choice;
	
	cout << "First Polynomial: " << endl;
	Polynomial *p1 = getInput();
	
	cout << endl;
	cout << "Second Polynomial: " << endl;
	Polynomial *p2 = getInput();
	
	Polynomial *pr = new Polynomial;
	
	switch(choice)
	{
		case 1:
			*pr = p1->add(p2);
			break;
		case 2:
			*pr = p1->subtract(p2);
			break;
		default:
			cout <<"print error message" << endl;
			break;
	}
	
	pr->print();
	
	return 0;
}

Polynomial* getInput()
{
	int a,b,c,d;
	
	cout << "x^3: ";
	cin >> a;
	
	cout << "x^2: ";
	cin >> b;
	
	cout << "x^1: ";
	cin >> c;
	
	cout << "x^0: ";
	cin >> d;
	
	Polynomial *p = new Polynomial(a,b,c,d);
	return p;
}


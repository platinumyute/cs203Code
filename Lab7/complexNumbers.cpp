#include<iostream>
#include<iomanip>

using namespace std;
class complex {	
	private:
		int real;
		int imaginary;
		char sign;
	public:
		complex();
		complex(int real, char sign, int imaginary);
	
		complex operator +(complex c);
		complex operator -(complex c);
		complex operator *(int multiplier);
		
		friend ostream& operator <<(ostream &output, complex c);
		friend istream& operator <<(istream &input, complex &c);
		
		int getA();
		int getB();	
		char getSign();	
		
		void print();		
};

complex::complex()
{
	real = 0;
	imaginary = 0;
}

complex::complex(int real, char sign, int imaginary)
{
	this->real = real;
	this->sign = sign;
	this->imaginary = imaginary;
}

int complex::getA()
{
	return real;
}

int complex::getB()
{
	
	return imaginary;
}
	
char complex::getSign()
{
	return sign;
}

complex complex::operator +(complex c)
{
	complex nc;
	nc.real = real + c.real;
	if(imaginary >= 0)
		nc.sign = '+';
	else
		nc.sign = '-';
	nc.imaginary = imaginary + c.imaginary;
	return nc;
}

complex complex::operator -(complex c)
{
	complex nc;
	nc.real = real - c.real;
	nc.imaginary = imaginary - c.imaginary;
	if(imaginary >= 0)
		nc.sign = '+';
	else
		nc.sign = '-';
	
	return nc;
}

complex complex::operator *(int multiplier)
{
	complex nc;
	nc.real = real * multiplier;
	nc.imaginary = imaginary * multiplier;
	if(imaginary >= 0)
		nc.sign = '+';
	else
		nc.sign = '-';
	return nc;
}

void complex::print()
{
	cout << real << " " << sign << " " <<  imaginary << "i" << endl;
}


ostream& operator <<(ostream &output, complex c)
{
	output << c.getA() << " " << c.getSign() << " " << c.getB() << "i" <<  endl;  
	return output;
}


istream& operator >>(istream &input, complex &c)
{
	int a;
	int	b;
	char sign;
	input >> setw(1) >> a;
	input.ignore(1);
	
	input >> setw(1) >> sign;
	input.ignore(1);
	
	input >> setw(1) >> b;
	input.ignore();
	if(sign == '-')
		b *= -1;
	c = complex(a, sign, b);
	
	return input;
}

int main()
{
	complex c1;
	complex c2;
	complex c3;
	int operation = 0;
	int multiplier = 1;
	
	cout << "please select operation to perform " << endl;
	cout << "1. Addition" << endl;	
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "-->";
	cin >> operation;
	
	switch(operation)
	{
		case 1: 
			cout << "please enter 1st expression: ";
			cin >> c1;
			cout << "please enter 2nd expression: ";
			cin >> c2;
			c3 = c1 + c2;
			break;
			
		case 2: 
			cout << "please enter 1st expression: ";
			cin >> c1;
			cout << "please enter 2nd expression: ";
			cin >> c2;
			c3 = c1 - c2;
			break;
			
		case 3: 
			cout << "please enter 1st expression: ";
			cin >> c1;
			cout << "please enter multiplier: ";
			cin >> multiplier;
			c3 = c1 * multiplier;
			break;
		
		default:
			cout << "invalid operation" << endl;
	}	
	cout <<  c3;
	
	return 0;
}

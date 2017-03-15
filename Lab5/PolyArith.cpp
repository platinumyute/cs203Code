#include "poly.cpp"

Polynomial* getInput();

int main()
{
	int selectedOperation = 0;

	//prompts user for operation selection, and stores input
	cout << "Enter the polynomial operation you would like to do perform" << endl;
	cout << "1. Add" << endl;
	cout << "2. Subtract" << endl;
	cout << "->";
	cin >> selectedOperation;
	
	
	//prompts user to enter the first polynomial, and stores it in p1
	cout << "First Polynomial: " << endl;
	Polynomial *p1 = getInput();
	cout << endl;
	
	
	//prompts user to enter the second polynomial and stores it in p2
	cout << "Second Polynomial: " << endl;
	Polynomial *p2 = getInput();
	cout << endl;
	

	//switch performs operation on polynomials and stores result in pr
	Polynomial *pr = new Polynomial;
	switch(selectedOperation)
	{
		case 1:
			*pr = p1->add(p2);
			break;
		case 2:
			*pr = p1->subtract(p2);
			break;
		default:
			cout <<"Invalid operation choice" << endl;
			break;
	}
	
	//prints result
	pr->print();
	
	
	// releases memory
	delete p1;
	delete p2;
	delete pr;
	
	
	system("pause");
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


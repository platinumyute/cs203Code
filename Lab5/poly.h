#ifndef poly_h
#define poly_h

//*************************************
//start of polynomial class prototype
//*************************************

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

//*************************************
//end of polynomial class prototype
//*************************************

#endif

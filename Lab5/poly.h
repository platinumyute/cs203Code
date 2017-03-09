#ifndef poly_h
#define poly_h

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

#endif

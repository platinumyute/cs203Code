#include <iostream>
#include <cmath>
using namespace std;

const int NUM_POLYGONS = 4; 
const int  TAN_54 = tan(54);
const double ROOT_3 = sqrt(3);

//class prototypes
class Polygon
{
	protected:
		double side;
		double x;
		double y;
		
	public:
		virtual void Area() = 0;
		virtual void Perimeter() = 0;
		virtual void CenterOfGravity() = 0;
		virtual ~Polygon();
};

class Square : public Polygon
{
	public:
		Square();
		Square(double side);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
		virtual ~Square();
};

class Rectangle : public Polygon
{
	private:
		double length;
		double width;
				
	public:
		Rectangle();
		Rectangle(double length, double width);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
		virtual ~Rectangle();
};

class Pentagon : public Polygon
{		
	public:
		Pentagon();
		Pentagon(double side);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
		virtual ~Pentagon() = 0;
};

class Hexagon : public Polygon
{
	public:
		Hexagon();
		Hexagon(double side);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
		virtual ~Hexagon();
};
//end of class prototypes

//class definitions
//square definitions
Square::Square()
{
	side = 0;
}

Square::Square(double side)
{
	this->side = side;
}

void Square::Area()
{
	cout << side * side;
}

void Square::Perimeter()
{
	cout << side * 4;
}

void Square::CenterOfGravity()
{
	x = side/2;
	y = side/2;
	cout << "x: " << x << " y: " << y;
}

Square::~Square()
{
	
}

//Rectangle definitions
Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}

Rectangle::Rectangle(double length, double width) 
{
	this->length = length;
	this->width = width;
}

void Rectangle::Area()
{
	cout << length * width;
}

void Rectangle::Perimeter()
{
	cout << (length + width) * 2;
}

void Rectangle::CenterOfGravity()
{
	x = length/2;
	y = width/2;
	cout << "x: " << x << " y: " << y;
}

Rectangle::~Rectangle()
{
	
}

//Pentagon definitions
Pentagon::Pentagon()
{
	side = 0;
}

Pentagon::Pentagon(double side)
{
	this->side = side;
}

void Pentagon::Area()
{
	cout << (5 * side * side) * TAN_54;
}

void Pentagon::Perimeter()
{
	cout << side * 5;
}

void Pentagon::CenterOfGravity()
{
	x = side/2;
	y = (5 * TAN_54)/2;
	cout << "x: " << x << " y: " << y;
}

Pentagon::~Pentagon()
{
	
}

//Hexagon definitions
Hexagon::Hexagon()
{
	side = 0;
}

Hexagon::Hexagon(double side)
{
	this->side = side;
}

void Hexagon::Area()
{
	cout << (3 * ROOT_3 * side * side)/2;
}

void Hexagon::Perimeter()
{
	cout << side * 6;
}

void Hexagon::CenterOfGravity()
{
	x = side/2;
	y = (ROOT_3 * side)/2;
	cout << "x: " << x << " y: " << y;
}

Hexagon::~Hexagon()
{
	
}

int main()
{
	/*
	//Polygon *p[4] = {new Square(), new Rectangle(), new Pentagon(), new Hexagon()};
	Polygon *p;
	int userInput;
	int shapeIX = userInput - 1;
	string userMsg = "please enter choice";
	cout << userMsg;
	cin >> shapeIX;
	
	p[shapeIX]->Area();
	cout << endl;
	p[shapeIX]->Perimeter();
	cout << endl;
	p[shapeIX]->CenterOfGravity();
	
	//delete polygon array
	for(int i = 0; i < NUM_POLYGONS; i++)
		delete p[i];
	*/
	return 0;
}

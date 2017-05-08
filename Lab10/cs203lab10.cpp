#include <iostream>
#include <cmath>
using namespace std;

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
};

class Square : public Polygon
{
	private:
		
	public:
		Square(double);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
};

class Rectangle : public Polygon
{
	private:
		double length;
		double width;
				
	public:
		Rectangle(double, double);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
};

class Pentagon : public Polygon
{
	private:
		
	public:
		Pentagon(double);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
};

class Hexagon : public Polygon
{
	private:
		
	public:
		Hexagon(double);
		virtual void Area();
		virtual void Perimeter();
		virtual void CenterOfGravity();
};
//end of class prototypes

//class definitions
//square definitions
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

//Rectangle definitions
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


//Pentagon definitions
Pentagon::Pentagon(double side)
{
	this->side = side;
}

void Pentagon::Area()
{
	cout << (5 * side * side) * tan(54);
}

void Pentagon::Perimeter()
{
	cout << side * 5;
}

void Pentagon::CenterOfGravity()
{
	x = side/2;
	y = side/2;
	cout << "x: " << x << " y: " << y;
}

//Hexagon definitions
Hexagon::Hexagon(double side)
{
	this->side = side;
}

void Hexagon::Area()
{
	double root3 = sqrt(3);
	cout << ((3 * root3)/2) * side * side;
}

void Hexagon::Perimeter()
{
	cout << side * 6;
}

void Hexagon::CenterOfGravity()
{
	x = side/2;
	y = side/2;
	cout << "x: " << x << " y: " << y;
}

int main()
{
	Square s(4);
	s.Area();
	cout << endl;
	s.Perimeter();
	cout << endl;
	s.CenterOfGravity();
	return 0;
}

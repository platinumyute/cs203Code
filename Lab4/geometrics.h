#include<iostream>
#include<cmath>

using namespace std;

const double pi = 3.14;

//***********************************//
// start of prototypes
//***********************************//

// class: cube prototype
class Cube 
{
	private:
		double side;
		double volume;

	public:
		void setSide(double Side);	
		void CalculateVolume();
		void PrintVolume();
};

// class sphere prototype 
class Sphere 
{
	private:
		double radius;
		double volume;
	
	public:	
		void setRadius(double Radius);
		void CalculateVolume();
		void PrintVolume();	
};

// class cylinder prototype 
class Cylinder 
{
	private:
		double radius;
		double height;
		double volume;

	public:
		void setRadius(double Radius);
		void setHeight(double Height);
		void CalculateVolume();
		void PrintVolume();
};

//***********************************//
//end of prototypes
//***********************************//


//***********************************//
// start of implementation
//***********************************//

// class: cube implementation
void Cube::setSide(double Side)
{
	this->side = Side;
}	
		
void Cube::CalculateVolume()
{
	this->volume = pow(this->side, 3);
}

void Cube::PrintVolume()
{
	cout << "The volume of a cube with side: " << this->side << ", is " << this->volume << endl;
}

// class: sphere implementation
void Sphere::setRadius(double Radius)
{
	this->radius = Radius;
}

void Sphere::CalculateVolume()
{
	double c = 4.0/3.0;
	double rc = pow(this->radius, 3);
	
	this->volume = c * pi * rc;
}

void Sphere::PrintVolume()
{
	cout << "The volume of a sphere with radius: " << this->radius << ", is " << this->volume << endl;
}

// class: cylinder implementation
void Cylinder::setRadius(double Radius)
{
	this->radius = Radius;
}

void Cylinder::setHeight(double Height)
{
	this->height = Height;
}

void Cylinder::CalculateVolume()
{
	double rs = pow(this->radius, 2);
	
	this->volume = pi * rs * this->height;
}

void Cylinder::PrintVolume()
{
	cout << "The volume of a cylinder with radius: " << this->radius << ", and height: " << this->height << ", is " << this->volume << endl;
}


//***********************************//
// end of implementation
//***********************************//

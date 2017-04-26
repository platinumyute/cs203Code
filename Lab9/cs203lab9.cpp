// --------------------------------------------------------------------------------
// Name: Josiah Zailabdeen, Ki Hoon Kim, Tabish CS 203 Lab 08
// Description: this program simulates a text editor
//				perform simple tasks such as inserting, removing, and display text
// --------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib> 
#include <iomanip> 

using namespace std;

//*****************************
//Class Prototypes
//*****************************

class Vector2D
{
	protected:
		int x;
		int y;
	
	public:
		Vector2D();
		Vector2D(int x, int y);
		int getX();
		int getY();
		~Vector2D();
};

class Vector3D : public Vector2D
{
	private:
		int z;
	
	public:
		Vector3D();
		Vector3D(int x, int y, int z);
		int getZ();
		int calculateDotProduct(Vector3D vector);
		Vector3D calculateCrossProduct(Vector3D vector);
		void printVector();
		~Vector3D();
};

//*****************************
//Class Definitions
//*****************************


//start of Vector2D definition
Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}
Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}
Vector2D::~Vector2D()
{	
}

int Vector2D::getX()
{
	return x;
}

int Vector2D::getY()
{
	return y;
}
//end of Vector2D definition

//start of Vector3D definitons
Vector3D::Vector3D()
{
	z = 0;
}
Vector3D::Vector3D(int x, int y, int z) : Vector2D(x, y)
{
	this->z = z;
}

Vector3D::~Vector3D()
{
}

int Vector3D::getZ()
{
	return z;
}

int Vector3D::calculateDotProduct(Vector3D vector)
{
	int sum = (x * vector.x) + (y * vector.y) + (z * vector.z);
	return sum;
}

Vector3D Vector3D::calculateCrossProduct(Vector3D vector)
{
	int rx = (y * vector.z) - (z * vector.y);
	int ry = (z * vector.x) - (x * vector.z);
	int rz = (x * vector.y) - (y * vector.x);
	
	Vector3D result(rx, ry, rz);
	return result;
}

void Vector3D::printVector()
{
	cout << "<" << x << ", " << y << ", " << z << ">";
}
//end of Vector3D definition
//end of class definitions


//function prototypes
void getVectorInput(Vector3D &vector);
void calculateAndPrintDotProduct(Vector3D &vector1, Vector3D &vector2);
void calculateAndPrintCrossProduct(Vector3D &vector1, Vector3D &vector2);

int main()
{
	Vector3D vector1;
	Vector3D vector2;
	
	cout << "First vector: " << endl;
	getVectorInput(vector1);
	cout << endl;
	
	cout << "Second vector: " << endl;
	getVectorInput(vector2);
	cout << endl;
	
	calculateAndPrintDotProduct(vector1, vector2);
	calculateAndPrintCrossProduct(vector1, vector2);

	return 0;
}

void getVectorInput(Vector3D &vector)
{
	int x,y,z;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	vector = Vector3D(x, y, z);
}

void calculateAndPrintDotProduct(Vector3D &vector1, Vector3D &vector2)
{
	int dotProduct = vector1.calculateDotProduct(vector2);
	cout << "The dot product of ";
	vector1.printVector();
	cout << " and ";
	vector2.printVector();
	cout << " is ";
	cout << dotProduct;
	cout << endl;
}

void calculateAndPrintCrossProduct(Vector3D &vector1, Vector3D &vector2)
{
	Vector3D crossProduct = vector1.calculateCrossProduct(vector2);
	cout << "The cross product of ";
	vector1.printVector();
	cout << " and ";
	vector2.printVector();
	cout << " is ";
	crossProduct.printVector();
}

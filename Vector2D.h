#ifndef VECTOR_2D
#define VECTOR_2D

using namespace std;

// Class
class Vector2D
{
public:
	// Variable Declarations:
	double x;
	double y;
	// Constructor(s):
	Vector2D(); // Default
	Vector2D(double in_x, double in_y);
};

// Overloaded operators
Vector2D operator * (Vector2D, double);
Vector2D operator / (Vector2D, double);
ostream& operator << (ostream&, Vector2D);


#endif

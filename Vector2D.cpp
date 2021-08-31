#include <iostream>
#include "Vector2D.h"
using namespace std;

// Constructors
Vector2D::Vector2D() // Default
{
	x = 0;
	y = 0;		
}

Vector2D::Vector2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}


// Non-Member Overloaded Operators
Vector2D operator * (Vector2D v1, double d)
{
	// Multiplies vector components by a double
	// Returns a new vector

	Vector2D out((v1.x * d), (v1.y * d));
	return out;
}

Vector2D operator / (Vector2D v1, double d)
{
  // Divides vector componenets by a double
  // Returns a new vector

  Vector2D out((v1.x/d), (v1.y/d));
  return out;
}

ostream& operator << (ostream& out, Vector2D v)
{
	// Formats printing of vectors

	out << "<" << v.x << "," << v.y << ">";
	return out;
}

#include <iostream>
#include <math.h>
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;

// Constructors
Point2D::Point2D() // Default
{
	x = 0;
	y = 0;		
}


Point2D::Point2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}


// Non-Member Functions
double GetDistanceBetween(Point2D p1, Point2D p2)
{
	// Returns distance between 2 points
	
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}


// Non-Member Overloaded Operators
ostream& operator << (ostream& out, Point2D p1)
{
	// Formats printing of points

	out << "(" << p1.x << "," << p1.y << ")";
	return out;
}

Point2D operator + (Point2D p1, Vector2D v1)
{
	// Adds corresponding componenets of a point and vector
	// Returns a new Point2D

	Point2D out((p1.x + v1.x), (p1.y + v1.y));
	return out;
}

Vector2D operator - (Point2D p1, Point2D p2)
{
  // Subtracts corresponding componenets of two points
  // Returns a new vector

  Vector2D out((p1.x - p2.x), p1.y - p2.y);
  return out;
}

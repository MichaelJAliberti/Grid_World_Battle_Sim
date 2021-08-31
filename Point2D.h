#ifndef POINT_2D
#define POINT_2D

#include "Vector2D.h"
using namespace std;

// Class
class Point2D
{
public:
	// Variable Declarations:
	double x;
	double y;
	// Constructor(s):
	Point2D(); // Default
	Point2D(double in_x, double in_y);
};

// Non-member functions
double GetDistanceBetween(Point2D, Point2D);

// Overloaded operators
ostream& operator << (ostream&, Point2D);
Point2D operator + (Point2D, Vector2D);
Vector2D operator - (Point2D, Point2D);

#endif

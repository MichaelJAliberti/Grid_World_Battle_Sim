#ifndef VIEW
#define VIEW

#include "Point2D.h"
#include "GameObject.h"

// External constant
const int view_maxsize = 20;

// Class
class View
{
public:
	// Private member variables
	int size;
	double scale;
	Point2D origin;
	char grid[view_maxsize][view_maxsize][2];
	// Private member functions
	bool GetSubscripts(int &out_x, int &out_y, Point2D location);
public:
	// Constructors
	View(); // default
	// Public member functions
	void Clear();
	void Plot(GameObject* ptr);
	void Draw();
};

#endif
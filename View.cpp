#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "View.h"


// Constructors
View::View() // default
{
	// Variable declarations
	size = 11;
	scale = 2;
}


// Private member functions
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	out_x = ((location - origin) / scale).x;
	out_y = ((location - origin) / scale).y;
	if (out_x > size - 1 || out_x < 0 || out_y > size - 1 || out_y < 0)
	{
		// False if off-screen
		cout << "An object is outside the display" << endl;
		return false;
	}
	else
		return true;
}


// Public member functions
void View::Clear()
{
	// Set up the clear field

	// Set up grid points
	for (int j = 0; j < size; j++)
		for (int i = 0; i < size; i++)
		{
			grid[j][i][0] = '.';
			grid[j][i][1] = ' ';
		}
}

void View::Plot(GameObject* ptr)
{
	// Plots object pointed to on grid

	// Initialize temporary locational variables
	int x;
	int y;
	// Call GetSubscripts
	if (View::GetSubscripts(x, y, ptr->GetLocation()))
		if (!ptr->ShouldBeVisible())
		{
			grid[y][x][0] = '.';
			grid[y][x][1] = ' ';
		}
		else if (grid[y][x][0] != '.')
		{
			grid[y][x][0] = '*';
			grid[y][x][1] = ' ';
		}
		else
			ptr->DrawSelf(grid[y][x]);
}

void View::Draw()
{
	// Draw the grid

	for (int j = size-1; j >= 0; j--)
	{
		// Print y scale info
		if (j % 2 == 0)
		{
			if (j * scale < 10)
				cout << j * scale << " ";
			else
				cout << j * scale;
		}
		else
			cout << "  ";
		// Print grid
		for (int i = 0; i < size; i++)
		{
			cout << grid[j][i][0];
			cout << grid[j][i][1];
		}
		cout << endl;
	}
	// Print x scale info
	cout << "  ";
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			if (i * scale < 10)
				cout << i * scale << " ";
			else
				cout << i * scale;
		}
		else
			cout << "  ";
	}
	cout << endl;
}

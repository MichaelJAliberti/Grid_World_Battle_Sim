#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
using namespace std;

// Constructors
GameObject::GameObject(char in_code)
{
	// Variable initialization
	id_num = 1;
	display_code = in_code;
	state = 0;
	// Announcement
	cout << "GameObject constructed." << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
	// Variable initialization	
	location = in_loc;	
	id_num = in_id;
	display_code = in_code;
	state = 0;
	// Announcement
	cout << "GameObject constructed." << endl;
}


// Destructor
GameObject::~GameObject()
{
	cout << "GameObject destructed." << endl;
}


// Member Functions
Point2D GameObject::GetLocation()
{
	// Returns the location of the GameObject
	
	return location;
}

int GameObject::GetId()
{
	// Returns the id_num of the GameObject

	return id_num;
}

bool GameObject::GetState()
{
	// Returns the state of the GameObject

	return state;
}

void GameObject::ShowStatus()
{
	// Prints the status of the GameObject 	

	cout << display_code << id_num << " at " << location;
}

void GameObject::DrawSelf(char* ptr)
{
	// Plots GameObject display_code then id_num

	ptr[0] = display_code;
	ptr[1] = '0' + id_num;
}


// Added member functions
char GameObject::GetDisplayCode()
{
	// Returns display_code

	return display_code;
}
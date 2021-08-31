#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
using namespace std;

// Constructors
Building::Building(): GameObject('B') // default
{
	// Variable initialization	
	pokemon_count = 0;
	// Announcement
	cout << "Building default constructed." << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc): GameObject(in_loc, in_id, in_code)
{
	// Variable Initialization
	pokemon_count = 0;
	// Announcement
	cout << "Building constructed." << endl;
}


// Destructor
Building::~Building()
{
	cout << "Building destructed." << endl;
}


// Member Functions
void Building::AddOnePokemon()
{
	// Adds 1 Pokemon to Building

	pokemon_count++;
}

void Building::RemoveOnePokemon()
{
	// Removes 1 Pokemon from Building

	if (pokemon_count > 0)
		pokemon_count--;
	else
		cout << "There are no pokemon in this building" << endl;
	return;
}

void Building::ShowStatus()
{
	// Displays the number of pokemon in the Building
	cout << display_code << id_num << " located at " << location << endl;
	if (pokemon_count == 1)
		cout << "\t" << pokemon_count << " pokemon is in this building" << endl;
	else
		cout << "\t" << pokemon_count << " pokemon are in this building" << endl;
}

bool Building::ShouldBeVisible()
{
	// Returns true because buildings are always visible

	return true;
}
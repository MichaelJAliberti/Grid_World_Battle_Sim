#include <iostream>
#include "Point2D.h"
#include "Building.h"
#include "GameObject.h"
#include "PokemonCenter.h"
using namespace std;

// Constructors
PokemonCenter::PokemonCenter(): Building() // Default
{
	// Variable Initialization
	display_code = 'C';
	stamina_capacity = 100;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5.0;
	state = STAMINA_POINTS_AVAILABLE;
	// Announcement
	cout << "PokemonCenter default constructed." << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc): Building('C', in_id, in_loc)
{
	// Variable Initialization	
	dollar_cost_per_stamina_point = stamina_cost;
	stamina_capacity = stamina_cap;
	// Default Variables
	num_stamina_points_remaining = stamina_capacity;
	state = STAMINA_POINTS_AVAILABLE;
	// Announcement
	cout << "PokemonCenter constructed." << endl;
}


// Destructor
PokemonCenter::~PokemonCenter()
{
	cout << "PokemonCenter destructed." << endl;
}


// Member Functions
bool PokemonCenter::HasStaminaPoints()
{
	// Returns true if 1 or more stamina points remaining

	if (num_stamina_points_remaining >= 1)
		return true;
	else
		return false;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
	// Returns number of stamina points left in Pokemon Center

	return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
	// Returns true if Pokemon can afford to purchase stamina points w/ budget

	if (stamina_points <= budget/dollar_cost_per_stamina_point)
		return true;
	else
		return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
	// Returns dollar cost of stamina_points

	return stamina_points * dollar_cost_per_stamina_point;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
	// Subtracts points_needed from Pokemon Center and returns it if Center has enough stamina
	// Otherwise, sets Center's stamina to zero and returns what remains

	if (num_stamina_points_remaining < points_needed)
	{
		// Number stamina points is less, set stamina stored to zero
		int current_stamina = num_stamina_points_remaining;
		num_stamina_points_remaining = 0;
		return current_stamina;
	}
	else 
	{
		// Subtracts amount requested from total and returns it
		num_stamina_points_remaining -= points_needed;
		return points_needed;
	}
}

bool PokemonCenter::Update()
{
	// Returns True and changes values if this is the first time this function
	// is called and no stamina points remain; otherwise return False

	if (state == STAMINA_POINTS_AVAILABLE)
	{
		if (num_stamina_points_remaining == 0)
		{
			state = NO_STAMINA_POINTS_AVAILABLE;
			display_code = 'c';
			cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl; 
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void PokemonCenter::ShowStatus()
{
	// Prints out info about Pokemon center

	cout << "Pokemon Center Status: ";
	Building::ShowStatus();
	cout << "\tPokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
	cout << "\thas " << num_stamina_points_remaining << " stamina point(s) remaining" << endl; 
}
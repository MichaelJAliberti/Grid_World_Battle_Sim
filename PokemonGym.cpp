#include <iostream>
#include <iomanip>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
using namespace std;

// Constructors
PokemonGym::PokemonGym(): Building() // Default
{
	// Variable Declarations
	display_code = 'G';
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	// Announcement
	cout << "PokemonGym default constructed." << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double
	dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc): Building('G', in_id, in_loc)
{
	// Variable Declarations
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost;
	// Announcement
	cout << "PokemonGym constructed." << endl;
}


// Destructor
PokemonGym::~PokemonGym()
{
	cout << "PokemonGym destructed." << endl;
}


// Member Functions
double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	// Returns cost of purchasing unit_qty training units

	return unit_qty * dollar_cost_per_training_unit;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	// Returns the amount of stamina required for unit_qty training units

	return unit_qty * stamina_cost_per_training_unit;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	// Returns the number of training units remaining in this Pokemon Gym

	return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	// Return's true if Budget and Stamina are sufficient to tain unit_qty training units
	// Returns false if not

	if (budget >= GetDollarCost(unit_qty) && stamina >= GetStaminaCost(unit_qty))
		return true;
	else
		return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	// Subtracts training units from Pokemon Gym if Center has enough stamina
	// Otherwise, sets Gym's training units to zero and returns what remains
	// Returns experience based on training units used

	if (num_training_units_remaining < training_units)
	{
		// Number training units reamining is less, set training units remaining to zero
		int current_units = num_training_units_remaining;
		num_training_units_remaining = 0;
		return current_units * experience_points_per_training_unit;
	}
	else 
	{
		// Subtracts amount requested from total and returns it
		num_training_units_remaining -= training_units;
		return training_units * experience_points_per_training_unit;
	}
}

bool PokemonGym::Update()
{
	// Returns True and changes values if this is the first time this function
	// is called and no training units remain; otherwise return False

	if (state == NOT_BEATEN)
	{
		if (num_training_units_remaining == 0)
		{
			state = BEATEN;
			display_code = 'g';
			cout << display_code << id_num << " has been beaten" << endl; 
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool PokemonGym::IsBeaten()
{
	// Returns true if  training units remaining is 0

	if (num_training_units_remaining == 0)
		return true;
	else
		return false;
}

void PokemonGym::ShowStatus()
{
	// Prints out info on Pokemon Gym

	cout << "Pokemon Gym Status: ";
	Building::ShowStatus();
	cout << "\tMax number of training units: " << max_number_of_training_units << endl;
	cout << "\tStamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "\tPokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "\tExperience points per training unit: " << experience_points_per_training_unit << endl;
	cout << "\t" << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
}
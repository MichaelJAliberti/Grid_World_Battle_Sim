#include <iostream>
#include <string>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "BattleArena.h"
using namespace std;

// Constructors
BattleArena::BattleArena(): Building('A', 0, Point2D()) // default
{
	// Variable declaration
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	// Announcmenet
	cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc): Building('A', in_id, in_loc)
{
	// Variable declarations
	pokemon_count = 0;
	max_num_rivals = max_rivals;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = dollar_cost;
	stamina_cost_per_fight = stamina_cost;
	state = RIVALS_AVAILABLE;
	// Announcmenet
	cout << "BattleArena constructed" << endl;
}


// Destructor
BattleArena::~BattleArena()
{
	cout << "BattleArena destructed" << endl;
}


// Public Member Functions
unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if (num_rivals_remaining >= 1)
		return true;
	else
		return false;
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	if (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight)
		return true;
	else
		return false;
}

bool BattleArena::Update()
{
	if (state == NO_RIVALS_AVAILABLE)
		return false;
	else if (num_rivals_remaining == 0)
	{
		state = NO_RIVALS_AVAILABLE;
		return true;
	}
	else
		return false;
}

bool BattleArena::IsBeaten()
{
	if (state == NO_RIVALS_AVAILABLE)
		return true;
	else
		return false;
}

void BattleArena::ShowStatus()
{
	cout << "Battle Arena: ";
	Building::ShowStatus();
	cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
	cout << "\tPokemon dollar cost per fight: " << dollar_cost_per_fight << endl;
	cout << "\t" << num_rivals_remaining << " rival(s) are remaining for this arena" << endl;
}


// Added functions
void BattleArena::AddOneRival()
{
	// Adds 1 Pokemon to Building

	num_rivals_remaining++;
}

void BattleArena::RemoveOneRival()
{
	// Removes 1 Pokemon from Building

	if (num_rivals_remaining > 0)
		num_rivals_remaining--;
	else
		cout << "There are no rival(s) in this battle arena" << endl;
	return;
}
#ifndef BATTLEARENA
#define BATTLEARENA

#include <string>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"

// Enumerated types
enum BattleArenaStates
{
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};

// Class
class BattleArena: public Building
{
private:
	// Private member variables
	unsigned int max_num_rivals;
	unsigned int num_rivals_remaining;
	double dollar_cost_per_fight;
	unsigned int stamina_cost_per_fight;
	unsigned int pokemon_count;
public:
	// Constructors
	BattleArena();
	BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc);
	// Destructor
	~BattleArena();
	// Public member functions
	unsigned int GetNumRivalsRemaining();
	bool HasEnoughRivals();
	double GetDollarCost();
	unsigned int GetStaminaCost();
	bool IsAbleToFight(double budget, unsigned int stamina);
	bool Update();
	bool IsBeaten();
	void ShowStatus();
	// Added functions
	void AddOneRival();
	void RemoveOneRival();
};

#endif
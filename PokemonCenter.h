#ifndef POKECENTER
#define POKECENTER

#include "Point2D.h"
#include "Building.h"

// Enumerated Types
enum PokemonCenterStates
{
	STAMINA_POINTS_AVAILABLE = 0,
	NO_STAMINA_POINTS_AVAILABLE = 1
};

// Class
class PokemonCenter: public Building
{
private:
	// Private variables
	unsigned int stamina_capacity;
	unsigned int num_stamina_points_remaining;
	double dollar_cost_per_stamina_point;
public:
	// Public constructors
	PokemonCenter(); // Default constructor
	PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);
	// Destructor
	~PokemonCenter();
	// Public functions
	bool HasStaminaPoints();
	unsigned int GetNumStaminaPointsRemaining();
	bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
	double GetDollarCost(unsigned int stamina_points);
	unsigned int DistributeStamina(unsigned int points_needed);
	bool Update();
	void ShowStatus();
};

#endif
#ifndef BUILDING
#define BUILDING

#include "Point2D.h"
#include "GameObject.h"

// Class
class Building: public GameObject
{
private:
	// Private variables
	unsigned int pokemon_count;
public:
	// Public constructors
	Building(); // Default constructor
	Building(char in_code, int in_id, Point2D in_loc);
	// Destructor
	~Building();
	// Public functions
	void AddOnePokemon();
	void RemoveOnePokemon();
	void ShowStatus();
	bool ShouldBeVisible();
};

#endif
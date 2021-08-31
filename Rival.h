#ifndef RIVAL
#define RIVAL

#include <string>
#include "Point2D.h"
#include "GameObject.h"
#include "BattleArena.h"

// Enumerated types
enum RivalStates
{
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

// Class
class Rival: public GameObject
{
protected:
	// Protected member variables
	string name;
	double speed;
	double health;
	double physical_damage;
	double magical_damage;
	double defense;
	bool is_in_arena;
	BattleArena* current_arena;
public:
	// Public constructor
	Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc, BattleArena* base);
	// Destructor
	~Rival();
	// Public member functions
	void TakeHit(double physical_damage, double magical_damage, double defense);
	double GetPhysDmg();
	double GetMagicDmg();
	double GetDefense();
	double GetHealth();
	bool Update();
	void ShowStatus();
	bool IsAlive();
	// Added functions
	bool ShouldBeVisible();
};

#endif
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Point2D.h"
#include "GameObject.h"
#include "Rival.h"
#include "BattleArena.h"
using namespace std;

// Constructor
Rival::Rival(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, Point2D in_loc, BattleArena* base): GameObject(in_loc, in_id, 'R')
{
	// Variable declarations
	name = in_name;
	speed = in_speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	current_arena = base;
	// Check if in arena
	if (in_loc.x == base->GetLocation().x && in_loc.y == base->GetLocation().y)
	{
		is_in_arena = true;
		base->AddOneRival();
	}
	else
		is_in_arena = false;
	// Announcmenet
	cout << "Rival constructed." << endl;
}


// Destructors
Rival::~Rival()
{
	cout << "Rival destructed" << endl;
}


// Public member functions
void Rival::TakeHit(double physical_dmg, double magical_dmg, double def)
{
	// Variable declarations
	int attackChoice;
	double damage;
	// Half chance magic, half chance physical
	attackChoice = rand() % 2;
	// If physical:
	if (attackChoice == 0)
	{
		damage = (100.0 - def)/100 * physical_dmg;
		cout << "Aaagh. no physical pain no gain!" << endl;
	}
	// If magical
	else
	{
		damage = (100.0 - def)/100 * magical_dmg;
		cout << "Ouch, I don't believe in magic!" << endl;
	}
	cout << "Damage: " << damage << endl;
	health -= damage;
	cout << "Health: " << health << endl;
	cout << "*******" << endl;
	return;
}

double Rival::GetPhysDmg()
{
	return physical_damage;
}

double Rival::GetMagicDmg()
{
	return magical_damage;
}

double Rival::GetDefense()
{
	return defense;
}

double Rival::GetHealth()
{
	return health;
}

bool Rival::Update()
{
	if (state == ALIVE_RIVAL)
	{
		if (!Rival::IsAlive())
		{
			state = FAINTED_RIVAL;
			return true;
		}
	}
	else
		return false;
}

void Rival::ShowStatus()
{
	// Basic info
	cout << name << " status: ";
	GameObject::ShowStatus();
	// Behavioral info
	if (Rival::IsAlive())
		cout << " alive" << endl;
	else
		cout << " dead, RIP" << endl;
	cout << "\tHealth: " << health << endl;
	cout << "\tPhysical Damage: " << physical_damage << endl;
	cout << "\tMagical Damage: " << magical_damage << endl;
	cout << "\tDefense: " << defense << endl;
}

bool Rival::IsAlive()
{
	if (health > 0)
		return true;
	else
		return false;
}


// Added Functions
bool Rival::ShouldBeVisible()
{
	// Returns true if this Rival is Not exhausted

	if (state != FAINTED_RIVAL)
		return true;
	else
		return false;
}


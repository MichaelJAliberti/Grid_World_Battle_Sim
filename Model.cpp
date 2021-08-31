#include <iostream>
#include <stdlib.h>
#include "Point2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"
using namespace std;


// Contructor
Model::Model()
{
	// Initialize variables
	time = 0;
	// Pokemon 1
	Pokemon* Pokemon1 = new Pokemon("Pikachu", 2, 23, 3, 6, 12, 1, 'P', Point2D(5, 1));
	object_ptrs.push_back(Pokemon1);
	pokemon_ptrs.push_back(Pokemon1);
	// Pokemon 2
	Pokemon* Pokemon2 = new Pokemon("Bulbasaur", 1, 26, 4, 3.7, 16, 2, 'P', Point2D(10, 1));
	object_ptrs.push_back(Pokemon2);
	pokemon_ptrs.push_back(Pokemon2);
	// PokemonCenter 1
	PokemonCenter* PokemonCenter1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
	object_ptrs.push_back(PokemonCenter1);
	center_ptrs.push_back(PokemonCenter1);
	// PokemonCenter 2
	PokemonCenter* PokemonCenter2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
	object_ptrs.push_back(PokemonCenter2);
	center_ptrs.push_back(PokemonCenter2);
	// PokemonGym 1 (supposed to be default but this aligns better with sample output)
	PokemonGym* PokemonGym1 = new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0, 0));
	object_ptrs.push_back(PokemonGym1);
	gym_ptrs.push_back(PokemonGym1);
	// PokemonGym 2
	PokemonGym* PokemonGym2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5));
	object_ptrs.push_back(PokemonGym2);
	gym_ptrs.push_back(PokemonGym2);
	// Battle Arena 1 (first half)
	BattleArena* BattleArena1 = new BattleArena(0, 3, 2.5, 1, Point2D(15, 12));
	// Rival 1
	Rival* Rival1 = new Rival("Scary Gary", 0, 16, 3, 7.2, 20, 1, Point2D(15, 12), BattleArena1);
	object_ptrs.push_back(Rival1);
	rival_ptrs.push_back(Rival1);
	// Rival 2
	Rival* Rival2 = new Rival("Hairy Larry", 0, 29, 4, 5.2, 12, 2, Point2D(15, 12), BattleArena1);
	object_ptrs.push_back(Rival2);
	rival_ptrs.push_back(Rival2);
	// Battle Arena 1 (second half)
	object_ptrs.push_back(BattleArena1);
	arena_ptrs.push_back(BattleArena1);
	// Establish active_ptrs
	active_ptrs = object_ptrs;
	// Announcement
	cout << "Model default constructed." << endl;
}


// Destructor
Model::~Model()
{
	for (it_object = object_ptrs.begin(); it_object != object_ptrs.end(); it_object++)
		delete *it_object;
	cout << "Model destructed." << endl;
}


// Public member functions
Pokemon* Model::GetPokemonPtr(int id)
{
	// Returns a Pokemon pointer that corresponds to the given id

	for (it_pokemon = pokemon_ptrs.begin(); it_pokemon != pokemon_ptrs.end(); it_pokemon++)
		if ((*it_pokemon)->GetId() == id)
			return *it_pokemon;
	throw Invalid_Input("No Pokemon with this ID");
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	// Returns a PokemonCenter pointer which corresponds to the given id

	for (it_center = center_ptrs.begin(); it_center != center_ptrs.end(); it_center++)
		if ((*it_center)->GetId() == id)
			return *it_center;
	throw Invalid_Input("No PokemonCenter with this ID");
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	// Returns a PokemonGym pointer which corresponds to the given id

	for (it_gym = gym_ptrs.begin(); it_gym != gym_ptrs.end(); it_gym++)
		if ((*it_gym)->GetId() == id)
			return *it_gym;
	throw Invalid_Input("No PokemonGym with this ID");
}

BattleArena* Model::GetArenaPtr(int id)
{
	// Returns a BattleArena pointer which corresponds to the given id

	for (it_arena = arena_ptrs.begin(); it_arena != arena_ptrs.end(); it_arena++)
		if ((*it_arena)->GetId() == id)
			return *it_arena;
	throw Invalid_Input("No BattleArena with this ID (Symbol 2)");
}

Rival* Model::GetRivalPtr(int id)
{
	// Returns a Rival pointer which corresponds to the given id

	for (it_rival = rival_ptrs.begin(); it_rival != rival_ptrs.end(); it_rival++)
		if ((*it_rival)->GetId() == id)
			return *it_rival;
	throw Invalid_Input("No Rival with this ID (Symbol 2)");
}

bool Model::Update()
{
	// Increment time
	time++;
	// Temporart truth holder
	bool tempTruth = true;
	// Spring cleaning
	while (tempTruth)
	{
		tempTruth = false;
		for (it_object = active_ptrs.begin(); it_object != active_ptrs.end(); it_object++)
			if (!(*it_object)->ShouldBeVisible())
			{
				// If object is "dead," restart cycle and print message
				active_ptrs.erase(it_object);
				tempTruth = true;
				cout << "Dead object removed" << endl;
				break;
			}
	}
	// Ensure integrity of temporary truth holder
	tempTruth = false;
	// Update all and see if any yield true
	for (it_object = active_ptrs.begin(); it_object != active_ptrs.end(); it_object++)
		if ((*it_object)->Update())
			tempTruth = true;
	// Return true immediately if any updates are true; oterwise, check win/fail states
	if (tempTruth)
		return true;

	/*else if (gym_ptrs[0]->IsBeaten() && gym_ptrs[1]->IsBeaten())
	{
		cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
		exit(0);
	}
	else if (pokemon_ptrs[0]->IsExhausted() && pokemon_ptrs[1]->IsExhausted())
	{
		// Dude you suck uninstall the game
		cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
		exit(0);
	}*/
}

void Model::Display(View& view)
{
	// Graph objects
	view.Clear();
	for (it_object = object_ptrs.begin(); it_object != object_ptrs.end(); it_object++)
		view.Plot(*it_object);
	view.Draw();
}

void Model::ShowStatus()
{
	// Outputs the status of all GameObjects by calling their ShowStatus() functions

	// Output time
	cout << "Time: " << time << endl;
	// Show status per object 
	for (it_object = object_ptrs.begin(); it_object != object_ptrs.end(); it_object++)
		(*it_object)->ShowStatus();
}

void Model::NewCommand(char type, int in_id, double x, double y)
{
	// Check if ID number is within acceptable range
	if (in_id < 1 || in_id > 9)
		throw Invalid_Input("ID numbers must be between 1 and 9 (Symbol 3)");
	// Determine building type
	switch (type)
	{
		case 'g':
		{
			// Check duplicates
			for (it_gym = gym_ptrs.begin(); it_gym != gym_ptrs.end(); it_gym++)
			{
				if (in_id == (*it_gym)->GetId())
				{
					//throw exception
					throw Invalid_Input("ID number already exists! (Symbol 3)");
				}
			}
			// Initialize and add new object
			PokemonGym* temp_gym = new PokemonGym(15, 3, 6, 5, in_id, Point2D(x, y));
			object_ptrs.push_back(temp_gym);
			active_ptrs.push_back(temp_gym);
			gym_ptrs.push_back(temp_gym);
			break;
		}
		case 'r':
		{
			// Check duplicates
			for (it_rival = rival_ptrs.begin(); it_rival != rival_ptrs.end(); it_rival++)
			{
				if (in_id == (*it_rival)->GetId())
				{
					//throw exception
					throw Invalid_Input("ID number already exists! (Symbol 3)");
				}
			}
			// Initialize and add new object
			Rival* temp_rival = new Rival("Weary Carrie", 1, 30, 5, 4, 16, in_id, Point2D(x, y), *(arena_ptrs.begin()));
			object_ptrs.push_back(temp_rival);
			active_ptrs.push_back(temp_rival);
			rival_ptrs.push_back(temp_rival);
			break;
		}
		case 'p':
		{
			// Check duplicates
			for (it_pokemon = pokemon_ptrs.begin(); it_pokemon != pokemon_ptrs.end(); it_pokemon++)
			{
				if (in_id == (*it_pokemon)->GetId())
				{
					//throw exception
					throw Invalid_Input("ID number already exists! (Symbol 3)");
				}
			}
			// Initialize and add new object
			Pokemon* temp_poke = new Pokemon("Bidoulf", in_id, 'P', 1.5, Point2D(x, y));
			object_ptrs.push_back(temp_poke);
			active_ptrs.push_back(temp_poke);
			pokemon_ptrs.push_back(temp_poke);
			break;
		}
		case 'c':
		{
			// Check duplicates
			for (it_center = center_ptrs.begin(); it_center != center_ptrs.end(); it_center++)
			{
				if (in_id == (*it_center)->GetId())
				{
					//throw exception
					throw Invalid_Input("ID number already exists! (Symbol 3)");
				}
			}
			// Initialize and add new object
			PokemonCenter* temp_cent = new PokemonCenter(in_id, 3, 100, Point2D(x, y));
			object_ptrs.push_back(temp_cent);
			active_ptrs.push_back(temp_cent);
			center_ptrs.push_back(temp_cent);
			break;
		}
		default:
			throw Invalid_Input("GameObject type does not exist! (Symbol 2)");
	}
	return;
}

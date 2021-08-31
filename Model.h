#ifndef MODEL
#define MODEL

#include <list>
#include <iterator>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"

// Class
class Model
{
private:
	// Private Member Variables
	int time;
	// Lists
	list <GameObject*> object_ptrs;
	list <GameObject*> active_ptrs;
	list <Pokemon*> pokemon_ptrs;
	list <PokemonCenter*> center_ptrs;
	list <PokemonGym*> gym_ptrs;
	list <Rival*> rival_ptrs;
	list <BattleArena*> arena_ptrs;
	// Iterators
	list <GameObject*> :: iterator it_object;
	list <Pokemon*> :: iterator it_pokemon;
	list <PokemonCenter*> :: iterator it_center;
	list <PokemonGym*> :: iterator it_gym;
	list <Rival*> :: iterator it_rival;
	list <BattleArena*> :: iterator it_arena;
public:
	// Public constructors
	Model();
	// Destructor
	~Model();
	// Public member functions
	Pokemon* GetPokemonPtr(int id);
	PokemonCenter * GetPokemonCenterPtr(int id);
	PokemonGym * GetPokemonGymPtr(int id);
	bool Update();
	void Display(View& view);
	void ShowStatus();
	// Added for PA4
	BattleArena* GetArenaPtr(int id);
	Rival* GetRivalPtr(int id);
	void NewCommand(char type, int in_id, double x, double y);
};

#endif
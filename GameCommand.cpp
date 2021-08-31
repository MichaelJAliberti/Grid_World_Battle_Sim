#include <iostream>
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
	// Moves pokemon to p1 if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL)
	{
		// Ensure pokemon exists
		cout << "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to " << p1 << endl;
		model.GetPokemonPtr(pokemon_id)->StartMoving(p1);
		return;
	}
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
	// Moves pokemon to center with center_id if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL || model.GetPokemonCenterPtr(center_id) == NULL)
	{
		// Ensure pokemon  and center exist
		cout << "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to center " << center_id << endl;
		model.GetPokemonPtr(pokemon_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
		return;
	}
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
	// Moves pokemon to center with center_id if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL || model.GetPokemonGymPtr(gym_id) == NULL)
	{
		// Ensure pokemon and gym exist
		cout << "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to gym " << gym_id << endl;
		model.GetPokemonPtr(pokemon_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
		return;
	}
}

void DoStopCommand(Model& model, int pokemon_id)
{
	// Stops pokemon if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL)
	{
		// Ensure pokemon exists
		cout << "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Stopping " << model.GetPokemonPtr(pokemon_id)->GetName() << " " << model.GetPokemonPtr(pokemon_id)->GetDisplayCode() << pokemon_id << endl;
		model.GetPokemonPtr(pokemon_id)->Stop();
		return;
	}
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
	// Initiates pokemon training if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL)
	{
		// Ensure pokemon exists
		cout << "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Training " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
		model.GetPokemonPtr(pokemon_id)->StartTraining(training_units);
		return;
	}
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
	// Initiates pokemon healthcare if commands are valid

	if (model.GetPokemonPtr(pokemon_id) == NULL)
	{
		// Ensure pokemon exists
		cout <<+ "Error: Please enter a valid command!" << endl;
		return;
	}
	else
	{
		// Post-error check
		cout << "Recovering " << model.GetPokemonPtr(pokemon_id)->GetName() << "'s stamina"<< endl;
		model.GetPokemonPtr(pokemon_id)->StartRecoveringStamina(stamina_points);
		return;
	}
}

void DoGoCommand(Model& model, View& view)
{
	// Announcement
	cout << "Advancing one tick." << endl;
	// Update
	model.Update();
	// Output
	model.ShowStatus();
	return;
}

void DoRunCommand(Model& model, View& view)
{
	// Announcement
	cout << "Advancing to next event." << endl;
	// Update
	for (int i = 0; i < 5; i++)
		if (model.Update())
			break;
	// Output
	model.ShowStatus();
	return;
}


// PA4 functions
void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id)
{

	//cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to arena " << arena << endl;
	model.GetPokemonPtr(pokemon_id)->StartMovingToArena(model.GetArenaPtr(arena_id));
	return;
}

void DoBattleCommand(Model& model, int pokemon_id, int rival_id)
{
	model.GetPokemonPtr(pokemon_id)->ReadyBattle(model.GetRivalPtr(rival_id));
	return;
}

void DoCreateCommand(Model& model, char type, int in_id, double x, double y)
{
	model.NewCommand(type, in_id, x, y);
	return;
}
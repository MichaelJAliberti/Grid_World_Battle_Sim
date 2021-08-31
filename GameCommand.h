#ifndef GAMECOMMAND
#define GAMECOMMAND

#include "Point2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"

// Function Prototypes
void DoMoveCommand(Model & model, int pokemon_id, Point2D p1);
void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id);
void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id);
void DoStopCommand(Model & model, int pokemon_id);
void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units);
void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points);
void DoGoCommand(Model& model, View& view);
void DoRunCommand(Model& model, View& view);
// Added for PA4
void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id);
void DoBattleCommand(Model& model, int pokemon_id, int rival_id);
void DoCreateCommand(Model& model, char type, int in_id, double x, double y);

#endif
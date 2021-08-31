#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"
using namespace std;

int main()
{
    // Header
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 4" << endl;
    // Seed random number generator (for get random money functions)
	srand(time(NULL));
	// Initialize Model and inputs
	Model master_key = Model();
	View master_graph = View();
	// Start core gameplay loop
	master_key.ShowStatus();
	master_key.Display(master_graph);

	while(true) // Goes on until exit() is called somewhere within program
	{
		// Initialize input receivers
		char commandCode;
		int inputOne; // services ID, ID1
		int inputTwo; // services ID2
		int inputThree; // services stamina_amount and unit_amount
		double x;
		double y;
		char type; // services new object creations
		// Prompt for input
		cout << "Enter command: ";
		cin >> commandCode;
		// Try block start
		try
		{
			// Command Loop
			switch (commandCode)
			{
				case 'm':
					if (!(cin >> inputOne)) // ID - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					if (!(cin >> x))
						throw Invalid_Input("Was expecting a double (Symbol 3)");
					if (!(cin >> y))
						throw Invalid_Input("Was expecting a double (Symbol 4)");
					DoMoveCommand(master_key, inputOne, Point2D(x, y));
					break;
				case 'g':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					if (!(cin >> inputTwo)) // ID2 - PokemonGym
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoMoveToGymCommand(master_key, inputOne, inputTwo);
					break;
				case 'c':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					if (!(cin >> inputTwo)) // ID2 - PokemonCenter
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoMoveToCenterCommand(master_key, inputOne, inputTwo);
					break;
				case 's':
					if (!(cin >> inputOne)) // ID - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					DoStopCommand(master_key, inputOne);
					break;
				case 'r':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					// cin >> inputTwo; // ID2 - PokemonCenter; REDACTED
					if (!(cin >> inputThree)) // stamina_amount
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoRecoverInCenterCommand(master_key, inputOne, inputThree);
					break;
				case 't':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					// cin >> inputTwo; // ID2 - Pokemon Gym; REDACTED
					if (!(cin >> inputThree)) // unit_amount
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoTrainInGymCommand(master_key, inputOne, inputThree);
					break;
				case 'v':
					DoGoCommand(master_key, master_graph);
					break;
				case 'x':
					DoRunCommand(master_key, master_graph);
					break;
				case 'q':
					exit(0);
					break;
				case 'b':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					if (!(cin >> inputTwo)) // ID2 - Rival
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoBattleCommand(master_key, inputOne, inputTwo);
					break;
				case 'a':
					if (!(cin >> inputOne)) // ID1 - Pokemon
						throw Invalid_Input("Was expecting an integer (Symbol 2)");
					if (!(cin >> inputTwo)) // ID2 - BattleArena
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					DoMoveToArenaCommand(master_key, inputOne, inputTwo);
					break;
				case 'n':
					cin >> type;
					if (!(cin >> inputOne))
						throw Invalid_Input("Was expecting an integer (Symbol 3)");
					if (!(cin >> x))
						throw Invalid_Input("Was expecting a double (Symbol 4)");
					if (!(cin >> y))
						throw Invalid_Input("Was expecting a double (Symbol 5)");
					DoCreateCommand(master_key, type, inputOne, x, y);
					break;
				default:
					throw Invalid_Input("Unreckognized command code (Symbol 1)");
					break;
				}
				// Display map
				master_key.Display(master_graph);
		}
		catch(Invalid_Input& except)
		{
			cout << "Invalid_Input - " << except.msg_ptr << endl;
			// Continue with the loop thereafter
		}

		// Flush input between prompts
		cin.clear();
		cin.ignore(100, '\n');
	}

	return 0;
}

#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "Point2D.h"

// Class
class GameObject
{
protected:
	// Protected variables	
	Point2D location;
	int id_num;
	char display_code;
	char state;
public:
	// Public constructors	
	GameObject(char in_code);
	GameObject(Point2D in_loc, int in_id, char in_code);
	// Destructor
	virtual ~GameObject();
	// Public functions
	Point2D GetLocation();
	int GetId();
	bool GetState();
	virtual void ShowStatus();
	virtual bool Update() = 0;
	virtual bool ShouldBeVisible() = 0;
	void DrawSelf(char* ptr);
	// Added member functions
	char GetDisplayCode();
};

#endif

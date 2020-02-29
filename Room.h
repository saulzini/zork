#pragma once
#include "Entity.h"
#include <map> 

using namespace std;

class Exit;
class Item;
class World;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	map<string, Exit*> exits;
	void SetExit(const char* key,Exit* exit);
	Exit *GetExit(string key);
	void DisplayDescription();
	void SolveRoom();

	Room* SolveMovement(string direction);
	Room* SolveOpenDoor(string direction,Item *key);
	World* world = NULL;
	void SetWorld(World* world);
};


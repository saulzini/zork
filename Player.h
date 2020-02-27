#pragma once
#include "Creature.h"
class Item;
class Player :public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	void SolveMovement(string direction);
	void SolveOpenDoor(string direction);
	Item* GetKey();
};


#pragma once
#include "Entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	float life = 100.0f;
	bool IsAlive();
	Room* GetCurrentRoom();
};


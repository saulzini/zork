#pragma once
#include "Creature.h"
class Player :public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
};


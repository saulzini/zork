#pragma once
#include "Creature.h"
class NPC :public Creature
{
public:
	NPC(const char* name, const char* description, Room* room);

};


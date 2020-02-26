#include "Creature.h"
#include <iostream>

Creature::Creature(const char* name, const char* description, Room* room) :Entity(name, description, (Entity*)room)
{
	type = CREATURE;
}

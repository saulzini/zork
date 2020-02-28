#include "NPC.h"
#include <iostream>

NPC::NPC(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = EntityType::CREATURE;
}

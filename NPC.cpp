#include "NPC.h"
#include <iostream>

NPC::NPC(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = CREATURE;
	//cout << "NPC created with name:" << name << "  , description " << description << ", type:" << type << endl;
}

#include "Room.h"
#include <iostream>

Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
	//cout << " created with name:" << name << "  , description " << description << ", type:" << type << endl;
}

#include "Room.h"
#include <iostream>

Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
	//cout << " created with name:" << name << "  , description " << description << ", type:" << type << endl;
}

void Room::SetExit(const char* key, Exit* exit)
{
	exits.insert( pair<string,Exit*>(key,exit) );
}

void Room::DisplayDescription()
{
	cout << description << endl;
}

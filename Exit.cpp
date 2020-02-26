#include "Exit.h"
#include "Room.h"
#include <iostream>
#include <string>

Exit::Exit(const char* name, const char* description, Room* source, Room* destination) :
	Entity(name, description, (Entity*)source),
	closed(false), locked(false), key(NULL), destination(destination)
{
	type = EXIT;

	if (description) {
		destination->contains.push_back(this);
	}

	//cout << "Door created with name:" << name << "  , description " << description << ", type:" << type << endl;
}

string Exit::GetSourceRoomName()
{
	if (parent) {
		return parent->name;
	}
	return "No Source Room Found";
}

string Exit::GetDestinationRoomName()
{
	if (destination) {
		return destination->name;
	}
	return "No Destination Room Found";
}

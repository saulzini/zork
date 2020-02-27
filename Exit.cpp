#include "Exit.h"
#include "Room.h"
#include <iostream>
#include <string>

Exit::Exit(const char* name, const char* destinationName, const char* description, Room* source, Room* destination) :
	Entity(name, description, (Entity*)source),
	closed(false), locked(false), key(NULL), destination(destination)
{
	type = EXIT;

	if (description) {
		destination->contains.push_back(this);
		destination->SetExit(destinationName, this);
	}

	source->SetExit(name, this);
}
/*
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
*/
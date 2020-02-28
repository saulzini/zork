#include "Exit.h"
#include "Room.h"
#include <iostream>
#include <string>

Exit::Exit(const char* name, const char* destinationName, const char* description, Room* source, Room* destination) :
	Entity(name, description, (Entity*)source),
	closed(true), locked(false), key(NULL), destination(destination)
{
	type = EntityType::EXIT;

	if (description) {
		destination->contains.push_back(this);
		destination->SetExit(destinationName, this);
	}

	source->SetExit(name, this);
}

Room* Exit::GetCurrentDestinationRoom(Room* currentRoom)
{
	Room* parentRoom = (Room*)parent;
	//if the room is the same as the parent then is trying to access to the destination
	if (parentRoom == currentRoom) {
		return destination;
	}
	return parentRoom;
}

void Exit::SetLocked(bool locked)
{
	this->locked = locked;
}

void Exit::SetClosed(bool closed)
{
	this->closed = closed;
}

void Exit::OpenExit(Item* key)
{
	//checking if is closed
	if (closed) {
		//if it requires a key
		if (locked) {
			//if you have a key
			if (key) {
				locked = false;
				OpenExitMessage();
			}
			else {
				cout << "The door requires a key" << endl;
			}
		}
		else {
			OpenExitMessage();
		}
	}
	else {
		cout << "The door is already open" << endl;
	}
}

void Exit::OpenExitMessage()
{
	SetClosed(false);
	cout << "The door has been opened" << endl;
}

bool Exit::IsClosed()
{
	return closed;
}

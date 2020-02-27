#include "Room.h"
#include <iostream>
#include "Exit.h"
Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
}

void Room::SetExit(const char* key, Exit* exit)
{
	exits.insert( pair<string,Exit*>(key,exit) );
}

Exit* Room::GetExit(string key)
{
	if (exits[key]) {
		return exits[key];
	}
	return NULL;
}

void Room::DisplayDescription()
{
	cout << description << endl;
}

Room* Room::SolveMovement(string direction)
{
	Exit *exit = GetExit(direction);
	Room* newRoom = NULL;
	//Checking if there is a door on that direction
	if (exit) {
		//checking if the door is closed
		if (exit->IsClosed()) {
			cout << "The door is closed, maybe I should try to openning it first" << endl;
		}
		else {
			newRoom = exit->GetCurrentDestinationRoom(this);

			//Displaying message of the new room
			newRoom->DisplayDescription();
		}
	}
	else {
		cout << "No exit on that direction" << endl;
	}
	return newRoom;
}

Room* Room::SolveOpenDoor(string direction,Item *key)
{
	Exit* exit = GetExit(direction);
	Room* newRoom = NULL;
	if (exit) {
		exit->OpenExit(key);
	}
	else {
		cout << "No exit on that direction" << endl;
	}
	return newRoom;
}

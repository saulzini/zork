#include "Room.h"
#include <iostream>
#include "Exit.h"
#include "World.h"
#include "MonsterRoom.h"
Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = EntityType::ROOM;
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

void Room::SolveRoom()
{
	//Checking if it is the monter room and the npc is alive
	if (type == EntityType::MONSTERROOM && world && world->IsNPCAlive()) {
		DisplayDescription();
		world->setBattleModeOn(true);
	}
	//The enemy is dead
	else if (type == EntityType::MONSTERROOM && world && !world->IsNPCAlive()) {
		MonsterRoom* monsterRoom = (MonsterRoom*)this;
		monsterRoom->DisplaySuccessRoom();
	}
	//Mission complete
	else if (type == EntityType::VICTORIOUSROOM) {
		DisplayDescription();
		world->setMissionComplete(true);
	}
	else {
		//Displaying message of the new room
		DisplayDescription();
	}

}


Room* Room::SolveMovement(string direction)
{
	Exit *exit = GetExit(direction);
	Room* newRoom = NULL;
	//Checking if there is a door on that direction
	if (exit) {
		//checking if the door is closed
		if (exit->IsClosed()) {
			cout << "The door is closed, maybe I should try to open it first" << endl;
		}
		else {

			newRoom = exit->GetCurrentDestinationRoom(this);
			newRoom->SolveRoom();
		}
	}
	else {
		cout << "No door on that direction" << endl;
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
		cout << "No door on that direction" << endl;
	}
	return newRoom;
}

void Room::SetWorld(World* world)
{
	this->world = world;
}

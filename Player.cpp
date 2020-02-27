#include "Player.h"
#include <iostream>
#include "Room.h"
#include "Item.h"
Player::Player(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = PLAYER;
}

void Player::SolveMovement(string direction)
{
	Room* currentRoom = (Room*)parent;

	//Checking if the movement is allowed
	Room* newRoom = currentRoom->SolveMovement(direction);
	if ( newRoom ) {
		ChangeParent(newRoom);
	}
}


void Player::SolveOpenDoor(string direction)
{
	Room* currentRoom = (Room*)parent;

	//Checking if you can open the door
	currentRoom->SolveOpenDoor(direction,GetKey());
}

Item* Player::GetKey()
{
	return nullptr;
}


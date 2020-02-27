#include "Player.h"
#include <iostream>

Player::Player(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = PLAYER;
	//cout << "Player created with name:"<< name << "  , description " << description << ", type:" << type <<endl;
}
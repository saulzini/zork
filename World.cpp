#include "World.h"
#include <iostream>
#include "Entity.h"
#include "Room.h"
using namespace std;

World::World()
{
	cout << "Creating world" << endl;

	//Creating the rooms
	Room* room1 = new Room("Room 1", "You are in the Room 1, in the room there is a desk and on it there is a letter, in addition to a door.");
	Room* room2 = new Room("Room 2", "You are in the Room 2, in the room there is a desk and on it there is a letter, in addition there are two doors.");
	Room* room3 = new Room("Room 3", "You are in the Room 3, in the room there is a bag to carry more items, in addition to a door.");
	Room* room4 = new Room("Room 4", "You are in the Room 4, in the room there is a key and a sword, in addition to a door.");
	Room* room5 = new Room("Room 5", "You are in the Room 5, You have found the monster that guards the exit, Prepare to fight with your sword.");
	Room *room6 = new Room("Forest", "You are in the Forest, Your journey has finish, Thanks for playing :)");


}


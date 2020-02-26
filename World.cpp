#include "World.h"
#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "NPC.h"
#include "Item.h"
#include "Exit.h"
using namespace std;

World::World()
{
	cout << "Creating world" << endl;

	//Creating the rooms
	Room *room1 = new Room("Room 1", "You are in the Room 1, in the room there is a desk and on it there is a letter, in addition to a door.");
	Room *room2 = new Room("Room 2", "You are in the Room 2, in the room there is a desk and on it there is a letter, in addition there are two doors.");
	Room *room3 = new Room("Room 3", "You are in the Room 3, in the room there is a bag to carry more items, in addition to a door.");
	Room *room4 = new Room("Room 4", "You are in the Room 4, in the room there is a key and a sword, in addition to a door.");
	Room *room5 = new Room("Room 5", "You are in the Room 5, You have found the monster that guards the exit, Prepare to fight with your sword.");
	Room *room6 = new Room("Forest", "You are in the Forest, Your journey has finish, Thanks for playing :)");
	
	//Creating player in the room 1
	Player *player = new Player("Player", "Character moved by user", room1);
	//Creating NPC in the room 5
	NPC *enemy = new NPC("Monster", "Npc character", room5);

	//Creating the doors 
	Exit* exitOneToTwo    = new Exit("Door 1-2", "Door between Room 1 and 2", room1, room2);
	Exit* exitTwoToThree  = new Exit("Door 2-3", "Door between Room 2 and 3", room2, room3);
	Exit* exitTwoToFive   = new Exit("Door 2-5", "Door between Room 2 and 5", room2, room5);
	Exit* exitThreeToFour = new Exit("Door 3-4", "Door between Room 3 and 4", room3, room4);
	Exit* exitFiveToSix   = new Exit("Door 5-6", "Door between Room 5 and 6", room5, room6);

	//Creating items 
	Item *letterRoom1 = new Item("Letter Room 1", "In your path you will find two doors, one will lead you to an endless path and the other is protected by a monster",room1,LETTER);
	Item *letterRoom2 = new Item("Letter Room 2", "Joseph: I could not carry a weapon because I am missing a bag, I will try my luck, I hope to not die in here",room2,LETTER);
	Item *bag = new Item("Bag", "Bag for collecting the items", room3, BAG);
	Item* key = new Item("Key", "Key for openning a door", room4, KEY);
	Item *sword = new Item("Sword", "A sharp sword made of silver", room4, WEAPON);
	cout << "End creating world" << endl;
}


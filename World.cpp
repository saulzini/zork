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
	//Creating the rooms
	Room *room1 = new Room("Room 1", "You are in the Room 1, in the room there is a desk and on it there is a letter, in addition to a door in the east side.");
	Room *room2 = new Room("Room 2", "You are in the Room 2, in the room there is a desk and on it there is a note, in addition there is one door to the east and one to the south.");
	Room *room3 = new Room("Room 3", "You are in the Room 3, in the room there is a bag to carry more items, in addition to a door in the south.");
	Room *room4 = new Room("Room 4", "You are in the Room 4, in the room there is a key and a sword.");
	Room *room5 = new Room("Room 5", "You are in the Room 5, You have found the monster that guards the exit, Prepare to fight with your sword.");
	Room *room6 = new Room("Forest", "You are in the Forest, Your journey has finish, Thanks for playing :)");
	
	//Creating player in the room 1
	//TODO::CHange room to room 1
	player = new Player("Player", "Character moved by user", room2);
	//Creating NPC in the room 5
	enemy = new NPC("Monster", "Npc character", room5);

	//Creating the doors 
	Exit* exitOneToTwo    = new Exit("east","west", "Door between Room 1 and 2", room1, room2);
	Exit* exitTwoToThree  = new Exit("south","north", "Door between Room 2 and 3", room2, room3);
	Exit* exitTwoToFive   = new Exit("east","west", "Door between Room 2 and 5", room2, room5);
	Exit* exitThreeToFour = new Exit("south","north", "Door between Room 3 and 4", room3, room4);
	Exit* exitFiveToSix   = new Exit("north","south", "Door between Room 5 and 6", room5, room6);

	//Locking door
	exitTwoToFive->SetLocked(true);

	//Creating items 
	Item *letterRoom1 = new Item("letter", "In your path you will find two doors, one will lead you to an endless path and the other is protected by a monster",room1,LETTER);
	Item *letterRoom2 = new Item("note", "Joseph: I could not carry a weapon because I am missing a bag, I will try my luck, I hope to not die in here",room2,LETTER);
	Item *bag = new Item("bag", "Bag for collecting the items", room3, BAG);
	Item* key = new Item("key", "Key for openning a door", room4, KEY);
	Item *sword = new Item("sword", "A sharp sword made of silver", room4, WEAPON);

}

bool World::IsPlayerAlive()
{
	return player->IsAlive();
}

bool World::IsNPCAlive()
{
	return enemy->IsAlive();
}

bool World::IsMissionComplete()
{
	return missionComplete;
}

Room* World::GetPlayerCurrentRoom()
{
	return player->GetCurrentRoom();
}


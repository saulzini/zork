#include "World.h"
#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Player.h"
#include "NPC.h"
#include "Item.h"
#include "Exit.h"
#include "MonsterRoom.h"
#include "VictoriousRoom.h"
using namespace std;

World::World()
{
	//Creating the rooms
	Room *room1 = new Room("Room 1", "You are in the Room 1, in the room there is a letter, in addition to a door in the east side.");
	Room *room2 = new Room("Room 2", "You are in the Room 2, in the room there is a note, in addition there is one door to the east and one to the south.");
	Room *room3 = new Room("Room 3", "You are in the Room 3, in the room there is a bag to carry more items, in addition to a door in the south.");
	Room *room4 = new Room("Room 4", "You are in the Room 4, in the room there is a key and a sword.");
	MonsterRoom *room5 = new MonsterRoom("Room 5", "You are in the Room 5, You have found the monster that guards the exit, Prepare to fight with your sword.","It looks there is a door to the north");
	room5->SetWorld(this);
	VictoriousRoom *room6 = new VictoriousRoom("Forest", "You are in the Forest, Your journey has finish, Thanks for playing :)");
	room6->SetWorld(this);

	entities.push_back(room1);
	entities.push_back(room2);
	entities.push_back(room3);
	entities.push_back(room4);
	entities.push_back(room5);
	entities.push_back(room6);

	//Creating player in the room 1
	player = new Player("player", "Character moved by user", room1);
	entities.push_back(player);

	//Creating NPC in the room 5
	enemy = new NPC("monster", "Npc character", room5);
	entities.push_back(enemy);

	//Creating the doors 
	Exit* exitOneToTwo    = new Exit("east","west", "Door between Room 1 and 2", room1, room2);
	Exit* exitTwoToThree  = new Exit("south","north", "Door between Room 2 and 3", room2, room3);
	Exit* exitTwoToFive   = new Exit("east","west", "Door between Room 2 and 5", room2, room5);
	Exit* exitThreeToFour = new Exit("south","north", "Door between Room 3 and 4", room3, room4);
	Exit* exitFiveToSix   = new Exit("north","south", "Door between Room 5 and 6", room5, room6);
	entities.push_back(exitOneToTwo);
	entities.push_back(exitTwoToThree);
	entities.push_back(exitTwoToFive);
	entities.push_back(exitThreeToFour);
	entities.push_back(exitFiveToSix);

	//Locking door
	exitTwoToFive->SetLocked(true);

	//Creating items 
	Item *letterRoom1 = new Item("letter", "In your path you will find two doors, one will lead you to a path where there is not a way out and the other is protected by a monster",room1, ItemType::LETTER);
	Item *letterRoom2 = new Item("note", "Joseph: I could not carry a weapon because I am missing a bag, I will try my luck, I hope to not die in here",room2, ItemType::NOTE);
	Item *bag = new Item("bag", "Bag for collecting the items", room3, ItemType::BAG);
	Item* key = new Item("key", "Key for openning a door", room4, ItemType::KEY);
	Item* sword = new Item("sword", "A sharp sword made of silver", room4, ItemType::WEAPON);
	Item* axe = new Item("axe", "Axe made of steel", room5, ItemType::WEAPON);

	entities.push_back(letterRoom1);
	entities.push_back(letterRoom2);
	entities.push_back(bag);
	entities.push_back(key);
	entities.push_back(sword);
	entities.push_back(axe);


	//Setting sword parameters
	sword->SetAttackSuccessRate(35);
	sword->SetDamage(50);
	//Setting axe parameters
	axe->SetAttackSuccessRate(60);
	axe->SetDamage(15);
	//Monster picking the item
	enemy->PickItem(axe, enemy);

	//Initializing in the room
	player->GetCurrentRoom()->SolveRoom();
}

World::~World()
{
	//Clearing entities
	for (list<Entity*>::iterator entity = entities.begin(); entity != entities.end(); ++entity) {
		delete* entity;
	}
	entities.clear();
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

bool World::IsBattleModeOn()
{
	return battle;
}

void World::setBattleModeOn(bool battle)
{
	this->battle = battle;
}

void World::setMissionComplete(bool missionComplete)
{
	this->missionComplete = missionComplete;
}


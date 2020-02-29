#include "Player.h"
#include <iostream>
#include "Room.h"
#include "Item.h"
Player::Player(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = EntityType::PLAYER;
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

float Player::CalculateAttack(string itemName)
{
	Item* item = GetItemByName(itemName);
	float damage = 0;
	if ( item ) {
		if (item->itemType == ItemType::WEAPON) {
			damage = item->CalculateInflictedDamage();
		}
		else {
			cout << "I can't attack with this, maybe I should try with a weapon." << endl;
		}
	}
	else {
		cout << "I don't have this item" << endl;
	}

	if (damage == 0) {
		cout << "I have missed an oportunity" << endl;
	}
	return damage;
}

void Player::SolveRead(string itemName)
{
	Item* item = GetItemByName(itemName);
	if (item->itemType == ItemType::LETTER || item->itemType == ItemType::NOTE) {
		cout << item->description << endl;
	}
	else {
		cout << "I can't read this item" << endl;
	}
}

void Player::SolveToss(string itemName)
{
	//Map string name to item
	//Find in player
	Item* item = GetItemByName(itemName);
	//If the item is found
	if (item) {
		Room* room = GetCurrentRoom();
		if (item->itemType == ItemType::WEAPON || item->itemType == ItemType::KEY) {
			TossItem(item, room);
			cout << "I have take out the " << item->name << " of the bag and toss the item into the room" << endl;
		}
		else {
			TossItem(item, room);
			cout << "I have toss the "<<item->name<<" into the room" << endl;
		}

	}
	else {
		cout << "I don't have that item" << endl;
	}
}

void Player::SolvePickup(string itemName)
{
	//Find in room
	Room* room = GetCurrentRoom();
	Item* item = (Item*)room->GetEntityByString(itemName);
	//If the item was found
	if (item) {
		
		//Check if it is the key or sword
		//Key and weapon only store if the player has a bag
		if (item->itemType == ItemType::WEAPON || item->itemType == ItemType::KEY) {
			//Check if it has a bag
			Item* bag = GetBag();
			if (bag) {
				PickItem(item, bag);
				cout << "The " << item->name << " has been picked and saved in the bag." << endl;
			}
			else {
				//if not display it needs it
				cout << "I need a bag, to carry this item" << endl;
			}
		}
		else {
			//Add to the player the items
			PickItem(item,this);
			cout << "The " << item->name << " has been picked." << endl;
		}
	}
	else {
		cout << "Item not found in the room" << endl;
	}
}


Item* Player::GetKey()
{	
	return GetItemByItemType(ItemType::KEY);
}

Item* Player::GetBag()
{
	return GetItemByItemType(ItemType::BAG);
}

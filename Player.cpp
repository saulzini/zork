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

void Player::SolveAttack(string itemName)
{
	//TODO:: USE HASH
}

void Player::SolveToss(string itemName)
{
	//Map string name to item
	//Find in player
	Item* item = GetItemByName(itemName);
	//If the item is found
	if (item) {
		Room* room = GetCurrentRoom();
		TossItem(item, room);
		cout << "I have toss the item" << endl;
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



void Player::PickItem( Item* item, Entity *parent)
{
	SolveItem(item, parent, true);
	//Checking if it is a bag to update hash insert of the contains
	if (item->itemType == ItemType::BAG) {
		for (auto child : item->contains) {
			SetItem((Item*)child);
		}
	}
}

void Player::TossItem(Item* item, Entity* parent)
{
	SolveItem(item, parent, false);
	//Checking if it is a bag to update hash delete of the contains
	if (item->itemType == ItemType::BAG) {
		for (auto child : item->contains) {
			UnsetItem((Item *)child);
		}
	}

}

void Player::SolveItem(Item* item, Entity* parent, bool pick)
{
	//Assign new parent
	item->ChangeParent(parent);
	if (pick) {
		//Assign it to hashes
		SetItem(item);
	}
	else {
		//Deleting from hashes
		UnsetItem(item);
	}
}

Item* Player::GetKey()
{	
	return GetItemByItemType(ItemType::KEY);
}

Item* Player::GetWeapon()
{
	return GetItemByItemType(ItemType::WEAPON);
}

Item* Player::GetBag()
{
	return GetItemByItemType(ItemType::BAG);
}

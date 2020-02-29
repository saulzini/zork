#include "Creature.h"
#include <iostream>
#include "Item.h"
using namespace std;
Creature::Creature(const char* name, const char* description, Room* room) :Entity(name, description, (Entity*)room)
{
	type = EntityType::CREATURE;
}

bool Creature::IsAlive()
{
	return life > 0;
}

Room* Creature::GetCurrentRoom()
{
	return (Room*)parent;
}

void Creature::SetItem(Item* item)
{
	itemsByItemType.insert(pair<ItemType, Item*>(item->itemType, item));
	itemsByName.insert(pair<string, Item*>(item->name, item));
}

void Creature::UnsetItem(Item *item)
{	
	if (itemsByName[item->name]) {
		itemsByName.erase(item->name);
		itemsByItemType.erase(item->itemType);
	}
}

Item* Creature::GetItemByItemType(ItemType key)
{
	map<ItemType, Item*>::iterator it;
	it = itemsByItemType.find(key);
	if (it != itemsByItemType.end()) {
		return it->second;
	}
	return NULL;
}

Item* Creature::GetItemByName(string itemName)
{
	map<string, Item*>::iterator it;
	it = itemsByName.find(itemName);
	if (it != itemsByName.end()) {
		return it->second;
	}
	return NULL;
}

void Creature::PickItem(Item* item, Entity* parent)
{
	SolveItem(item, parent, true);
	//Checking if it is a bag to update hash insert of the contains
	if (item->itemType == ItemType::BAG) {
		for (auto child : item->contains) {
			SetItem((Item*)child);
		}
	}
}

void Creature::TossItem(Item* item, Entity* parent)
{
	SolveItem(item, parent, false);
	//Checking if it is a bag to update hash delete of the contains
	if (item->itemType == ItemType::BAG) {
		for (auto child : item->contains) {
			UnsetItem((Item*)child);
		}
	}

}

void Creature::SolveItem(Item* item, Entity* parent, bool pick)
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

void Creature::ReceivedDamage(float damageTaken, Creature* instigator)
{
	cout << name << " has take damage of " << damageTaken << " by " << instigator->name << " Life left:"<<life-damageTaken<< endl;
	
	life -= damageTaken;
	if (life <= 0) {
		life = 0;
	}
}


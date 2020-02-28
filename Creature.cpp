#include "Creature.h"
#include <iostream>
#include "Item.h"
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

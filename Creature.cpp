#include "Creature.h"
#include <iostream>
#include "Item.h"
Creature::Creature(const char* name, const char* description, Room* room) :Entity(name, description, (Entity*)room)
{
	type = CREATURE;
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
	Item* item = itemsByItemType[key];
	if (item) {
		return item;
	}
	return NULL;
}

Item* Creature::GetItemByName(string itemName)
{
	Item* item = itemsByName[itemName];
	if (item) {
		return item;
	}
	return NULL;
}

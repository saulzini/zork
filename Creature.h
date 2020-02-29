#pragma once
#include "Entity.h"
#include <map> 
#include "ItemType.h"
class Room;
class Item;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	float life = 100.0f;
	bool IsAlive();
	Room* GetCurrentRoom();
	map<ItemType, Item*> itemsByItemType;
	map<string, Item*> itemsByName;
	void SetItem(Item* item);
	void UnsetItem(Item* item);
	Item* GetItemByItemType(ItemType key);
	Item* GetItemByName(string itemName);
	void PickItem(Item* item, Entity* parent);
	void TossItem(Item* item, Entity* parent);
	void SolveItem(Item* item, Entity* parent, bool pick);
	void ReceivedDamage(float damageTaken,Creature *instigator);
};


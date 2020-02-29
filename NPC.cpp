#include "NPC.h"
#include <iostream>
#include "Item.h"
NPC::NPC(const char* name, const char* description, Room* room) :Creature(name, description, room)
{
	type = EntityType::CREATURE;

}

float NPC::CalculateAttack()
{
	Item* item = GetItemByItemType(ItemType::WEAPON);
	float damage = 0;
	if (item) {
		if (item->itemType == ItemType::WEAPON) {
			damage = item->CalculateInflictedDamage();
		}
	}
	return damage;
}

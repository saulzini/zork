#include "Item.h"
#include <iostream>

Item::Item(const char* name, const char* description, Entity* parent, ItemType itemType):Entity(name, description, parent),itemType(itemType)
{
	type = EntityType::ITEM;

	if (itemType == ItemType::WEAPON) {
		damage = defaultDamage;
		attackSuccessRate = defaultAttackSuccessRate;
	}
}

void Item::SetDamage(float damage)
{
	this->damage = damage;
}

void Item::SetAttackSuccessRate(float attackSuccessRate)
{
	this->attackSuccessRate = attackSuccessRate;
}

float Item::CalculateInflictedDamage()
{
	int random = rand() % 100 + 1;
	return random >= (100-attackSuccessRate) ? damage : 0;
}


Item* Item::GetItem(ItemType entityType)
{
	for (auto entity : contains) {
		Item* item = (Item*)entity;
		if (item->itemType == entityType) {
			return item;
		}
	}
	return NULL;
}

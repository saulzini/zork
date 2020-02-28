#pragma once
#include "Entity.h"
#include "ItemType.h"

class Item :public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, ItemType itemType = ItemType::COMMON);
	ItemType itemType;
	float defaultDamage = 30;
	float defaultAttackSuccessRate = 80;
	float damage = 0;
	float attackSuccessRate = 0;

	void SetDamage(float damage);
	void SetAttackSuccessRate(float attackSuccessRate);
	float CalculateInflictedDamage();

	Item* GetItem(ItemType entityType);
};


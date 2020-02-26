#pragma once
#include "Entity.h"

enum ItemType
{
	COMMON,
	LETTER,
	KEY,
	WEAPON,
	BAG,
};
class Item :public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, ItemType item_type = COMMON);
	ItemType item_type;
};


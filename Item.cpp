#include "Item.h"
#include <iostream>

Item::Item(const char* name, const char* description, Entity* parent, ItemType item_type):Entity(name, description, parent),item_type(item_type)
{
	type = ITEM;
	//cout << "Item created with name:"<< name << "  , description " << description << ", type:" << type << " item type " << item_type <<endl;
}

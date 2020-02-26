#include "Entity.h"
#include <iostream>

Entity::Entity(const char* name, const char* description, Entity* parent)
{
	type = ENTITY;
	if (parent != NULL)
		parent->contains.push_back(this);

	cout << "Entity created with name:"<< name << "  , description " << description << ", type:" << type <<endl;
}

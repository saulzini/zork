#include "Entity.h"
#include <iostream>

Entity::Entity(const char* name, const char* description, Entity* parentEntity)
{
	type = ENTITY;
	parent = NULL;
	if (parentEntity != NULL) {
		parent = parentEntity;
		parent->contains.push_back(this);
	}

	//cout << "Entity created with name:"<< name << "  , description " << description << ", type:" << type <<endl;
}

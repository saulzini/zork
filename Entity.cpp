#include "Entity.h"
#include <iostream>

Entity::Entity(const char* name, const char* description, Entity* parentEntity = NULL):name(name), description(description), parent(parentEntity)
{
	type = ENTITY;
	
	if (parentEntity != NULL) {
		parent->contains.push_back(this);
	}
	//cout << "Entity created with name:"<< name << "  , description " << description << ", type:" << type <<endl;
}

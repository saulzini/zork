#include "Entity.h"
#include <iostream>
#include "Item.h"
Entity::Entity(const char* name, const char* description, Entity* parentEntity = NULL):name(name), description(description), parent(parentEntity)
{
	type = EntityType::ENTITY;
	
	if (parentEntity != NULL) {
		parent->contains.push_back(this);
	}
}


void Entity::ChangeParent(Entity* newParent)
{
	//Delete from parent contains
	parent->contains.remove(this);
	//Add into new parent contains
	newParent->contains.push_back(this);
	// Assign new parent
	parent = newParent;
}

int Entity::FindEntityIndex(EntityType entityType)
{
	int index = -1;
	int i = 0;
	for (auto item : contains) {
		i++;
		Entity* entity = (Entity*)item;
		if (entity->type == entityType) {
			index = i;
		}
	}
	return index;
}

Entity* Entity::GetEntity(EntityType entityType)
{

	for (auto entity : contains) {
		Entity* item = (Entity*)entity;
		if (item->type == entityType) {
			return item;
		}
	}
	return NULL;
}


Entity* Entity::GetEntityByString(string name)
{

	for (auto entity : contains) {
		Entity* item = (Entity*)entity;
		if (item->name == name) {
			return item;
		}
	}
	return NULL;
}



#pragma once
#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{

public:
	Entity(const char* name, const char* description, Entity* parentEntity);
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
	Entity* parent;

};


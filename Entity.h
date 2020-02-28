#pragma once
#include <string>
#include <list>

class Item;
using namespace std;
enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER,
	MONSTERROOM,
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
	void ChangeParent(Entity* newParent);
	int FindEntityIndex(EntityType entityType);
	Entity* GetEntity(EntityType entityType);
	Entity* GetEntityByString(string name);
};


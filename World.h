#pragma once

#include <list>

using namespace std;

class Entity;

class World
{	
public:
	World();
	list<Entity*> entities;
};


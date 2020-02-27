#pragma once
#include "Entity.h"
#include <map> 

using namespace std;

class Exit;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	map<string, Exit*> exits;
	void SetExit(const char* key,Exit* exit);
	void DisplayDescription();
};


#pragma once
#include "Entity.h"
class Room;
class Item;
class Exit :public Entity
{
public:
	Exit(const char* name, const char* destinationName,  const char* description, Room* source, Room* destination);

	bool closed;
	bool locked;
	Room* destination;
	Item* key;
	
	Room* GetCurrentDestinationRoom(Room *currentRoom);
	void SetLocked(bool locked);
	void SetClosed(bool closed);
	void OpenExit(Item* key);
	void OpenExitMessage();
	bool IsClosed();
};


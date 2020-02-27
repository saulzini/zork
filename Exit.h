#pragma once
#include "Entity.h"
class Room;

class Exit :public Entity
{
public:
	Exit(const char* name, const char* destinationName,  const char* description, Room* source, Room* destination);

	bool closed;
	bool locked;
	Room* destination;
	Entity* key;
	
	//string GetSourceRoomName();
	//string GetDestinationRoomName();

};


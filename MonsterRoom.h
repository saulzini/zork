#pragma once
#include "Room.h"
class MonsterRoom :public Room
{
public:
	MonsterRoom(const char* name, const char* description,string successRoom);
	string successRoom;
	void DisplaySuccessRoom();
};


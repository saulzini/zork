#include "MonsterRoom.h"
#include <iostream>

MonsterRoom::MonsterRoom(const char* name, const char* description,string successRoom) : Room(name, description),successRoom(successRoom)
{
	type = EntityType::MONSTERROOM;
}

void MonsterRoom::DisplaySuccessRoom()
{
	cout << successRoom << endl;
}

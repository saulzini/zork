#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(const char* name, const char* description) : Room(name, description)
{
	type = MONSTERROOM;
}

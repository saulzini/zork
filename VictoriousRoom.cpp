#include "VictoriousRoom.h"

VictoriousRoom::VictoriousRoom(const char* name, const char* description):Room(name, description)
{
	type = EntityType::VICTORIOUSROOM;
}

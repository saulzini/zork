#pragma once

#include <list>

using namespace std;

class Entity;
class Player;
class NPC;
class Room;

class World
{	
public:
	World();
	list<Entity*> entities;
	Player* player;
	NPC* enemy;

	bool missionComplete = false;
	bool isPlayerAlive();
	bool isNPCAlive();
	bool isMissionComplete();

	//bool playerHasWeapon();
	Room* getPlayerCurrentRoom();
};


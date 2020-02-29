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
	~World();

	list<Entity*> entities;
	Player* player;
	NPC* enemy;

	bool missionComplete = false;
	bool battle = false;
	bool IsPlayerAlive();
	bool IsNPCAlive();
	bool IsMissionComplete();
	bool IsBattleModeOn();

	void setBattleModeOn(bool battle);
	void setMissionComplete(bool missionComplete);
};


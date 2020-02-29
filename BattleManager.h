#pragma once
#include <string>
using namespace std;
class World;
class Player;
class NPC;
class BattleManager
{
public:
	BattleManager(World *world);
	World *world;
	float handleEnemyAttack(NPC *npc);
	float handlePlayerAttack(Player *player,string item);
	void handleBattle(string enemyName,string item);
};


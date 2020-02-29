#include "BattleManager.h"
#include "World.h"
#include "Player.h"
#include "NPC.h"
#include "MonsterRoom.h"
#include <iostream>
BattleManager::BattleManager(World *world)
{
	this->world = world;
}

float BattleManager::handleEnemyAttack(NPC *npc)
{
	return npc->CalculateAttack();
}

float BattleManager::handlePlayerAttack(Player *player,string item)
{
	return player->CalculateAttack(item);
}

void BattleManager::handleBattle(string enemyName, string item)
{
	Player *player = world->player;
	NPC* enemy = world->enemy;
	//Players turn
	float playerDamageToEnemy= handlePlayerAttack(player, item);
	enemy->ReceivedDamage(playerDamageToEnemy, player);
	//Enemy turn
	float enemyDamageToPlayer = handleEnemyAttack(enemy);
	player->ReceivedDamage(enemyDamageToPlayer, enemy);

	//The battle has finish
	if (!enemy->IsAlive()) {
		cout << "----The battle has end, fortunately I am alive----" << endl;
		world->setBattleModeOn(false);
		MonsterRoom *room = (MonsterRoom *) player->GetCurrentRoom();
		room->DisplaySuccessRoom();
	}
	if (!player->IsAlive()) {
		cout << "I have lost, my soul is trapped" << endl;
	}
}

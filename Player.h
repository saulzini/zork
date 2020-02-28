#pragma once
#include "Creature.h"
class Item;
class Player :public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	void SolveMovement(string direction);
	void SolveOpenDoor(string direction);
	void SolveAttack(string itemName);
	void SolvePickup(string itemName);
	void SolveToss(string itemName);
	void PickItem(Item* item, Entity* parent);
	void TossItem(Item *item,Entity *parent);
	void SolveItem(Item* item, Entity* parent, bool pick);
	Item* GetKey();
	Item* GetWeapon();
	Item* GetBag();
};


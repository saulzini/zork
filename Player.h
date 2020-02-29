#pragma once
#include "Creature.h"
class Item;
class Player :public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	void SolveMovement(string direction);
	void SolveOpenDoor(string direction);
	float CalculateAttack(string itemName);
	void SolveRead(string itemName);
	void SolvePickup(string itemName);
	void SolveToss(string itemName);
	
	Item* GetKey();
	Item* GetBag();
};


#include "DecisionManager.h"
#include "World.h"
#include "Room.h"
#include <iostream>
#include <sstream>
#include "Player.h"
#include "BattleManager.h"
DecisionManager::DecisionManager(World *world)
{
	this->world = world;
	battleManager = new BattleManager(world);
}

void DecisionManager::ParseDecision()
{
	//Converting sentence into array of words
	istringstream iss(decision);
	string word;
	while (iss >> word) {
		words.push_back(word);
	}
}

void DecisionManager::ManageDecision()
{
	if (decision == "") {
		Unsolved();
		ClearInput();
		return;
	}
	//Parsing input
	ParseDecision();
	//Commands availables
	string command = words[0];

	//Checking if is battle mode
	if (IsBattleModeOn()) {
		if (command == "attack") {
			SolveAttack();
		}
		else {
			cout << "I cant escape, I can only attack" << endl;
		}
	}
	else {
		if (command == "move") {
			SolveMove();
		}
		else if (command == "open") {
			SolveOpenDoor();
		}
		else if (command == "pick") {
			SolvePick();
		}
		else if (command == "toss") {
			SolveToss();
		}
		else if (command == "read") {
			SolveRead();
		}
		else {
			Unsolved();
		}
	}
	
	ClearInput();
}


void DecisionManager::SolveMove()
{
	if (words.size() == 2) {
		world->player->SolveMovement(words[1]);
	}
	else {
		cout << "Command not found movement i.e. move east" << endl;
	}

}

void DecisionManager::SolveOpenDoor()
{
	//I.E. open east door
	if (words.size() == 3 && words[2] == "door") {
		world->player->SolveOpenDoor(words[1]);
	}
	else {
		cout << "Command not found open door i.e. open east door" << endl;
	}
}

void DecisionManager::SolvePick()
{
	if (words.size() == 2) {
		world->player->SolvePickup(words[1]);
	}
	else {
		cout << "Command not found movement i.e. pick letter" << endl;
	}
}

void DecisionManager::SolveToss()
{
	if (words.size() == 2) {
		world->player->SolveToss(words[1]);
	}
	else {
		cout << "Command not found toss i.e. toss letter" << endl;
	}
}

void DecisionManager::SolveRead()
{
	if (words.size() == 2) {
		world->player->SolveRead(words[1]);
	}
	else {
		cout << "Command not found read i.e. read letter" << endl;
	}
}

void DecisionManager::SolveAttack()
{
	if (words.size() == 4) {
		battleManager->handleBattle(words[1], words[3]);
	}
	else {
		cout << "Command not found attack i.e. attack monster using sword" << endl;
	}
}

void DecisionManager::Unsolved()
{
	cout << "Command not found, please try again: move,open,pick,toss" << endl;
}

void DecisionManager::ClearInput()
{
	decision = "";
	words.clear();
}

bool DecisionManager::IsBattleModeOn()
{
	return world->battle;
}

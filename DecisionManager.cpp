#include "DecisionManager.h"
#include "World.h"
#include "Room.h"
#include <iostream>
#include <sstream>
#include "Player.h"
DecisionManager::DecisionManager(World* world)
{
	this->world = world;
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
		cout << "Command not found movement i.e. pick letter" << endl;
	}
}

void DecisionManager::SolveAttack()
{
	cout << "attack is selected" << endl;
	if (words.size() == 2) {
		world->player->SolveMovement(words[1]);
	}
	else {
		cout << "Command not found movement i.e. attack using sword" << endl;
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

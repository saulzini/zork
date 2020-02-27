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

	if ( command == "move" ) {
		SolveMove();
	}
	else if (command == "open") {
		SolveOpenDoor();
	}
	else if ( command == "pick" ) {
		SolvePick();
	}
	else if ( command == "toss") {
		SolveToss();
	}
	else if (command == "attack") {
		SolveAttack();
	}
	else {
		Unsolved();
	}
	ClearInput();
}

void DecisionManager::Initialize()
{
	Room *room = world->GetPlayerCurrentRoom();
	room->DisplayDescription();
}

void DecisionManager::SolveMove()
{
	if (words.size() > 1) {
		world->player->SolveMovement(words[1]);
	}
	else {
		cout << "Command move incomplete: missing direction word" << endl;
	}

}

void DecisionManager::SolveOpenDoor()
{
	if (words.size() > 1) {
		world->player->SolveOpenDoor(words[1]);
	}
	else {
		cout << "Command open door incomplete: missing direction word" << endl;
	}
}

void DecisionManager::SolvePick()
{
	cout << "pick is selected" << endl;
}

void DecisionManager::SolveToss()
{
	cout << "toss is selected" << endl;
}

void DecisionManager::SolveAttack()
{
	cout << "attack is selected" << endl;
}

void DecisionManager::Unsolved()
{
	cout << "Command not found, please try again: move,pick,toss,attack" << endl;
}

void DecisionManager::ClearInput()
{
	decision = "";
	words.clear();
}

#include "DecisionManager.h"
#include "World.h"
#include "Room.h"
#include <iostream>
#include <sstream>
DecisionManager::DecisionManager(World* world)
{
	this->world = world;
}

void DecisionManager::parseDecision()
{
	//Converting sentence into array of words
	istringstream iss(decision);
	string word;
	while (iss >> word) {
		words.push_back(word);
	}
}

void DecisionManager::manageDecision()
{
	if (decision == "") {
		unsolved();
		clearInput();
		return;
	}
	//Parsing input
	parseDecision();
	//Commands availables
	string command = words[0];

	if ( command == "move" ) {
		solveMove();
	}
	else if ( command == "pick" ) {
		solvePick();
	}
	else if ( command == "toss") {
		solveToss();
	}
	else if (command == "attack") {
		solveAttack();
	}
	else {
		unsolved();
	}
	clearInput();
}

void DecisionManager::initialize()
{
	Room *room = world->getPlayerCurrentRoom();
	room->DisplayDescription();
}

void DecisionManager::solveMove()
{
	cout << "move is selected" << endl;
}

void DecisionManager::solvePick()
{
	cout << "pick is selected" << endl;
}

void DecisionManager::solveToss()
{
	cout << "toss is selected" << endl;
}

void DecisionManager::solveAttack()
{
	cout << "attack is selected" << endl;
}

void DecisionManager::unsolved()
{
	cout << "Command not found, please try again: move,pick,toss,attack" << endl;
}

void DecisionManager::clearInput()
{
	decision = "";
	words.clear();
}

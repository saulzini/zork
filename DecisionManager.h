#pragma once
#include <string>
#include <vector>
using namespace std;

class World;

class DecisionManager
{
public:
	DecisionManager(World* world);
	World *world;
	string decision;
	vector<string> words;

	void parseDecision();
	void manageDecision();

	void initialize();
	void solveMove();
	void solvePick();
	void solveToss();
	void solveAttack();
	void unsolved();
	void clearInput();

};


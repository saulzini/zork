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

	void ParseDecision();
	void ManageDecision();

	void Initialize();
	void SolveMove();
	void SolveOpenDoor();
	void SolvePick();
	void SolveToss();
	void SolveAttack();
	void Unsolved();
	void ClearInput();

};


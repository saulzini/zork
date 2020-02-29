#pragma once
#include <string>
#include <vector>
using namespace std;

class World;
class BattleManager;

class DecisionManager
{
public:
	DecisionManager(World* world);
	World *world;
	BattleManager *battleManager;
	string decision;
	vector<string> words;

	void ParseDecision();
	void ManageDecision();

	void SolveMove();
	void SolveOpenDoor();
	void SolvePick();
	void SolveToss();
	void SolveRead();
	void SolveAttack();
	void Unsolved();
	void ClearInput();

	bool IsBattleModeOn();

};


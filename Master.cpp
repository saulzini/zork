// Master.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "World.h"
#include "DecisionManager.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Welcome to your new conquest \nThe mission in this game is to get free from the dungeon.\nLet's Begin\n" << endl;
	World *world = new World();
	DecisionManager* decisionManager = new DecisionManager(world);

	while (world->IsPlayerAlive() && !world->IsMissionComplete() )
	{
		getline(cin,decisionManager->decision);
		decisionManager->ManageDecision();
	}
	cout << "--------------Thanks for playing-------------" << endl;
	cout << "---------------------BYE---------------------" << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

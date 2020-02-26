#include "World.h"
#include <iostream>
#include "Entity.h"

using namespace std;

World::World()
{
	cout << "Creating world" << endl;
	Entity* entity = new Entity("jojo", "des",NULL);
}

#include "stdafx.h"
#include "World.h"

World::World(std::string wfilename, std::vector<RoomFactory*> rmFactories, std::vector<EntityFactory*> enFactories, std::vector<ItemFactory*> itFactories) :
	entityFactories(enFactories), roomFactories(rmFactories), itemFactories(itFactories),worldFileName(wfilename)
{
	std::ifstream in;
	in.open(worldFileName);
	std::cout << "Loading world, please wait . . .\n";
	while (true)
	{
		unsigned int x, y;
		std::string roomType;
		RoomFactory* factory = nullptr;
		for (auto& i : roomFactories) {
			if (i->getTypeString() == roomType) {
				factory = i;
			}
		}
		in >> x >> y;
		if (factory != nullptr) {
			map[x][y] = factory->createRoomFromFile(in);
		}
		else {
			map[x][y] = nullptr;
		}
	}
	

}

void World::save()
{
}

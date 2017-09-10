#pragma once
#include <array>
#include "WorldInterface.h"
#include "EntityFactory.h"
#include "ItemFactory.h"
#include "RoomFactory.h"



class World :
	public WorldInterface
{
public:

	World(std::string wfilename, std::vector<RoomFactory*> rmFactories, std::vector<EntityFactory*> enFactories, std::vector<ItemFactory*> itFactories);

	void save();

	const static unsigned int mapSize = 50;

private:

	std::vector<ItemFactory*> itemFactories;
	std::vector<EntityFactory*> entityFactories;
	std::vector<RoomFactory*> roomFactories;
	std::array<std::array<Room*, mapSize>, mapSize> map;
	std::vector<Entity*> wEntities;
	std::string worldFileName;
};

const unsigned int World::mapSize;


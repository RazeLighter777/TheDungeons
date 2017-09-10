#pragma once
#include <vector>
#include <string>
#include <ostream>

struct Entity;
struct Item;
struct Room;

struct WorldInterface {

	virtual Room* getRoomAt(std::pair<int, int> pos) = 0;

	virtual std::vector<Entity*> getEntitiesAt(std::pair<unsigned int, unsigned int> pos) = 0;

	virtual Entity* spawnNew(std::pair<unsigned int, unsigned int> pos, std::string factoryname) = 0;

	virtual bool isTileValid(std::pair<unsigned int, unsigned int> pos) = 0;

};
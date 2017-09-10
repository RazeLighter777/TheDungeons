#pragma once
#include "Entity.h"



struct EntityFactory {
	
	virtual std::string getTypeString() = 0;

	virtual Entity* createNewEntity(WorldInterface* winterface, std::pair<coord, coord> pos) = 0;

	virtual Entity* createEntityFromFile(WorldInterface* winterface, std::istream& in) = 0;

};
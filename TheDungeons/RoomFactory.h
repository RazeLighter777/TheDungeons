#pragma once
#include "Room.h"


struct RoomFactory
{

	virtual std::string getTypeString() = 0;

	virtual Room* createNewRoom(std::pair<int, int> pos) = 0;

	virtual Room* createRoomFromFile(std::istream& in) = 0;

};
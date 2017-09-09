#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
struct WorldInterface;
struct Entity;

struct Room : public sf::Drawable {
	/*
	Fetches a string containing the type of room.
	*/
	virtual std::string getTypeString() = 0;
	/*
	Returns 1 if the room is solid.
	*/
	virtual bool isSolid() = 0;
	/*
	Saves the room to a file.
	*/
	virtual void save(std::ostream& out) = 0;
	/*
	Returns a reference to the world the room is in.
	*/
	virtual WorldInterface* getWorldInterface() = 0;
	/*
	updates the room.
	*/
	virtual void update() = 0;
};
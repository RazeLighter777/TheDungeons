#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>

/*
The entity interface is an interface for an obect that exists in the world. 
*/

typedef int coord;

struct WorldInterface;
struct Item;

struct Entity : public sf::Drawable {
	/*
	Returns a pair of coordinates coresponding to the entities position.
	*/
	virtual std::pair<coord, coord> getPosition() = 0;
	/*
	Returns a string containing the type of entity.
	This string should match the one of the factory used to create it,
	so that the entity can be saved and loaded.
	*/
	virtual std::string getTypeString() = 0;
	/*
	Fetches the name of the entity
	*/
	virtual std::string getName() = 0;
	/*
	Update function passes one update tick for the entity. Returns 0 if the entity is dead and needs to be removed.
	*/
	virtual bool update() = 0;
	/*
	Serializes the entity to a file
	*/
	virtual void save(std::ostream& out) = 0;
	/*
	Should return a reference to the world the entity was created in.
	*/
	virtual WorldInterface& getWorldInterface() = 0;
	/*
	Event handler for when the entity takes damage.
	*/
	virtual void takeDamage(double amount, Entity* sender) = 0;
	/*
	Event handler for when the entity recieves an item. Note that this transfers ownership of the said item.
	*/
	virtual void getItem(Item* item, Entity* sender) = 0;
	/*
	Event handler for sending a message.
	*/
	virtual void getMessage(std::string msg, Entity* sender) = 0;
	/*
	Draws the entity on the map on some tile. The draw position will be multiplied by 16, each tile is 16x16 when rendered on the map.
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
	/*
	*/
};
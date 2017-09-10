#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
struct Entity;

struct Item {
	virtual std::string getName() = 0;

	virtual std::string getTypeString() = 0;

	virtual void save(std::ostream& out) = 0;

	virtual void use(Entity* sender, Entity* target) = 0;

	virtual sf::Sprite getSprite() = 0;

	virtual std::string getDesc() = 0;

	virtual double getWieght() = 0;

	virtual long int getValue() = 0;
};
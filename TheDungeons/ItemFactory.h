#pragma once
#include <string>
#include <vector>
#include <iostream>


struct Item;


struct ItemFactory {

	virtual std::string getTypeString() = 0;

	virtual Item* createNewItem() = 0;

	virtual Item* createItemFromFile(std::istream& in) = 0;
};
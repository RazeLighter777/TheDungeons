// TheDungeons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameServices.h"

int main()
{
	GameServices::loadTextures("C:\\Users\\GENESIS-FRC-02\\Documents\\Visual Studio 2015\\Projects\\TheDungeons\\TheDungeons\\Assets",
		std::vector<std::string>({ "azure_jelly.png", "goblin.png" }));
    return 0;
}


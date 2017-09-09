#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




class GameServices
{
public:
	static sf::Texture * GameServices::getTexture(std::string textureName)
	{
		if (textureMap.find(textureName) == textureMap.end()) {
			return nullptr;
		}
		else {
			textureMap[textureName];
		}
	}
	static sf::Music * GameServices::getMusic(std::string musicName)
	{
		if (musicMap.find(musicName) == musicMap.end()) {
			return nullptr;
		}
		else {
			textureMap[musicName];
		}
	}
	static sf::Sound GameServices::getSound(std::string soundName)
	{
		if (soundMap.find(soundName) == soundMap.end()) {
			return sf::Sound();
		}
		else {
			sf::Sound sound;
			sound.setBuffer(*soundMap[soundName]);
			return sound;
		}
	}
	static int GameServices::moon_phase(int y, int m, int d)
	{


		int c, e;
		double jd;
		int b;

		if (m < 3) {
			y--;
			m += 12;
		}
		++m;
		c = 365.25*y;
		e = 30.6*m;
		jd = c + e + d - 694039.09;  /* jd is total days elapsed */
		jd /= 29.53;           /* divide by the moon cycle (29.53 days) */
		b = jd;		   /* int(jd) -> b, take integer part of jd */
		jd -= b;		   /* subtract integer part to leave fractional part of original jd */
		b = jd * 8 + 0.5;	   /* scale fraction from 0-8 and round by adding 0.5 */
		b = b & 7;		   /* 0 and 8 are the same so turn 8 into 0 */
		return b;

	}
	static void GameServices::loadTextures(std::string path, std::vector<std::string> textureList)
	{
		for (const auto& i : textureList) {
			sf::Texture* newTexture = new sf::Texture;
			newTexture->loadFromFile(path + "\\" + i);
			GameServices::textureMap[i] = newTexture;
		}
	}
	static void GameServices::loadMusic(std::string path, std::vector<std::string> musicList) {
		for (const auto& i : musicList) {
			sf::Music* newSound = new sf::Music;
			newSound->openFromFile(path + "\\" + i);
			GameServices::musicMap[i] = newSound;
		}
	}
	static void GameServices::loadSounds(std::string path, std::vector<std::string> soundList) {
		for (const auto& i : soundList) {
			sf::SoundBuffer* newSound = new sf::SoundBuffer;
			newSound->loadFromFile(path + "\\" + i);
			GameServices::soundMap[i] = newSound;
		}
	}
private:
	static std::map<std::string, sf::Texture*> textureMap;
	static std::map<std::string, sf::SoundBuffer*> soundMap;
	static std::map<std::string, sf::Music*> musicMap;
};


std::map<std::string, sf::Texture*> GameServices::textureMap;
std::map<std::string, sf::SoundBuffer*> GameServices::soundMap;
std::map<std::string, sf::Music*> GameServices::musicMap;
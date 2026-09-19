#pragma once
#include <vector>
#include <string>
#include <SFML/System/Time.hpp>

struct AnimDataStruct {

	std::vector<std::string> TextureNames;
	int TileSizeX;
	int TileSizeY;
	int TileLeft;
	int TileTop;
	int NumFrames{ 0 };
	bool Orentation = false; //False = Horizontal, true = vertical.
	bool Looped = false;
	int CurrentFrame = 0;
	sf::Time FrameTime{ sf::seconds(1.0f / 2.0f) };
	sf::Time FrameStartTime{ sf::Time::Zero };
};
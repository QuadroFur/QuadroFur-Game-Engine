#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_map>
#include "AnimDataStruct.h"

class Actor
{

public:
	sf::Sprite* Sprite = nullptr;
	AnimDataStruct LoadedAnimSet;
	std::unordered_map<std::string, AnimDataStruct> AnimSets;

};
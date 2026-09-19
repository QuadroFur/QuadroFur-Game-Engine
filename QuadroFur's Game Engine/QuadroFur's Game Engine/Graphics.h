#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Actor.h"

class Graphics
{

private:
	std::unordered_map<std::string, sf::Texture*>TextureMap;
	std::unordered_map<std::string, Actor*>RenderMap;

public:

	bool LoadTexture(std::string Path, std::string TextureName);
	bool LoadAnimation(std::string AnimationName, Actor* Actor, std::vector<std::string>Textures, int TileLeft, int TileTop, int NumOfFrames = 0, int TileSizeX = 32, int TileSizeY = 32, bool Orentation = false);
	bool LoadAnimation(std::string AnimationName, Actor* Actor, AnimDataStruct AnimData);
	bool SetLoadedAnimation(std::string AnimationName, Actor* Actor);
	void SetVisible(std::string ActorName, Actor* Actor);
	void SetNotVisible(std::string ActorName, Actor* Actor);
	void Render(sf::RenderWindow& Window, sf::Clock& Clock);

	~Graphics();

};
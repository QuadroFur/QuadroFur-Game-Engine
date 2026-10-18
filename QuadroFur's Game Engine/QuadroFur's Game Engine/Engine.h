#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Engine
{

public:
	Engine();
	
	sf::RenderWindow& CreateWindow(sf::Vector2i WindowSize, std::string Title);
	sf::RenderWindow& CreareWindiw(int SizeX, int SizeY, std::string Title);

};
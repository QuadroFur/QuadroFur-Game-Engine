#include "Graphics.h"
#include "Actor.h"
#include <vector>
int main() {

	//TEST CODE:
	Graphics NewGraphics;
	NewGraphics.LoadTexture("C:/Users/Username/Downloads/Grass_Block_112.png", "TestSheet");
	Actor NewActor;
	NewGraphics.LoadAnimation("TestAnim", &NewActor, std::vector<std::string>{"TestSheet"}, 0, 0, 4, 67, 106, false);
	NewGraphics.SetLoadedAnimation("TestAnim", &NewActor);
	NewGraphics.SetVisible("NewActor", &NewActor);

	sf::RenderWindow Window{ sf::VideoMode({800, 800}), "Cool Window bro" };
	sf::Clock Clock;

	while (true) {
		NewGraphics.Render(Window, Clock);
	}

	return 1;
}
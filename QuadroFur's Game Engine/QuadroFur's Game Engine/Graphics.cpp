#include <iostream>
#include "Graphics.h"

bool Graphics::LoadTexture(std::string Path, std::string TextureName) {
	if (TextureMap.find(TextureName) != TextureMap.end()) {
		std::cerr << "Texture with provided name already exists in map! Skipping..." << std::endl;
		return false;
	}
	sf::Texture* Texture = new sf::Texture;
	if (Texture->loadFromFile(Path)) {
		TextureMap[TextureName] = Texture;
		return true;
	}
	std::cerr << "Texture did not load! Incorrect path provided, or an error occured!" << std::endl;
	return false;
}
bool Graphics::LoadAnimation(std::string AnimationName, Actor* Actor, std::vector<std::string>Textures, int TileSizeX, int TileSizeY, int TileLeft, int TileTop, int NumOfFrames, bool Orentation) {
	if (Actor->AnimSets.find(AnimationName) != Actor->AnimSets.end()) {
		std::cerr << "Animation with provided name already exists in map! Skipping..." << std::endl;
		return false;
	}
	AnimDataStruct AnimData = { Textures, TileSizeX, TileSizeY, TileLeft, TileTop, NumOfFrames };
	Actor->AnimSets[AnimationName] = AnimData;
	return true;
}
bool Graphics::LoadAnimation(std::string AnimationName, Actor* Actor, AnimDataStruct AnimData) {
	if (Actor->AnimSets.find(AnimationName) != Actor->AnimSets.end()) {
		std::cerr << "Animation with provided name already exists in map! Skipping..." << std::endl;
		return false;
	}
	Actor->AnimSets[AnimationName] = AnimData;
	return true;
}
bool Graphics::SetLoadedAnimation(std::string AnimationName, Actor* Actor) {
	if (Actor->AnimSets.find(AnimationName) == Actor->AnimSets.end()) {
		std::cerr << "Animation with provided name not found in map! Unable to load!" << std::endl;
		return false;
	}
	Actor->LoadedAnimSet = Actor->AnimSets[AnimationName];
	if (Actor->Sprite == nullptr) Actor->Sprite = new sf::Sprite(*TextureMap[Actor->LoadedAnimSet.TextureNames[1]]);
	else Actor->Sprite->setTexture(*TextureMap[Actor->LoadedAnimSet.TextureNames[1]]);
	return true;
}
void Graphics::SetVisible(std::string ActorName, Actor* Actor) {
	if (RenderMap.find(ActorName) != RenderMap.end()) {
		std::cerr << "Actor with matching name already exists in map. Mistaken for SetNotVisible? Skipped..." << std::endl;
		return;
	}
	RenderMap[ActorName] = Actor;
	return;
}
void Graphics::SetNotVisible(std::string ActorName, Actor* Actor) {
	if (RenderMap.find(ActorName) == RenderMap.end()) {
		std::cerr << "No actor with name exists in render map. Mistaken for SetVisible? Skipped..." << std::endl;
		return;
	}
	RenderMap.erase(ActorName);
	return;
}
void Graphics::Render(sf::RenderWindow& Window, sf::Clock& Clock) {
	for (auto& i : RenderMap) {
		sf::Time CurrentTime = Clock.getElapsedTime();
		if (i.second->LoadedAnimSet.NumFrames > 1 && CurrentTime - i.second->LoadedAnimSet.FrameStartTime >= i.second->LoadedAnimSet.FrameTime) {
			if (i.second->LoadedAnimSet.TextureNames.size() > 1) {
				i.second->Sprite->setTexture(*TextureMap[i.second->LoadedAnimSet.TextureNames[i.second->LoadedAnimSet.CurrentFrame]]);
				i.second->LoadedAnimSet.CurrentFrame++;
			}
			else {
				//Surprisingly, easier than the old way - See Scrap Colony engine (Sept. 2026).
				if (i.second->LoadedAnimSet.Orentation == false) //Horizontal
				{
					int LeftSide = i.second->LoadedAnimSet.TileLeft + (i.second->LoadedAnimSet.TileSizeX * i.second->LoadedAnimSet.NumFrames);
					i.second->Sprite->setTextureRect(sf::IntRect({ LeftSide, i.second->LoadedAnimSet.TileTop }, { i.second->LoadedAnimSet.TileSizeX, i.second->LoadedAnimSet.TileSizeY }));
				}
				else { //Vertical
					int TopSide = i.second->LoadedAnimSet.TileTop + (i.second->LoadedAnimSet.TileSizeY * i.second->LoadedAnimSet.NumFrames);
					i.second->Sprite->setTextureRect(sf::IntRect({ i.second->LoadedAnimSet.TileLeft, TopSide }, { i.second->LoadedAnimSet.TileSizeX, i.second->LoadedAnimSet.TileSizeY }));
				}
			}
		}
	}
}
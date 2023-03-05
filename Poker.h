#pragma once

#include "Phase.h"

class Poker : public Phase
{
private:
	// Background
	sf::Sprite background;

	// Textures
	std::vector<sf::Texture*> textures;
	sf::Texture backgroundTex;

	// Initializer functions
	void initTextures();


public:
	Poker(sf::RenderWindow*, std::stack<Phase*>*);
	virtual ~Poker();

	void update();
	void render(sf::RenderTarget*);
};
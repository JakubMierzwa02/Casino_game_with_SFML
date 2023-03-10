#pragma once

#include "Phase.h"
#include "Deal.h"
#include "Card.h"

class Poker : public Phase
{
private:
	// Background
	sf::Sprite background;

	// Textures
	std::vector<sf::Texture*> textures;
	sf::Texture backgroundTex;

	// Cards
	std::vector<Card*> cards;
	std::vector<sf::Sprite> cardBacks;

	// Deal
	Deal* deal;

	// Initializer functions
	void initTextures();
	void initCards();
	void initCardBacks();
	void initDeal();

public:
	Poker(sf::RenderWindow*, std::stack<Phase*>*);
	virtual ~Poker();

	void update();
	void render(sf::RenderTarget*);
};
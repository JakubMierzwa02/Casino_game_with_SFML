#pragma once

#include "Card.h"

class Hand
{
private:
	std::vector<Card*> cards;
	std::vector<Card> copyCards;
	float pos_x;
	float pos_y;
	float gap;

	// Initializer functions
	void initCopyCards();

public:
	// Constructors / Destructors
	Hand(std::vector<Card*>, float, float, float);
	virtual ~Hand();

	// Functions
	void update();
	void render(sf::RenderTarget*);
};
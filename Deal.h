#pragma once

#include "Hand.h"

class Deal
{
private:
	// Resources
	sf::RenderWindow* window;

	// Hand
	Hand* hand;

	// Cards
	std::vector<Card*> cards;

	// Initializer functions
	void initHand();

public:
	Deal(sf::RenderWindow*, std::vector<Card*>);
	virtual ~Deal();

	// Functions
	void updateHand();
	void update();
	void render(sf::RenderTarget*);
};
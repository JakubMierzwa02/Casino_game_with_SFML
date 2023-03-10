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
	std::vector<Card*> handCards;
	std::vector<Card> usedCards;

	// Logic
	int counter;

	// Initializer functions
	void initVariables();
	void initHandCards();
	void initHand();

public:
	Deal(sf::RenderWindow*, std::vector<Card*>);
	virtual ~Deal();

	const int checkHand();

	// Functions
	void updateButtons();
	void updateHand();
	void update();
	void render(sf::RenderTarget*);
};
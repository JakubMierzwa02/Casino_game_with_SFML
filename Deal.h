#pragma once

#include "Hand.h"
#include "Button.h"

class Deal
{
private:
	// Resources
	sf::RenderWindow* window;

	// Mouse positions
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Hand
	Hand* hand;

	// Cards
	std::vector<Card*> cards;
	std::vector<Card*> handCards;
	std::vector<Card> usedCards;

	// Buttons
	std::vector<bool> isChecked;

	// Logic
	int counter;

	// Initializer functions
	void initVariables();
	void initHandCards();
	void initHand();

public:
	Deal(sf::RenderWindow*, std::vector<Card*>);
	virtual ~Deal();

	void checkHand();

	bool canPress();

	// Functions
	void updateMousePos();
	void updateButtons();
	void updateHand();
	void update();
	void render(sf::RenderTarget*);
};
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

	void sortHand();

	// Check poker hands
	bool jacks_or_better();
	bool two_pairs();
	bool three_of_a_kind();
	bool straight();
	bool flush();
	bool full_house();
	bool four_of_a_kind();
	bool straight_flush();

	// Functions
	void update(const float&);
	void render(sf::RenderTarget*);
};
#pragma once

#include "Phase.h"

class Poker : public Phase
{
private:


public:
	Poker(sf::RenderWindow*, std::stack<Phase*>*);
	virtual ~Poker();

	void update();
	void render(sf::RenderTarget*);
};
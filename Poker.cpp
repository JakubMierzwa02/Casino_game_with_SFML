#include "Poker.h"

Poker::Poker(sf::RenderWindow* window, std::stack<Phase*>* phases)
	: Phase(window, phases)
{
	
}

Poker::~Poker()
{
	
}

void Poker::update()
{
	// Quit phase
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		this->endPhase();
}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
}

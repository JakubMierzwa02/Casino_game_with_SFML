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

}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
}

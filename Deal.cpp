#include "Deal.h"

void Deal::initHand()
{
	// Init hand
	//this->hand = new Hand();
}

Deal::Deal(sf::RenderWindow* window, std::vector<Card*> cards)
{
	this->window = window;
	this->initHand();
}

Deal::~Deal()
{
	//delete this->hand;
}

void Deal::updateHand()
{

}

void Deal::update()
{
	this->updateHand();
}

void Deal::render(sf::RenderTarget*)
{

}

#include "Hand.h"

void Hand::initCopyCards()
{
	for (size_t i = 0; i < 5; i++)
	{
		this->copyCards.push_back(*this->cards[i]);
	}
}


Hand::Hand(std::vector<Card*> cards, float pos_x, float pos_y, float gap)
	: cards(cards), pos_x(pos_x), pos_y(pos_y), gap(gap)
{
	this->initCopyCards();
}

Hand::~Hand()
{

}


void Hand::update()
{

}

void Hand::render(sf::RenderTarget* target)
{
	float pos = 0;
	float width = this->cards[0]->getBounds().width + this->gap;
	for (size_t i = 0; i < this->cards.size(); i++)
	{
		this->cards[i]->setPosition(this->pos_x + pos, this->pos_y);
		this->cards[i]->render(target);
		pos += width;
	}
}

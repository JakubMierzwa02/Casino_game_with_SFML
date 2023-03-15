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


void Hand::sortHand()
{
	for (size_t i = 0; i < this->copyCards.size() - 1; i++)
		for (size_t j = 0; j < this->copyCards.size() - i - 1; j++)
			if (this->copyCards[j].getValue() > this->copyCards[j + 1].getValue())
				std::swap(this->copyCards[j], this->copyCards[j + 1]);
}

bool Hand::jacks_or_better()
{
	for (size_t i = 0; i < this->cards.size(); i++)
		for (size_t j = i + 1; j < this->cards.size(); j++)
			if (this->cards[i]->getValue() >= 11 && (this->cards[i]->getValue() == this->cards[j]->getValue()))
				return true;
	return false;
}

bool Hand::two_pairs()
{
	int pairs = 0;
	for (size_t i = 0; i < this->cards.size(); i++)
	{
		for (size_t j = i + 1; j < this->cards.size(); j++)
		{
			if (this->cards[i]->getValue() == this->cards[j]->getValue())
			{
				pairs++;
			}
		}
	}
	if (pairs == 2)
		return true;
	return false;
}

bool Hand::three_of_a_kind()
{
	for (size_t i = 0; i < this->cards.size(); i++)
		for (size_t j = i + 1; j < this->cards.size(); j++)
			for (size_t k = j + 1; k < this->cards.size(); k++)
				if (this->cards[i]->getValue() == this->cards[j]->getValue() && this->cards[i]->getValue() == this->cards[k]->getValue())
					return true;
	return false;
}

bool Hand::straight()
{
	this->sortHand();
	for (size_t i = 1; i < this->copyCards.size(); i++)
		if (this->copyCards[i].getValue() - 1 != this->copyCards[i - 1].getValue())
			return false;
	return true;
}

bool Hand::flush()
{
	for (size_t i = 1; i < this->cards.size(); i++)
		if (this->cards[i]->getColor() != this->cards[i - 1]->getColor())
			return false;
	return true;
}

bool Hand::full_house()
{
	this->sortHand();
	if (this->copyCards[0].getValue() == this->copyCards[1].getValue() && this->copyCards[0].getValue() == this->copyCards[2].getValue())
		return (this->copyCards[3].getValue() == this->copyCards[4].getValue());
	else if (this->copyCards[0].getValue() == this->copyCards[1].getValue())
		return ((this->copyCards[2].getValue() == this->copyCards[3].getValue()) && (this->copyCards[2].getValue() == this->copyCards[4].getValue()));
	else
		return false;
}

bool Hand::four_of_a_kind()
{
	for (size_t i = 0; i < this->cards.size(); i++)
		for (size_t j = i + 1; j < this->cards.size(); j++)
			for (size_t k = j + 1; k < this->cards.size(); k++)
				for (size_t l = k + 1; l < this->cards.size(); l++)
					if (this->cards[i]->getValue() == this->cards[j]->getValue() && this->cards[i]->getValue() == this->cards[k]->getValue() && this->cards[i]->getValue() == this->cards[l]->getValue())
						return true;
	return false;
}

bool Hand::straight_flush()
{
	return (this->flush() && this->straight());
}

void Hand::update(const float& dt)
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

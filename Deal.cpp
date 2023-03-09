#include "Deal.h"

void Deal::initVariables()
{
	this->counter = 10;
}

void Deal::initHandCards()
{
	// Check if the card is duplicated
	for (int i = 0; i < 5; i++)
	{
		this->handCards.push_back(this->cards[std::rand() % 51 + 1]);
		for (int j = i - 1; j >= 0 && i > 0; j--)
		{
			if ((this->handCards[j]->getValue() == this->handCards[i]->getValue())
				&& (this->handCards[j]->getColor() == this->handCards[i]->getColor()))
			{
				this->handCards.erase(this->handCards.begin() + i);
				i--;
				break;
			}
		}
	}

	// Init used cards
	for (size_t i = 0; i < 5; i++)
	{
		this->usedCards.push_back(*this->handCards[i]);
	}
}

void Deal::initHand()
{
	// Init hand
	this->hand = new Hand(this->handCards, 210.f, 530.f, 100.f);
}


Deal::Deal(sf::RenderWindow* window, std::vector<Card*> cards)
{
	this->window = window;
	this->initVariables();
	this->initHandCards();
	this->initHand();
}

Deal::~Deal()
{
	//delete this->hand;
}


void Deal::updateButtons()
{

}

void Deal::updateHand()
{

}

void Deal::update()
{
	this->updateButtons();
	this->updateHand();
}

void Deal::render(sf::RenderTarget* target)
{
	for (size_t i = 0; i < this->handCards.size(); i++)
	{
		this->hand->render(target);
	}
}

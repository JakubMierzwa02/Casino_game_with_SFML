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


const int Deal::checkHand()
{
	if (this->hand->straight_flush())
	{
		std::cout << "Straight flush!" << '\n';
	}
	else if (this->hand->four_of_a_kind())
	{
		std::cout << "Four of a kind!" << '\n';
	}
	else if (this->hand->full_house())
	{
		std::cout << "Full house" << '\n';
	}
	else if (this->hand->flush())
	{
		std::cout << "Flush" << '\n';
	}
	else if (this->hand->straight())
	{
		std::cout << "Straight" << '\n';
	}
	else if (this->hand->three_of_a_kind())
	{
		std::cout << "Three of a kind" << '\n';
	}
	else if (this->hand->two_pairs())
	{
		std::cout << "Two pairs" << '\n';
	}
	else if (this->hand->jacks_or_better())
	{
		std::cout << "Jacks or better" << '\n';
	}
	else
	{
		std::cout << "High card" << '\n';
	}

	return;
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

#include "Poker.h"

void Poker::initVariables()
{
	this->counter = 30;
	this->change = false;
	this->check = false;
}

void Poker::initTextures()
{
	for (int i = 0; i < 53; i++)
		this->textures.push_back(new sf::Texture());

	// Load textures
	this->textures[0]->loadFromFile("Resources/Cards/2_of_clubs.png");
	this->textures[1]->loadFromFile("Resources/Cards/3_of_clubs.png");
	this->textures[2]->loadFromFile("Resources/Cards/4_of_clubs.png");
	this->textures[3]->loadFromFile("Resources/Cards/5_of_clubs.png");
	this->textures[4]->loadFromFile("Resources/Cards/6_of_clubs.png");
	this->textures[5]->loadFromFile("Resources/Cards/7_of_clubs.png");
	this->textures[6]->loadFromFile("Resources/Cards/8_of_clubs.png");
	this->textures[7]->loadFromFile("Resources/Cards/9_of_clubs.png");
	this->textures[8]->loadFromFile("Resources/Cards/10_of_clubs.png");
	this->textures[9]->loadFromFile("Resources/Cards/jack_of_clubs.png");
	this->textures[10]->loadFromFile("Resources/Cards/queen_of_clubs.png");
	this->textures[11]->loadFromFile("Resources/Cards/king_of_clubs.png");
	this->textures[12]->loadFromFile("Resources/Cards/ace_of_clubs.png");

	this->textures[13]->loadFromFile("Resources/Cards/2_of_spades.png");
	this->textures[14]->loadFromFile("Resources/Cards/3_of_spades.png");
	this->textures[15]->loadFromFile("Resources/Cards/4_of_spades.png");
	this->textures[16]->loadFromFile("Resources/Cards/5_of_spades.png");
	this->textures[17]->loadFromFile("Resources/Cards/6_of_spades.png");
	this->textures[18]->loadFromFile("Resources/Cards/7_of_spades.png");
	this->textures[19]->loadFromFile("Resources/Cards/8_of_spades.png");
	this->textures[20]->loadFromFile("Resources/Cards/9_of_spades.png");
	this->textures[21]->loadFromFile("Resources/Cards/10_of_spades.png");
	this->textures[22]->loadFromFile("Resources/Cards/jack_of_spades.png");
	this->textures[23]->loadFromFile("Resources/Cards/queen_of_spades.png");
	this->textures[24]->loadFromFile("Resources/Cards/king_of_spades.png");
	this->textures[25]->loadFromFile("Resources/Cards/ace_of_spades.png");

	this->textures[26]->loadFromFile("Resources/Cards/2_of_diamonds.png");
	this->textures[27]->loadFromFile("Resources/Cards/3_of_diamonds.png");
	this->textures[28]->loadFromFile("Resources/Cards/4_of_diamonds.png");
	this->textures[29]->loadFromFile("Resources/Cards/5_of_diamonds.png");
	this->textures[30]->loadFromFile("Resources/Cards/6_of_diamonds.png");
	this->textures[31]->loadFromFile("Resources/Cards/7_of_diamonds.png");
	this->textures[32]->loadFromFile("Resources/Cards/8_of_diamonds.png");
	this->textures[33]->loadFromFile("Resources/Cards/9_of_diamonds.png");
	this->textures[34]->loadFromFile("Resources/Cards/10_of_diamonds.png");
	this->textures[35]->loadFromFile("Resources/Cards/jack_of_diamonds.png");
	this->textures[36]->loadFromFile("Resources/Cards/queen_of_diamonds.png");
	this->textures[37]->loadFromFile("Resources/Cards/king_of_diamonds.png");
	this->textures[38]->loadFromFile("Resources/Cards/ace_of_diamonds.png");

	this->textures[39]->loadFromFile("Resources/Cards/2_of_hearts.png");
	this->textures[40]->loadFromFile("Resources/Cards/3_of_hearts.png");
	this->textures[41]->loadFromFile("Resources/Cards/4_of_hearts.png");
	this->textures[42]->loadFromFile("Resources/Cards/5_of_hearts.png");
	this->textures[43]->loadFromFile("Resources/Cards/6_of_hearts.png");
	this->textures[44]->loadFromFile("Resources/Cards/7_of_hearts.png");
	this->textures[45]->loadFromFile("Resources/Cards/8_of_hearts.png");
	this->textures[46]->loadFromFile("Resources/Cards/9_of_hearts.png");
	this->textures[47]->loadFromFile("Resources/Cards/10_of_hearts.png");
	this->textures[48]->loadFromFile("Resources/Cards/jack_of_hearts.png");
	this->textures[49]->loadFromFile("Resources/Cards/queen_of_hearts.png");
	this->textures[50]->loadFromFile("Resources/Cards/king_of_hearts.png");
	this->textures[51]->loadFromFile("Resources/Cards/ace_of_hearts.png");

	this->textures[52]->loadFromFile("Resources/Cards/cardBack.png");

	// Init background
	if (!this->backgroundTex.loadFromFile("Resources/background.jpg"))
		throw "Could not load background.jpg file";
	this->background.setTexture(this->backgroundTex);
	this->background.setScale(3.6f, 3.6f);
}

void Poker::initCards()
{
	int i = 0;
	
	// Create cards
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, CLUBS));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, SPADES));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, DIAMONDS));
		i++;
	}
	for (int j = 2; j <= 14; j++)
	{
		this->cards.push_back(new Card(*this->textures[i], j, HEARTS));
		i++;
	}
}

void Poker::initCardBacks()
{
	for (size_t i = 0; i < 5; i++)
	{
		this->cardBacks.push_back(sf::Sprite(*this->textures[52]));
	}
	this->cardBacks[0].setScale(1.4f, 1.4f);
	this->cardBacks[0].setPosition(210.f, 530.f);

	float pos = 210.f + this->cardBacks[0].getGlobalBounds().width + 100.f;
	for (size_t i = 1; i < 5; i++)
	{
		this->cardBacks[i].setScale(1.4f, 1.4f);
		this->cardBacks[i].setPosition(pos, 530.f);
		pos += this->cardBacks[0].getGlobalBounds().width + 100.f;
	}
}

void Poker::initDeal()
{
	this->deal = new Deal(this->window, this->cards);
}


Poker::Poker(sf::RenderWindow* window, std::stack<Phase*>* phases)
	: Phase(window, phases)
{
	this->initVariables();
	this->initTextures();
	this->initCards();
	this->initCardBacks();
}

Poker::~Poker()
{
	for (size_t i = 0; i < this->textures.size(); i++)
	{
		delete this->textures[i];
	}

	for (size_t i = 0; i < this->cards.size(); i++)
	{
		delete this->cards[i];
	}
}


bool Poker::canPlay()
{
	if (this->counter < 30)
	{
		this->counter++;
		return false;
	}
	return true;
}

void Poker::updateButtons()
{
	// Deal
	if (this->canPlay() && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!this->change && !this->check)
		{

			this->initDeal();
			this->counter = 0;
			this->change = true;
		}
		else if (this->change && !this->check)
		{
			// Change hand
			this->deal->updateHand();

			this->deal->checkHand();
			this->counter = 0;
			this->check = true;
			this->change = false;
		}

		// Deal ends
		else if (this->check)
		{
			delete this->deal;
			this->counter = 0;
			this->check = false;
		}
	}

	// Quit phase
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		this->endPhase();
}

void Poker::update()
{
	this->updateButtons();

	if (this->change)
		this->deal->update();
}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	// Render cardbacks
	if (!this->change && !this->check)
	{
		for (size_t i = 0; i < this->cardBacks.size(); i++)
		{
			target->draw(this->cardBacks[i]);
		}
	}

	else if (this->deal && (this->change || this->check))
	{
		this->deal->render(target);
	}
}

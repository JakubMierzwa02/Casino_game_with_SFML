#include "Poker.h"

void Poker::initVariables()
{
	this->counter = 30;
	this->money = 100000;
	this->change = false;
	this->check = false;
}

void Poker::initTextures()
{
	const std::vector<std::string> paths{
		"2_of_clubs.png",
		"3_of_clubs.png",
		"4_of_clubs.png",
		"5_of_clubs.png",
		"6_of_clubs.png",
		"7_of_clubs.png",
		"8_of_clubs.png",
		"9_of_clubs.png",
		"10_of_clubs.png",
		"jack_of_clubs.png",
		"queen_of_clubs.png",
		"king_of_clubs.png",
		"ace_of_clubs.png",
		"2_of_spades.png",
		"3_of_spades.png",
		"4_of_spades.png",
		"5_of_spades.png",
		"6_of_spades.png",
		"7_of_spades.png",
		"8_of_spades.png",
		"9_of_spades.png",
		"10_of_spades.png",
		"jack_of_spades.png",
		"queen_of_spades.png",
		"king_of_spades.png",
		"ace_of_spades.png",
		"2_of_diamonds.png",
		"3_of_diamonds.png",
		"4_of_diamonds.png",
		"5_of_diamonds.png",
		"6_of_diamonds.png",
		"7_of_diamonds.png",
		"8_of_diamonds.png",
		"9_of_diamonds.png",
		"10_of_diamonds.png",
		"jack_of_diamonds.png",
		"queen_of_diamonds.png",
		"king_of_diamonds.png",
		"ace_of_diamonds.png",
		"2_of_hearts.png",
		"3_of_hearts.png",
		"4_of_hearts.png",
		"5_of_hearts.png",
		"6_of_hearts.png",
		"7_of_hearts.png",
		"8_of_hearts.png",
		"9_of_hearts.png",
		"10_of_hearts.png",
		"jack_of_hearts.png",
		"queen_of_hearts.png",
		"king_of_hearts.png",
		"ace_of_hearts.png",
		"cardBack.png"
	};

	// Load textures
	textures.resize(53);
	for (int i = 0; i < 53; i++)
	{
		this->textures[i] = new sf::Texture();
		if (!textures[i]->loadFromFile("Resources/Cards/" + paths[i]))
		{
			throw "Could not load " + paths[i] + " file";
		}
	}

	// Init background
	if (!this->backgroundTex.loadFromFile("Resources/background.jpg"))
		throw "Could not load background.jpg file";
	this->background.setTexture(this->backgroundTex);
	this->background.setScale(3.6f, 3.6f);
}

void Poker::initFont()
{
	if (!this->font.loadFromFile("Resources/Fonts/font.ttf"))
		throw "Could not load font.ttf file";
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

void Poker::initButtons()
{
	this->buttons["DEAL"] = new Button(50.f, this->window->getSize().y - 132.f, 150.f, 92.f,
		this->font, "Deal",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));

	this->buttons["EXIT"] = new Button(250.f, this->window->getSize().y - 132.f, 150.f, 92.f,
		this->font, "Exit",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33));
}

void Poker::initGui()
{
	// Payout text
	this->payoutText.setFont(this->font);
	this->payoutText.setFillColor(sf::Color::Yellow);
	this->payoutText.setOutlineColor(sf::Color::Black);
	this->payoutText.setOutlineThickness(3);
	this->payoutText.setCharacterSize(62);
	this->payoutText.setPosition(this->window->getSize().x / 2.f - this->payoutText.getGlobalBounds().width - 150.f,
		this->window->getSize().y - this->payoutText.getGlobalBounds().height - 110.f);

	// Money text
	this->moneyText.setFont(this->font);
	this->moneyText.setFillColor(sf::Color::Yellow);
	this->moneyText.setOutlineColor(sf::Color::Black);
	this->moneyText.setOutlineThickness(3);
	this->moneyText.setCharacterSize(54);
	this->moneyText.setPosition(this->window->getSize().x - this->moneyText.getGlobalBounds().width - 400.f,
		this->window->getSize().y - this->moneyText.getGlobalBounds().height - 100.f);
	this->moneyText.setString("Cash: $" + std::to_string(this->money));

	// Coin text
	this->coinText.setFont(this->font);
	this->coinText.setFillColor(sf::Color::Yellow);
	this->coinText.setOutlineColor(sf::Color::Black);
	this->coinText.setOutlineThickness(3);
	this->coinText.setCharacterSize(54);
	this->coinText.setPosition(this->window->getSize().x - this->coinText.getGlobalBounds().width - 350.f, 50.f);
	this->coinText.setString("Coin value: \n \t $100");

	// Wager text
	this->wagerText.setFont(this->font);
	this->wagerText.setFillColor(sf::Color::Yellow);
	this->wagerText.setOutlineColor(sf::Color::Black);
	this->wagerText.setOutlineThickness(3);
	this->wagerText.setCharacterSize(54);
	this->wagerText.setPosition(this->window->getSize().x - this->wagerText.getGlobalBounds().width - 300.f, 200.f);
	this->wagerText.setString("Wager: \n  $500");
}

void Poker::initDeal()
{
	this->deal = new Deal(this->window, this->cards, 100, 500, this->font);
}


Poker::Poker(sf::RenderWindow* window, std::stack<Phase*>* phases)
	: Phase(window, phases)
{
	this->initVariables();
	this->initTextures();
	this->initFont();
	this->initCards();
	this->initCardBacks();
	this->initButtons();
	this->initGui();
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

	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


bool Poker::canPlay()
{
	if (this->counter < 30 || this->money == 0)
	{
		this->counter++;
		return false;
	}
	return true;
}

void Poker::updateMoney()
{
	this->money += this->deal->checkHand();
}

void Poker::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// Deal
	if (this->canPlay() && this->buttons["DEAL"]->isPressed())
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

			this->updateMoney();
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
	if (this->buttons["EXIT"]->isPressed())
		this->endPhase();
}

void Poker::updateGui()
{
	if (this->check)
		this->payoutText.setString("Payout: $" + std::to_string(this->deal->checkHand() + 500));

	this->moneyText.setString("Cash: $" + std::to_string(this->money));
}

void Poker::update(const float& dt)
{
	this->updateMousePositions();
	this->updateButtons();
	this->updateGui();

	if (this->change)
		this->deal->update();
}

void Poker::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Poker::renderGui(sf::RenderTarget* target)
{
	if (this->check)
		target->draw(this->payoutText);

	target->draw(this->moneyText);
	target->draw(this->coinText);
	target->draw(this->wagerText);
}

void Poker::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
	this->renderGui(target);

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

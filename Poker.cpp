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
	const std::vector<std::string> paths
	{
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
	for (const auto& suit : { CLUBS, SPADES, DIAMONDS, HEARTS }) 
	{
		for (int j = 2; j <= 14; j++) 
		{
			this->cards.push_back(new Card(*this->textures[i++], j, suit));
		}
	}
}

void Poker::initCardBacks()
{
	const float scale = 1.4f;
	const float x = 210.f;
	const float y = 530.f;

	for (size_t i = 0; i < 5; ++i) 
	{
		this->cardBacks.push_back(sf::Sprite(*this->textures[52]));
		this->cardBacks[i].setScale(scale, scale);
		this->cardBacks[i].setPosition(x + i * (cardBacks[0].getGlobalBounds().width + 100.f), y);
	}
	this->cardBacks[0].setPosition(x, y);
}

void Poker::initButtons()
{
	this->buttons.emplace("DEAL", new Button(50.f, this->window->getSize().y - 132.f, 150.f, 92.f,
		this->font, "Deal",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33)));

	this->buttons.emplace("EXIT", new Button(250.f, this->window->getSize().y - 132.f, 150.f, 92.f,
		this->font, "Exit",
		sf::Color(207, 27, 27), sf::Color(171, 32, 32), sf::Color(128, 33, 33)));
}

void Poker::initGui()
{
	// Hand table
	this->handTable = std::unique_ptr<HandTable> (new HandTable(50.f, 50.f, 1000.f, 350.f, this->font));

	// Payout text
	this->texts.emplace("PAYOUT", new sf::Text());
	this->texts.at("PAYOUT")->setFont(this->font);
	this->texts.at("PAYOUT")->setFillColor(sf::Color::Yellow);
	this->texts.at("PAYOUT")->setOutlineColor(sf::Color::Black);
	this->texts.at("PAYOUT")->setOutlineThickness(3);
	this->texts.at("PAYOUT")->setCharacterSize(62);
	this->texts.at("PAYOUT")->setPosition(this->window->getSize().x / 2.f - this->texts.at("PAYOUT")->getGlobalBounds().width - 150.f,
		this->window->getSize().y - this->texts.at("PAYOUT")->getGlobalBounds().height - 110.f);

	// Money text
	this->texts.emplace("MONEY", new sf::Text());
	this->texts.at("MONEY")->setFont(this->font);
	this->texts.at("MONEY")->setFillColor(sf::Color::Yellow);
	this->texts.at("MONEY")->setOutlineColor(sf::Color::Black);
	this->texts.at("MONEY")->setOutlineThickness(3);
	this->texts.at("MONEY")->setCharacterSize(54);
	this->texts.at("MONEY")->setPosition(this->window->getSize().x - this->texts.at("MONEY")->getGlobalBounds().width - 400.f,
		this->window->getSize().y - this->texts.at("MONEY")->getGlobalBounds().height - 100.f);
	this->texts.at("MONEY")->setString("Cash: $" + std::to_string(this->money));

	// Coin text
	this->texts.emplace("COIN", new sf::Text());
	this->texts.at("COIN")->setFont(this->font);
	this->texts.at("COIN")->setFillColor(sf::Color::Yellow);
	this->texts.at("COIN")->setOutlineColor(sf::Color::Black);
	this->texts.at("COIN")->setOutlineThickness(3);
	this->texts.at("COIN")->setCharacterSize(54);
	this->texts.at("COIN")->setPosition(this->window->getSize().x - this->texts.at("COIN")->getGlobalBounds().width - 350.f, 50.f);
	this->texts.at("COIN")->setString("Coin value: \n \t $100");

	// Wager text
	this->texts.emplace("WAGER", new sf::Text());
	this->texts.at("WAGER")->setFont(this->font);
	this->texts.at("WAGER")->setFillColor(sf::Color::Yellow);
	this->texts.at("WAGER")->setOutlineColor(sf::Color::Black);
	this->texts.at("WAGER")->setOutlineThickness(3);
	this->texts.at("WAGER")->setCharacterSize(54);
	this->texts.at("WAGER")->setPosition(this->window->getSize().x - this->texts.at("WAGER")->getGlobalBounds().width - 300.f, 200.f);
	this->texts.at("WAGER")->setString("Wager: \n  $500");
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
	for (auto& texture : this->textures)
	{
		delete texture;
	}

	for (auto& card : this->cards)
	{
		delete card;
	}

	for (auto& button : this->buttons)
	{
		delete button.second;
	}

	for (auto it = this->texts.begin(); it != this->texts.end(); ++it)
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
	if (this->buttons.at("EXIT")->isPressed())
		this->endPhase();
}

void Poker::updateGui()
{
	if (this->check)
		this->texts["PAYOUT"]->setString("Payout: $" + std::to_string(this->deal->checkHand() + 500));

	this->texts["MONEY"]->setString("Cash: $" + std::to_string(this->money));
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
	this->handTable->render(target);

	if (this->check)
		target->draw(*this->texts["PAYOUT"]);

	target->draw(*this->texts["MONEY"]);
	target->draw(*this->texts["COIN"]);
	target->draw(*this->texts["WAGER"]);
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

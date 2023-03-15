#include "Casino.h"

void Casino::initWindow()
{
	srand(time(NULL));

	this->name = "Casino";
	this->window_width = 1920;
	this->window_height = 1080;
	this->fps = 120;
	this->videoMode = sf::VideoMode(this->window_width, this->window_height);

	this->window = new sf::RenderWindow(this->videoMode, this->name, sf::Style::Fullscreen);
	this->window->setFramerateLimit(fps);
}

void Casino::initPhase()
{
	this->phases.push(new Poker(this->window, &this->phases));
}


Casino::Casino()
{
	this->initWindow();
	this->initPhase();
}

Casino::~Casino()
{
	delete this->window;
}


void Casino::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
	}
}

void Casino::updateDt()
{
	// Updates the dt variable with the time it takes to update and render one frame
	this->dt = this->clock.restart().asSeconds();
}

void Casino::update()
{
	this->pollEvents();

	// Update phases
	if (!this->phases.empty())
	{
		this->phases.top()->update(this->dt);
		if (this->phases.top()->getQuit())
		{
			this->phases.top()->endPhase();
			delete this->phases.top();
			this->phases.pop();
		}
	}

	// End app
	else
	{
		this->window->close();
	}
}

void Casino::render()
{
	this->window->clear();

	// Render stuff
	if (!this->phases.empty())
		this->phases.top()->render();

	this->window->display();
}

void Casino::run()
{
	// Main loop
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
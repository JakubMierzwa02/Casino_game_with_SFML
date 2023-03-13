#include "Casino.h"

void Casino::initWindow()
{
	srand(time(NULL));

	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Casino game", sf::Style::Fullscreen);
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

void Casino::update()
{
	this->pollEvents();

	// Update phases
	if (!this->phases.empty())
	{
		this->phases.top()->update();
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
		this->update();
		this->render();
	}
}
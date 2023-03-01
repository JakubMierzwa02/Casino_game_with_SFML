#include "Casino.h"

void Casino::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "Casino game");
}

Casino::Casino()
{
	this->initWindow();
}

Casino::~Casino()
{
	delete this->window;
}

void Casino::update()
{

}

void Casino::render()
{
	this->window->clear();

	// Render stuff

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

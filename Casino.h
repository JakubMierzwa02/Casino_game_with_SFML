#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Casino
{
private:
	// Window
	sf::RenderWindow* window;

	// Events
	sf::Event ev;

	// Initializer functions
	void initWindow();

public:
	// Constructors / Destructors
	Casino();
	virtual ~Casino();

	// Functions
	void pollEvents();

	void update();
	void render();

	void run();
};


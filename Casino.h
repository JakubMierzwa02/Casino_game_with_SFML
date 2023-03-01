#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Casino
{
private:
	// Window
	sf::RenderWindow* window;

	// Initializer functions
	void initWindow();

public:
	// Constructors / Destructors
	Casino();
	virtual ~Casino();

	// Functions
	void update();
	void render();

	void run();
};


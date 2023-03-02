#pragma once

#include "Phase.h"

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


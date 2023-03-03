#pragma once

#include "Phase.h"

class Casino
{
private:
	// Window
	sf::RenderWindow* window;

	// Events
	sf::Event ev;

	// Phases
	std::stack<Phase*>* phases;

	// Initializer functions
	void initWindow();
	void initPhase();

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


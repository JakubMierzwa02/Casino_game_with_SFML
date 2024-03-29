#pragma once

#include "Poker.h"

class Casino
{
private:
	// Window
	unsigned int window_width;
	unsigned int window_height;
	sf::VideoMode videoMode;
	std::string name;
	unsigned int fps;
	sf::RenderWindow* window;

	// Events
	sf::Event ev;

	// Clock
	sf::Clock clock;
	float dt;

	// Phases
	std::stack<Phase*> phases;

	// Initializer functions
	void initWindow();
	void initPhase();

public:
	// Constructors / Destructors
	Casino();
	virtual ~Casino();

	// Functions
	void pollEvents();
	void updateDt();

	void update();
	void render();

	void run();
};


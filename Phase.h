#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <stack>

class Phase
{
private:
	// Window
	sf::RenderWindow* window;

	// Phases
	std::stack<Phase*>* phases;

	bool quit;

public:
	Phase(sf::RenderWindow* window, std::stack<Phase*>* phases);
	virtual ~Phase();

	const bool getQuit() const;

	void endPhase();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
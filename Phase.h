#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <stack>

class Phase
{
private:

protected:
	// Window
	sf::RenderWindow* window;

	// Phases
	std::stack<Phase*>* phases;

	// Mouse positions
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	bool quit;

public:
	Phase(sf::RenderWindow*, std::stack<Phase*>*);
	virtual ~Phase();

	const bool getQuit() const;

	void endPhase();

	void updateMousePositions();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
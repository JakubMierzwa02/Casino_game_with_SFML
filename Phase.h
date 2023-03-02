#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Phase
{
private:
	// Window
	sf::RenderWindow* window;

	bool quit;

public:
	Phase(sf::RenderWindow* window);
	virtual ~Phase();

	const bool getQuit() const;

	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
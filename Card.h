#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

enum Color { CLUBS = 0, SPADES = 1, DIAMONDS = 2, HEARTS = 3 };

class Card
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int value;
	Color color;

public:
	// Constructors / Destructors
	Card(sf::Texture, int, Color);
	virtual ~Card();

	// Accessors
	const int& getValue() const;
	const Color& getColor() const;
	const sf::FloatRect& getBounds() const;

	// Modifiers
	void setPosition(float, float);

	// Functions
	void update();
	void render(sf::RenderTarget*);

};
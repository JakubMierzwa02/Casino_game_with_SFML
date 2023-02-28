#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "Casino game");

	window.clear();

	window.display();

	return 0;
}
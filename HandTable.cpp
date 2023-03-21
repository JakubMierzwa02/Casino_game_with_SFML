#include "HandTable.h"

void HandTable::initText()
{

}

HandTable::HandTable(float pos_x, float pos_y, float width, float height, sf::Font font)
	: font(font)
{
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setSize(sf::Vector2f(width, height));

	this->shape.setFillColor(sf::Color(0, 0, 0, 190));
	this->shape.setOutlineColor(sf::Color::Yellow);
	this->shape.setOutlineThickness(3);

	this->initText();
}

HandTable::~HandTable()
{

}

void HandTable::render(sf::RenderTarget*)
{

}

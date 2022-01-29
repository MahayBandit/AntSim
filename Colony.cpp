#include "include/Colony.h"

Colony::Colony(sf::Vector2f pos)
{
	radius = 15.0f;
	body.setPosition(pos);
	body.setRadius(radius);
	body.setOrigin(radius, radius);
	body.setFillColor(sf::Color::Blue);
}

sf::Vector2f Colony::GetPos() const
{
	return body.getPosition();
}

float Colony::GetRadius() const
{
	return radius;
}

float Colony::GetDistance(sf::Vector2f pos) const
{
	return sqrt(powf(GetPos().x - pos.x, 2.0f) + powf(GetPos().y - pos.y, 2.0f));
}

void Colony::Render(sf::RenderWindow* window)
{
	window->draw(body);
}
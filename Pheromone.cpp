#include "include/Pheromone.h"

Pheromone::Pheromone(sf::Vector2f pos, bool toFood)
{
	radius = 0.5f;
	body.setPosition(pos);
	body.setRadius(radius);
	body.setOrigin(radius, radius);

	if (toFood)
		body.setFillColor(sf::Color::Green);
	else
		body.setFillColor(sf::Color::Blue);

	intensity = 10;
	toDelete = false;
}

sf::Vector2f Pheromone::GetPos() const
{
	return body.getPosition();
}

float Pheromone::GetDistance(sf::Vector2f pos) const
{
	return sqrt(powf(GetPos().x - pos.x, 2) + powf(GetPos().y - pos.y, 2));
}

void Pheromone::Diffuse()
{
	intensity--;
	if (intensity == 0)
		toDelete = true;
}

void Pheromone::Render(sf::RenderWindow* window)
{
	window->draw(body);
}
#pragma once

#include <SFML/Graphics.hpp>

class Colony
{
	sf::CircleShape body;

	float radius;

public:
	Colony(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
	sf::Vector2f GetPos() const;
	float GetRadius() const;
	float GetDistance(sf::Vector2f pos) const;
	void Render(sf::RenderWindow* window);
};
#pragma once

#include <SFML/Graphics.hpp>

class Pheromone
{
	sf::CircleShape body;
	float radius;
	int intensity;

public:
	Pheromone(sf::Vector2f pos, bool toFood);
	bool toFood;
	bool toDelete;
	sf::Vector2f GetPos() const;
	float GetDistance(sf::Vector2f pos) const;
	void Diffuse();
	void Render(sf::RenderWindow* window);
};


#pragma once

#include <SFML/Graphics.hpp>

class FoodSource
{
	sf::RectangleShape body;
	int foodCount;
public:
	FoodSource(sf::Vector2f pos);
	sf::Vector2f GetPos() const;
	float GetDistance(sf::Vector2f pos) const;
	bool GiveFood();
	void Render(sf::RenderWindow* window);
};

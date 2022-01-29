#pragma once

#include <SFML/Graphics.hpp>

class Ant
{
	sf::RectangleShape body;
	sf::Vector2f detection;
	sf::CircleShape test;

	float speed;
	float wanderCoef;
	float detectRadius;
	bool holdingFood;
	int pherLeft;

	void ResetPheromones();

public:
	Ant(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
	sf::Vector2f GetPos() const;
	sf::Vector2f GetDetect() const;
	void Rotate(float deg);
	bool IsHoldingFood() const;
	void PickFood();
	void ColonyInt();
	void Update();
	void Render(sf::RenderWindow* window);
};


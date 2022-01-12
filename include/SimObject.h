#pragma once

#include <SFML/Graphics.hpp>

class SimObject
{
public:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	SimObject(sf::String, float, float, int, int);
	bool SetTexture(sf::String);
	virtual void Update();
};
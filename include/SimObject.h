#pragma once

#include <SFML/Graphics.hpp>

class SimObject
{
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SimObject(sf::String, float, float);
	sf::FloatRect collsionBox;

	bool SetTexture(sf::String);
	void Render(sf::RenderWindow*);
};
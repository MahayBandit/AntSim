#pragma once

#include <SFML/Graphics.hpp>

class SimObject
{
protected:
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SimObject(sf::String, sf::Vector2f);
	sf::FloatRect collsionBox;

	sf::Vector2f GetPostion();
	bool SetTexture(sf::String);
	void Render(sf::RenderWindow*);
};
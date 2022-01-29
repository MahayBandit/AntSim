#pragma once

#include <SFML/Graphics.hpp>

class SimObject
{
	sf::RectangleShape bodyRect;
	sf::CircleShape bodyCirc;
public:
	sf::Vector2f GetPos() const;

};
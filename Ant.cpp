#include "include/Ant.h"

bool Ant::IsHoldingFood() const
{
	return holdingFood;
}

void Ant::Update()
{
	//Movement behaviour
	sprite.rotate((rand() % 181 - 90) * wanderStrength);

	float degree = sprite.getRotation();
	float rad = degree * 3.14159265 / 180;
	sf::Vector2f angle(cos(rad), sin(rad));
	
	sprite.move(angle);
}
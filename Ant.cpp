#include "include/Ant.h"

void Ant::InitVariables()
{
	sprite.setOrigin(2, 1);

	holdingFood = false;
	speed = 1.0f;
	wanderStrength = 0.25f;
}

void Ant::PickUpFood()
{
	holdingFood = true;

	if (!SetTexture("sprites/PH_Ant_holding.png"))
		return;
}

bool Ant::IsHoldingFood() const
{
	return holdingFood;
}

void Ant::Update()
{
	//Movement behaviour
	sprite.rotate((rand() % 181 - 90) * wanderStrength);

	float degree = sprite.getRotation();
	float rad = degree * 3.14159265f / 180.0f;
	sf::Vector2f angle(cos(rad), sin(rad));
	
	sprite.move(angle);
}

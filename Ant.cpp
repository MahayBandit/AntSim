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

void Ant::ReturnFood()
{
	holdingFood = false;

	if (!SetTexture("sprites/PH_Ant.png"))
		return;
}


bool Ant::IsHoldingFood() const
{
	return holdingFood;
}

void Ant::ResetToHomePheromone()
{
	toHomePheromoneInt = 10.0f;
}

void Ant::ResetToFoodPheromone()
{
	toHomePheromoneInt = 10.0f;
}


void Ant::Update()
{
	//Wander behaviour
	sprite.rotate((rand() % 181 - 90) * wanderStrength);

	float degree = sprite.getRotation();
	float rad = degree * 3.14159265f / 180.0f;
	sf::Vector2f angle(cos(rad), sin(rad));
	
	sprite.move(angle);

	//Update collsion box
	collsionBox = sprite.getGlobalBounds();

	//Diffuse pheromones over distance
	toHomePheromoneInt -= 0.013f;
	toFoodPheromoneInt -= 0.013f;
}



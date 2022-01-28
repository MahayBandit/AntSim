#include "include/Ant.h"

void Ant::InitVariables()
{
	sprite.setOrigin(2, 1);

	holdingFood = false;
	speed = 1.0f;
	wanderStrength = 0.1f;
	//toHomePheromoneInt = 20;
	//toFoodPheromoneInt = 20;

	for (int i = 0; i < 3; i++)
	{
		detectRect[i].setSize(sf::Vector2f(10, 10));
		//detectRect[i].setFillColor(sf::Color::White);
	}
}

void Ant::PickUpFood()
{
	holdingFood = true;
	toHomePheromoneInt = 0;
	toFoodPheromoneInt = 20;

	if (!SetTexture("sprites/PH_Ant_holding.png"))
		return;
}

void Ant::ReturnFood()
{
	holdingFood = false;

	toFoodPheromoneInt = 0;

	if (!SetTexture("sprites/PH_Ant.png"))
		return;
}


bool Ant::IsHoldingFood() const
{
	return holdingFood;
}

void Ant::ResetToHomePheromone()
{
	toHomePheromoneInt = 20;
}

void Ant::ResetToFoodPheromone()
{
	toHomePheromoneInt = 20;
}

void Ant::Update(std::vector<Pheromone*>& Pheromones)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < Pheromones.size(); j++)
		{
			if (detectBox[i].contains(Pheromones[j]->GetPostion()))
			{
				if (IsHoldingFood() && Pheromones[j]->type)
				{
					switch (i)
					{
					case 0: sprite.rotate(-25);
						break;
					case 1: sprite.rotate(0);
						break;
					case 2: sprite.rotate(25);
						break;
					default:
						break;
					}
					break;
				}

				if (!IsHoldingFood() && !Pheromones[j]->type)
				{
					switch (i)
					{
					case 0: sprite.rotate(-25 );
						break;
					case 1: sprite.rotate(0);
						break;
					case 2: sprite.rotate(25);
						break;
					default:
						break;
					}
					break;
				}
			}
			else
			{
				//Wander behaviour
				sprite.rotate((rand() % 181 - 90) * wanderStrength);
				break;
			}
		}
	}

	float degree = sprite.getRotation();
	float rad = degree * 3.14159265f / 180.0f;
	sf::Vector2f angle(cos(rad), sin(rad));
	
	sprite.move(angle * speed);
	
	for(int i = 0; i < 3; i++)
	{
		detectRect[i].setPosition(sprite.getPosition());
	}
	
	detectRect[0].setRotation(degree - 90);
	detectRect[1].setRotation(degree - 45);
	detectRect[2].setRotation(degree);

	//Update collsion box
	collsionBox = sprite.getGlobalBounds();
	for (int i = 0; i < 3; i++)
	{
		detectBox[i] = detectRect[i].getGlobalBounds();
	}

}




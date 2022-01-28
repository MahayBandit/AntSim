#include "include/Pheromone.h"

void Pheromone::InitVariables(bool type, int intensity)
{
	this->type = type;
	this->intensity = intensity;
	toDeletion = false;
}

void Pheromone::Update(sf::Time dTime)
{
	if (dTime.asSeconds() > 2.5f)
		intensity--;

	if (intensity < 0)
		toDeletion = true;
}

int Pheromone::GetIntensity()
{
	return intensity;
}

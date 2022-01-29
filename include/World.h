#pragma once

#include "include/Ant.h"
#include "include/FoodSource.h"
#include "include/Colony.h"
#include "include/Pheromone.h"

class World
{
public:
	Colony* colony;

	std::vector<Ant*> ants;
	std::vector<FoodSource*> food;
	std::vector<Pheromone*> pheromones;

	World();

	void SpawnAnt(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
	void SpawnFood(sf::Vector2f pos);
	void SpawnPheromone(sf::Vector2f pos, bool toFood = false);

	void CheckFood();
	void CheckColony();
	void CheckPheromones(int i);
};


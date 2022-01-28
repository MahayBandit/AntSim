#pragma once

#include "include/SimObject.h"
#include "include/Pheromone.h"

class Ant : public SimObject
{
	using SimObject::SimObject;
	bool holdingFood;
	float speed;
	float wanderStrength;
	sf::RectangleShape detectRect[3]; // 0 - left detection, 1 - min detection, 2 - right detection
	sf::FloatRect detectBox[3];

public:
	int toHomePheromoneInt;
	int toFoodPheromoneInt;
	void InitVariables();
	void PickUpFood();
	void ReturnFood();
	bool IsHoldingFood() const;
	void ResetToHomePheromone();
	void ResetToFoodPheromone();
	void Update(std::vector<Pheromone*>& Pheromones);
	
	
	
};


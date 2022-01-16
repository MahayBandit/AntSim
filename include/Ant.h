#pragma once

#include "include/SimObject.h"

class Ant : public SimObject
{
	using SimObject::SimObject;
	bool holdingFood;
	float speed;
	float wanderStrength;
	float toHomePheromoneInt;
	float toFoodPheromoneInt;

public:
	void InitVariables();
	void PickUpFood();
	void ReturnFood();
	bool IsHoldingFood() const;
	void ResetToHomePheromone();
	void ResetToFoodPheromone();
	void Update();
	
};


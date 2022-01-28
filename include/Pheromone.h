#pragma once

#include "include/SimObject.h"

class Pheromone : public SimObject
{
	using SimObject::SimObject;
	int intensity;
public:
	bool type; // false = to home pheromone, true = to food pheromone
	bool toDeletion;
	void InitVariables(bool, int);
	void Update(sf::Time);
	int GetIntensity();
};
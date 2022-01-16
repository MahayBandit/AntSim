#pragma once

#include "include/Ant.h"
#include "include/SimObject.h"
#include <vector>

class FoodSource : public SimObject
{
	using SimObject::SimObject;
	std::vector<Ant*> Ants;
	int stage;

public:
	int foodLeft;
	void InitVariables(std::vector<Ant*>&);
	void Update();
};


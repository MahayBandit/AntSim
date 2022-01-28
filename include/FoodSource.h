#pragma once

#include "include/Ant.h"
#include "include/SimObject.h"
#include <vector>
#include <iostream>

class FoodSource : public SimObject
{
	using SimObject::SimObject;
	unsigned int stage;
	int foodLeft;

public:
	void InitVariables();
	void Update(std::vector<Ant*>&);
};

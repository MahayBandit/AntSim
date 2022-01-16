#pragma once

#include "include/SimObject.h"

class Ant : public SimObject
{
	using SimObject::SimObject;
	bool holdingFood;
	float speed;
	float wanderStrength;

public:
	void InitVariables();
	void PickUpFood();
	bool IsHoldingFood() const;
	void Update();
	
};


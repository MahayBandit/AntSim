#pragma once

#include "SimObject.h"

class Ant : public SimObject
{
	using SimObject::SimObject;
	bool holdingFood = false;
	float speed = 1.0f;
	float steerStrength = 1.0f;
	float wanderStrength = 0.25f;

	sf::Vector2f velocity;
	sf::Vector2f desiredDirection;

public:
	bool IsHoldingFood() const;
	void Update();
};


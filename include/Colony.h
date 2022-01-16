#pragma once

#include "include/SimObject.h"
#include "include/Ant.h"

class Colony : public SimObject
{
	using SimObject::SimObject;
public:
	void InitVariables();
	void Update(std::vector<Ant*>&);
};
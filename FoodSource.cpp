#include "include/FoodSource.h"

void FoodSource::InitVariables(std::vector<Ant*>& Ants)
{
	this->Ants.clear();
	sprite.setOrigin(5, 5);

	stage = 3;
	foodLeft = 100;
	this->Ants = Ants;
}

void FoodSource::Update()
{
	for (int i = 0; i < Ants.size(); i++)
	{
		if (collsionBox.intersects(Ants[i]->collsionBox) && foodLeft > 0 && !Ants[i]->IsHoldingFood())
		Ants[i]->PickUpFood();
	}
}

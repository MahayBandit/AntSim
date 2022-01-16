#include "include/FoodSource.h"

void FoodSource::InitVariables()
{
	sprite.setOrigin(5, 5);

	stage = 3;
	foodLeft = 100;
}

void FoodSource::Update(std::vector<Ant*>& Ants)
{
	//Give food to passing ants
	for (int i = 0; i < Ants.size(); i++)
	{
		if (collsionBox.intersects(Ants[i]->collsionBox))
		{
			if (foodLeft > 0 && !Ants[i]->IsHoldingFood())
			{
				Ants[i]->PickUpFood();
				Ants[i]->ResetToFoodPheromone();
			}
		}
	}
}

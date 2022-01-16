#include "include/Colony.h"

void Colony::InitVariables()
{
	sprite.setOrigin(25, 25);
}

void Colony::Update(std::vector<Ant*>& Ants)
{
	//Check for passing ants
	for (int i = 0; i < Ants.size(); i++)
	{
		if (collsionBox.intersects(Ants[i]->collsionBox))
		{
			if (Ants[i]->IsHoldingFood())
			{
				Ants[i]->ReturnFood();
			}
			Ants[i]->ResetToHomePheromone();
		}
	}
}
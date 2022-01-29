#include "include/World.h"

World::World()
{
	colony = new Colony(sf::Vector2f(800.0f, 450.0f));

	ants.clear();
	food.clear();
	pheromones.clear();
}

void World::SpawnAnt(sf::Vector2f pos)
{
	ants.push_back(new Ant(pos));
}

void World::SpawnFood(sf::Vector2f pos)
{
	food.push_back(new FoodSource(pos));
}

void World::SpawnPheromone(sf::Vector2f pos, bool toFood)
{
	pheromones.push_back(new Pheromone(pos, toFood));
}

void World::CheckFood()
{
	for (FoodSource * food : food)
	{
		for (Ant* ant : ants)
		{
			if (food->GetDistance(ant->GetPos()) < 10 && food->GiveFood())
				ant->PickFood();
		}
	}
}

void World::CheckColony()
{
	for (Ant* ant : ants)
	{
		float distance = colony->GetDistance(ant->GetPos());

		if (distance < colony->GetRadius())
			ant->ColonyInt();
	}
}

void World::CheckPheromones(int i)
{
	//for (Ant* ant : ants)
	//{
		float detectRad = 25.f;
		for (Pheromone* pher : pheromones)
		{
			float ant2pehr = pher->GetDistance(ants[i]->GetPos());
			if (ant2pehr < detectRad)
			{
				float pher2detect = pher->GetDistance(ants[i]->GetDetect());
				if (pher2detect < tan(3.14f / 3.f) * detectRad)
				{
					float cosa = (powf(ant2pehr, 2.f) + powf(detectRad, 2.f) - powf(pher2detect, 2.f)) / (2 * ant2pehr * detectRad);
					
					if(ants[i]->IsHoldingFood() && !pher->toFood)
						ants[i]->Rotate(acos(cosa) * 180.f / 3.14f);

					if(!ants[i]->IsHoldingFood() && pher->toFood)
						ants[i]->Rotate(acos(cosa) * 180.f / 3.14f);
				}
			}
		}
	//}
}
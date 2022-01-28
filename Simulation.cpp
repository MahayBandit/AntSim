#include "include/Simulation.h"

Simulation::Simulation()
{
	videoMode.width = 1600;
	videoMode.height = 900;
	window = new sf::RenderWindow(videoMode, "AntSim");

	window->setFramerateLimit(60);

	Ants.clear();
	Food.clear();
	placePheromoneTimer.restart();
	diffPheromoneTimer.restart();

	//Initialize Colony
	colony = new Colony("sprites/PH_Colony.png", sf::Vector2f(videoMode.width / 2, videoMode.height / 2));
	colony->InitVariables();

	//Initialize Ants
	for (int i = 0; i < 250; i++)
	{
		Ants.push_back(new Ant("sprites/PH_Ant.png", sf::Vector2f(videoMode.width / 2, videoMode.height / 2)));
		Ants[i]->InitVariables();
	}

}

Simulation::~Simulation()
{
	delete colony;
	delete window;
}

const bool Simulation::Running()
{
	return window->isOpen();
}

void Simulation::PollEvents()
{
	while (window->pollEvent(event))
	{
		//Close window
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			//Close window on 'escape' press
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

				//Spawn food source at current mouse postion
				Food.push_back(new FoodSource("sprites/PH_Food.png", sf::Vector2f(mousePos.x, mousePos.y)));
				Food[Food.size() - 1]->InitVariables();
				std::cout << "Food created at - x: " << mousePos.x << " y: " << mousePos.y << std::endl;
			}
		}
	}
}

void Simulation::Update()
{
	PollEvents();

	//Update Colony
	colony->Update(Ants);

	//std::cout << "Timer: " << clock.getElapsedTime().asSeconds() << std::endl;

	//Update Ants
	for (int i = 0; i < Ants.size(); i++)
	{
		Ants[i]->Update(Pheromones);
		if (placePheromoneTimer.getElapsedTime().asSeconds() > 0.25)
		{
			for (int j = 0; j < Ants.size(); j++)
			{
				if (Ants[j]->toHomePheromoneInt > 0 && !Ants[j]->IsHoldingFood())
				{
					Pheromones.push_back(new Pheromone("sprites/ToHomePheromone.png", Ants[j]->GetPostion()));
					Pheromones[Pheromones.size() - 1]->InitVariables(Ants[j]->IsHoldingFood(), Ants[j]->toHomePheromoneInt);
					Ants[j]->toHomePheromoneInt--;
				}
				else if (Ants[j]->toFoodPheromoneInt > 0 && Ants[j]->IsHoldingFood())
				{
					Pheromones.push_back(new Pheromone("sprites/ToFoodPheromone.png", Ants[j]->GetPostion()));
					Pheromones[Pheromones.size() - 1]->InitVariables(Ants[j]->IsHoldingFood(), Ants[j]->toFoodPheromoneInt);
					Ants[j]->toFoodPheromoneInt--;
				}		
			}
			placePheromoneTimer.restart();
		}
	}

	//Update food
	for (int i = 0; i < Food.size(); i++)
	{
		Food[i]->Update(Ants);
	}

	for (int i = 0; i < Pheromones.size(); i++)
	{
		Pheromones[i]->Update(diffPheromoneTimer.getElapsedTime());
		
		if (Pheromones[i]->toDeletion)
		{
			Pheromones.erase(Pheromones.begin() + i);
			//std::cout << "Pheromone " << i << ": erased" << std::endl;
		}
	}

	if (diffPheromoneTimer.getElapsedTime().asSeconds() > 2.5f)
		diffPheromoneTimer.restart();
}

void Simulation::Render()
{
	//Background color
	window->clear(sf::Color::Black);

	//Draw Pheromones
	for (int i = 0; i < Pheromones.size(); i++)
		Pheromones[i]->Render(window);

	//Draw Food
	for (int i = 0; i < Food.size(); i++)
		Food[i]->Render(window);

	//Draw Ants
	for (int i = 0; i < Ants.size(); i++)
	{
		Ants[i]->Render(window);
		//window->draw(Ants[i]->detectRect[0]);
		//window->draw(Ants[i]->detectRect[1]);
		//window->draw(Ants[i]->detectRect[2]);
	}

	//Draw Colony
	colony->Render(window);

	//Draw frame
	window->display();
}

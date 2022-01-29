#include "include/Simulation.h"

Simulation::Simulation()
{
	videoMode.width = 1600;
	videoMode.height = 900;
	window = new sf::RenderWindow(videoMode, "AntSim");

	window->setFramerateLimit(60);

	pheromonePlaceTimer.restart();
	pheromoneDiffTimer.restart();

	for (int i = 0; i < 100; i++)
		world.SpawnAnt(sf::Vector2f(800.0f, 450.0f));

	spawn = false;
}

Simulation::~Simulation()
{
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
				world.SpawnFood(sf::Vector2f(mousePos.x, mousePos.y));
				
			}
		}
	}
}

void Simulation::Update()
{
	int i = 0;
	PollEvents();

	//Update Ants
	for (Ant* ant : world.ants)
	{
		ant->Update();
		world.CheckPheromones(i++);
		if (spawn)
		{
			world.SpawnPheromone(ant->GetPos(), ant->IsHoldingFood());
		}
	}
	spawn = false;

	if (pheromonePlaceTimer.getElapsedTime().asSeconds() > 0.5f)
	{
		spawn = true;
		pheromonePlaceTimer.restart();
	}

	if (pheromoneDiffTimer.getElapsedTime().asSeconds() > 0.5f)
	{
		for (int i = 0; i < world.pheromones.size(); i++)
		{
			world.pheromones[i]->Diffuse();
			if (world.pheromones[i]->toDelete)
			{
				world.pheromones.erase(world.pheromones.begin() + i);
			}
			pheromoneDiffTimer.restart();
		}
	}

	//Collsion checks
	world.CheckFood();
	world.CheckColony();
	//world.CheckPheromones();
}

void Simulation::Render()
{
	//Background color
	window->clear(sf::Color::Black);
	
	//Render pheromones
	for (Pheromone* pher : world.pheromones)
		pher->Render(window);

	//Render food sources
	for (FoodSource* food : world.food)
		food->Render(window);

	//Render ants
	for (Ant* ant : world.ants)
		ant->Render(window);

	//Render colony
	world.colony->Render(window);
	
	//Draw frame
	window->display();
}

#include "include/Simulation.h"

Simulation::Simulation()
{
	videoMode.width = 1600;
	videoMode.height = 900;
	window = new sf::RenderWindow(videoMode, "AntSim");

	window->setFramerateLimit(60);

	Ants.clear();
	Food.clear();

	//Initialize Colony
	colony = new Colony("sprites/PH_Colony.png", videoMode.width / 2, videoMode.height / 2);
	colony->InitVariables();

	//Initialize Ants
	for (int i = 0; i < 250; i++)
	{
		Ants.push_back(new Ant("sprites/PH_Ant.png", videoMode.width / 2, videoMode.height / 2));
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
				Food.push_back(new FoodSource("sprites/PH_Food.png", mousePos.x, mousePos.y));
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

	//Update Ants
	for (int i = 0; i < Ants.size(); i++)
	{
		Ants[i]->Update();
	}

	//Update food
	for (int i = 0; i < Food.size(); i++)
	{
		Food[i]->Update(Ants);
	}

}

void Simulation::Render()
{
	//Background color
	window->clear(sf::Color::Black);

	//Draw Ants
	for (int i = 0; i < Ants.size(); i++)
		Ants[i]->Render(window);

	//Draw Food
	for (int i = 0; i < Food.size(); i++)
		Food[i]->Render(window);

	//Draw Colony
	colony->Render(window);


	//Draw frame
	window->display();
}

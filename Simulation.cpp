#include "include/Simulation.h"

Simulation::Simulation()
{
	videoMode.width = 1600;
	videoMode.height = 900;
	window = new sf::RenderWindow(videoMode, "AntSim");

	window->setFramerateLimit(60);

	//Initialize SimObjects
	simObjects.clear();

	//Initialize Ants
	for(int i = 0; i < 250; i++)
		simObjects.push_back(new Ant("sprites/PH_Ant.png", 800, 450, 2, 1));
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
	}
}

void Simulation::Update()
{
	PollEvents();

	//Update Objects
	for (int i = 0; i < simObjects.size(); i++)
		simObjects[i]->Update();
}

void Simulation::Render()
{
	//Background color
	window->clear(sf::Color::Black);

	//Draw Objects
	for (int i = 0; i < simObjects.size(); i++)
		window->draw(simObjects[i]->sprite);

	//Draw frame
	window->display();
}

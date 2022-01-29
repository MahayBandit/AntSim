#pragma once

#include <vector>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "include/World.h"

//This class handles rendering
class Simulation
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Clock pheromonePlaceTimer;
	sf::Clock pheromoneDiffTimer;

	World world;
	bool spawn;

public:
	//Constructors
	Simulation();
	~Simulation();

	//Methods
	const bool Running();
	void PollEvents();
	void Update();
	void Render();
};
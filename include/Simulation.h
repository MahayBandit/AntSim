#pragma once

#include "include/Ant.h"
#include "include/FoodSource.h"
#include "include/Colony.h"
#include <vector>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Simulation
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	Colony* colony;
	std::vector<Ant*> Ants;
	std::vector<FoodSource*> Food;

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
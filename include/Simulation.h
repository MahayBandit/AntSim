#pragma once

#include<vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "include/Ant.h"

class Simulation
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	sf::Vector2f colonyPos;
	std::vector<sf::Vector2f> antsPos;

public:
	std::vector<SimObject*> simObjects;

	//Constructors
	Simulation();
	~Simulation();

	//Methods
	const bool Running();
	void PollEvents();
	void Update();
	void Render();

};
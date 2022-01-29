#include "include/Ant.h"

Ant::Ant(sf::Vector2f pos) : detection(pos)
{
	body.setPosition(pos);
	body.setSize(sf::Vector2f(4.0f, 2.0f));
	body.setOrigin(2.0f, 1.0f);
	body.setRotation(rand() % 361);
	body.setFillColor(sf::Color::Blue);
	test.setRadius(1);
	test.setPosition(pos);
	test.setFillColor(sf::Color::Cyan);

	speed = 1.0f;
	wanderCoef = 0.15f;
	detectRadius = 25.0f;
	holdingFood = false;
}

sf::Vector2f Ant::GetPos() const
{
	return body.getPosition();
}

sf::Vector2f Ant::GetDetect() const
{
	return detection;
}

void Ant::Rotate(float deg)
{
	body.rotate(deg);
}

bool Ant::IsHoldingFood() const
{
	return holdingFood;
}

void Ant::ResetPheromones()
{
	pherLeft = 10;
}

void Ant::PickFood()
{
	holdingFood = true;
	body.setFillColor(sf::Color::Green);
	body.rotate(180.0f);
	ResetPheromones();
}

void Ant::ColonyInt()
{
	ResetPheromones();

	if (holdingFood)
	{
		holdingFood = false;
		body.setFillColor(sf::Color::Blue);
	}
}

void Ant::Update()
{
	body.rotate((rand() % 181 - 90) * wanderCoef);
	float degree = body.getRotation();
	float rad = degree * 3.14159265f / 180.0f;
	sf::Vector2f dir(cos(rad), sin(rad));

	body.move(dir * speed);
	test.setPosition(body.getPosition().x + dir.x * detectRadius, body.getPosition().y + dir.y * detectRadius);
	detection.x += body.getPosition().x + dir.x * detectRadius;
	detection.y += body.getPosition().y + dir.y * detectRadius;
}

void Ant::Render(sf::RenderWindow* window)
{
	//window->draw(test);
	window->draw(body);
}
#include "include/FoodSource.h"

FoodSource::FoodSource(sf::Vector2f pos)
{
	body.setPosition(pos);
	body.setSize(sf::Vector2f(10.0f, 10.0f));
	body.setOrigin(5.0f, 5.0f);
	body.setRotation(rand() % 361);
	body.setFillColor(sf::Color::White);
	
	foodCount = 100;
}

sf::Vector2f FoodSource::GetPos() const
{
	return body.getPosition();;
}

float FoodSource::GetDistance(sf::Vector2f pos) const
{
	return sqrt(powf(GetPos().x - pos.x, 2) + powf(GetPos().y - pos.y, 2));;
}

bool FoodSource::GiveFood()
{
	if (foodCount > 0)
	{
		foodCount--;
		return true;
	}
	else
	{
		return false;
	}
}

void FoodSource::Render(sf::RenderWindow* window)
{
	window->draw(body);
}
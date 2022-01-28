#include "include/SimObject.h"

SimObject::SimObject(sf::String textureName, sf::Vector2f pos)
{
	if (!SetTexture(textureName))
		return;
	//position = sf::Vector2f(pos.x, pos.y);
	sprite.setPosition(pos);
	sprite.setRotation(rand() % 361);

	collsionBox = sprite.getGlobalBounds();
}

sf::Vector2f SimObject::GetPostion()
{
	return sf::Vector2f(sprite.getPosition());
}

bool SimObject::SetTexture(sf::String filename)
{
	if (!texture.loadFromFile(filename))
		return false;

	texture.setSmooth(false);
	sprite.setTexture(texture);
	return true;
}

void SimObject::Render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

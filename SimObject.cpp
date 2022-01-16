#include "include/SimObject.h"

SimObject::SimObject(sf::String textureName, float pos_x, float pos_y)
{
	if (!SetTexture(textureName))
		return;
	position = sf::Vector2f(pos_x, pos_y);
	sprite.setPosition(position);
	sprite.setRotation(rand() % 361);

	collsionBox = sprite.getGlobalBounds();
}

bool SimObject::SetTexture(sf::String filename)
{
	if (!texture.loadFromFile(filename))
		return false;

	texture.setSmooth(true);
	sprite.setTexture(texture);
	return true;
}

void SimObject::Render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

#include "include/SimObject.h"

SimObject::SimObject(sf::String textureName, float pos_x, float pos_y, int org_x, int org_y)
{
	if (!SetTexture(textureName))
		return;

	sprite.setOrigin(org_x, org_y);
	position = sf::Vector2f(pos_x, pos_y);
	sprite.setPosition(position);
	sprite.setRotation(rand() % 361);
}

bool SimObject::SetTexture(sf::String filename)
{
	if (!texture.loadFromFile(filename))
		return false;

	texture.setSmooth(true);
	sprite.setTexture(texture);
	return true;
}

void SimObject::Update()
{
	return;
}

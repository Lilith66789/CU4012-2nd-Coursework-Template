#include "Collectables.h"

Collectables::Collectables()
{
	if (!texture.loadFromFile("Assets/Collectables/CrystalHeart.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
	setTag("Collectable");
}



void Collectables::update(float dt)
{
}

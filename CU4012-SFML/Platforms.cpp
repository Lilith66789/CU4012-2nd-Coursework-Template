#include "Platforms.h"
#include <iostream>

Platforms::Platforms()
{


	if (!PlatformTex.loadFromFile("Assets/TileSets/Foreground/Screenshot 2024-03-05 112159.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&PlatformTex);
	setSize(sf::Vector2f(500, 100));
	setCollisionBox(getPosition(), getSize());
}

void Platforms::update(float dt)
{
	setCollisionBox(getPosition(), getSize());

}

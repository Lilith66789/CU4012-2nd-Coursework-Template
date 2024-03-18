#include "Enemy.h"

Enemy::Enemy()
{
	health = 100;
	speed = 150;
	velocity.x = -150;

	if (!texture.loadFromFile("gfx/Goomba.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");
	setMass(50.f);
}

void Enemy::update(float dt)
{
	//std::cout<<isColliding()<<std::endl;
}

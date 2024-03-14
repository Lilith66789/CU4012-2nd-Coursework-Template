#include "Player.h"

Player::Player()
{

	health = 100;
	speed = 200;

	if (!texture.loadFromFile("Assets/Ball and Chain Bot/Run/runPlac.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity = sf::Vector2f(1, 0);
		move(-velocity*speed *dt);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity = sf::Vector2f(1, 0);
		move(velocity * speed * dt);
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity = sf::Vector2f(0, 1);
		move(-velocity * speed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity = sf::Vector2f(0, 1);
		move(velocity * speed * dt);
	}
}

void Player::update(float dt)
{
	if (!Colliding)
	{
		lastSafePosition = this->getPosition();
	}

	setCollisionBox(getPosition(), getSize());
	//move(sf::Vector2f(0, 0.02));
}




void Player::collisionResponse(GameObject* collider)
{
	this->setColliding(true);
	collider->setVelocity(sf::Vector2f(0, 0));
	setPosition(lastSafePosition);
}

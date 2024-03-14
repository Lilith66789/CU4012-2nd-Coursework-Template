#include "Player.h"


Player::Player()
{

	health = 100;
	speed = 150;

	if (!texture.loadFromFile("Assets/Ball and Chain Bot/Run/runPlac.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
	setMass(100.f);
	setTag("Player");

}

void Player::handleInput(float dt)
{

	velocity = sf::Vector2f(0, 0);


	// Check each key independently, rather than using else-if statements
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -1 * speed;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = 1 * speed;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y = 1 * speed;
	}
	
	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y = -1 * speed;
	}
}

void Player::update(float dt)
{

}

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

	velocity.x = 0.f;


	// Check each key independently, rather than using else-if statements
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -1 * speed;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = 1 * speed;
	}
	
	if (input->isKeyDown(sf::Keyboard::W)&&canJump|| input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(200.f);
	}
}

void Player::update(float dt)
{

}

void Player::ReduceHealth(float h)
{
	health -= h;
}

void Player::SetHealth(float ph)
{
	health = 100;
}

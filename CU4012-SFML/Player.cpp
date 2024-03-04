#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	//Moving UP 
	if (input->isKeyDown(sf::Keyboard::W))
	{
		//input->setKeyUp(sf::Keyboard::W);
		velocity = sf::Vector2f(0, -200);
		move(velocity * dt);
	}

	//Moving Down
	if (input->isKeyDown(sf::Keyboard::S))
	{
		//input->setKeyUp(sf::Keyboard::S);
		velocity = sf::Vector2f(0, 200);
		move(velocity * dt);
	}

	//Moving Left
	if (input->isKeyDown(sf::Keyboard::A))
	{
		//input->setKeyUp(sf::Keyboard::A);
		velocity = sf::Vector2f(-200, 0);
		move(velocity * dt);
	}

	//Moving Right 
	if (input->isKeyDown(sf::Keyboard::D))
	{
		//input->setKeyUp(sf::Keyboard::D);
		velocity = sf::Vector2f(200, 0);
		move(velocity * dt);
	}
}

void Player::update(float dt)
{
	move(sf::Vector2f(0, 0.02));
}

void Player::CollisionResponse(GameObject* collider)
{

}

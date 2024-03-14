#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;
	// Assuming these are class members
	bool isJumping = false;
	bool wasWPressedLastFrame = false;

public:
	Player();

	void handleInput(float dt);
	void update(float dt);


};


#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;
	int CollectableCount;
	sf::Text collectableText;
	sf::Font font;

public:
	Player();
	void handleInput(float dt);
	void update(float dt);
	float getHealth() { return health; }
	void ReduceHealth(float h);
	void AddCollectable() { CollectableCount++; }
	int getCollectableCount() { return CollectableCount; }
};


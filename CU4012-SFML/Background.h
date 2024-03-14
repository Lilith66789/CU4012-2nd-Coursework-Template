#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Background :
    public GameObject
{
	sf::Vector2f centerView = (sf::Vector2f(960.f, 540.f));
	float viewX = 960.f;
	sf::View view;
public:

	Background();
	~Background();

	void handleInput(float dt);

};


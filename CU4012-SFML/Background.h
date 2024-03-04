#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class Background :
    public GameObject
{
	sf::View view;
public:
	Background();
	~Background();

	void handleInput(float dt);
};


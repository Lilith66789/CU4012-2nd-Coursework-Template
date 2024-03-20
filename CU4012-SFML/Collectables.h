#pragma once
#include "Framework/GameObject.h"
class Collectables : public GameObject
{
    sf::Texture texture;

public:



    Collectables();

    void update(float dt);
};


#pragma once
#include "Framework/GameObject.h"
class Platforms :
    public GameObject
{
    sf::Texture PlatformTex;
public:
    Platforms();

    void update(float dt);
};


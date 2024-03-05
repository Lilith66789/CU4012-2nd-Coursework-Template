#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Player.h"
#include <string>
#include <iostream>
#include "Background.h"
#include "Player.h"
#include "Enemy.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
		//Player Objects 
	Player playerSprite;

	//Background stuff
	Background bg[4];
	Background bg1[4];
	Background bg2[4];
	Background bg3[4];

	sf::Texture backgroundTex[4];



	sf::View view;


	//Foreground Stuff
	Background fg1;

	sf::Texture foregroundTex1;

	Enemy e1;

};
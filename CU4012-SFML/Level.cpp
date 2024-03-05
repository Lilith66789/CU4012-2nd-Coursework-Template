#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects


	//Player Texture Initialisation 
	playerSprite.setPosition(100, 300);

	//Setting Input and Velocity 
	playerSprite.setInput(input);


	//Background
	backgroundTex[0].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/1.png");
	backgroundTex[1].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/2.png");
	backgroundTex[2].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/3.png");
	backgroundTex[3].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/5.png");

	//Foreground
	foregroundTex1.loadFromFile("Assets/TileSets/Foreground/Screenshot 2024-03-05 112159.png");


	//Background

	for (size_t i = 0; i < 4; i++)
	{
		bg[i].setTexture(&backgroundTex[i]);
		bg[i].setSize(sf::Vector2f(1920, 1080));
		bg[i].setPosition(sf::Vector2f(0, 0));
		bg[i].setInput(input);
		bg[i].setWindow(window);
	}

	for (size_t i = 0; i < 4; i++)
	{
		bg1[i].setTexture(&backgroundTex[i]);
		bg1[i].setSize(sf::Vector2f(1920, 1080));
		bg1[i].setPosition(sf::Vector2f(1920, 0));
		bg1[i].setInput(input);
		bg1[i].setWindow(window);
	}
	for (size_t i = 0; i < 4; i++)
	{
		bg2[i].setTexture(&backgroundTex[i]);
		bg2[i].setSize(sf::Vector2f(1920, 1080));
		bg2[i].setPosition(sf::Vector2f(3840, 0));
		bg2[i].setInput(input);
		bg2[i].setWindow(window);
	}
	for (size_t i = 0; i < 4; i++)
	{
		bg3[i].setTexture(&backgroundTex[i]);
		bg3[i].setSize(sf::Vector2f(1920, 1080));
		bg3[i].setPosition(sf::Vector2f(5760, 0));
		bg3[i].setInput(input);
		bg3[i].setWindow(window);
	}

	window->setView(view);

	//Foreground
	fg1.setTexture(&foregroundTex1);
	fg1.setSize(sf::Vector2f(150,50));
	fg1.setPosition(sf::Vector2f(100, 850));
	fg1.setInput(input);
	fg1.setWindow(window);

	e1.setPosition(500, 100);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerSprite.handleInput(dt);

	for (int i = 0; i < 4; i++)
	{
		bg[i].handleInput(dt);
		bg1[i].handleInput(dt);
		bg2[i].handleInput(dt);
		bg3[i].handleInput(dt);
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
}

// Update game objects
void Level::update(float dt)
{
	playerSprite.update(dt);
	e1.update(dt);

	if (playerSprite.checkCollision(e1.getCollisionBox()))
	{
		playerSprite.collisionResponse(&e1);
		
	}
	else
	{
		playerSprite.setColliding(false);
	}

}

// Render level
void Level::render()
{
	beginDraw();


	for (int i = 0; i < 4; i++) 
	{
		window->draw(bg[i]);
		window->draw(bg1[i]);
		window->draw(bg2[i]);
		window->draw(bg3[i]);

	}
	window->draw(fg1);
	
	window->draw(playerSprite);
	window->draw(playerSprite.getDebugCollisionBox());

	window->draw(e1);
	window->draw(e1.getDebugCollisionBox());

	endDraw();
}

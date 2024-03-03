#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects
	PlayerTex.loadFromFile("Assets/Ball and Chain Bot/Run/runPlac.png");

	//Player Texture Initialisation 
	playerSprite.setTexture(&PlayerTex);
	playerSprite.setSize(sf::Vector2f(100, 100));
	playerSprite.setPosition(300, 300);

	//Setting Input and Velocity 
	playerSprite.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	playerSprite.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(playerSprite);

	endDraw();
}

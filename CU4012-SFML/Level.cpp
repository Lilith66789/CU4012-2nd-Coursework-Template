#include "Level.h"
#include "Player.h"
#include "Collectables.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	};

	TileEditorText.setFont(font);
	TileEditorText.setCharacterSize(24);
	TileEditorText.setFillColor(sf::Color::Red);

	TileEditorText.setString(" Press E to edit tiles");
	TileEditorText.setPosition(0, 0);

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	};

	CollectableText.setFont(font);
	CollectableText.setCharacterSize(24);
	CollectableText.setFillColor(sf::Color::Red);


	CollectableText.setPosition(1600, 0);


	sf::View view(sf::FloatRect(0, 0, 1920, 1080));

	// initialise game objects

	p1.setPosition(100, 100);
	p1.setInput(input);

	e1.setPosition(500, 100);

	c1.setPosition(100, 300);


	world->AddGameObject(p1);
	world->AddGameObject(e1);
	world->AddGameObject(c1);

	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);

	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}

	//Background
	backgroundTex[0].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/1.png");
	backgroundTex[1].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/2.png");
	backgroundTex[2].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/3.png");
	backgroundTex[3].loadFromFile("Assets/TileSets/1 Backgrounds/1/Day/5.png");

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
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}

	// Check if 'E' is pressed to toggle editing mode
	if (input->isKeyDown(sf::Keyboard::E))
	{
		// First, if we're in edit mode, we save the tiles
		if (editMode)
		{
			std::cout << "Exiting edit mode. Saving tiles...\n";
			tileManager.saveTiles(tileManager.getTiles(), tileManager.getFilePath());
		}
		// Then toggle the edit mode
		editMode = !editMode;
		input->setKeyUp(sf::Keyboard::E); // Acknowledge the key press
	}

	if (editMode)
	{
		// Handle moving the view or other edit-mode-specific logic
		moveView(dt);
		//tileManager.handleInput(dt); // tileManager might have its own logic for when editing is true
	}
	else
	{


		p1.handleInput(dt);
		for (int i = 0; i < 4; i++)
		{
			bg[i].handleInput(dt);
			bg1[i].handleInput(dt);
			bg2[i].handleInput(dt);
			bg3[i].handleInput(dt);
		}
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);

	//for(int i=0;i<6;i++)
	/*
	if(c[i].CollisionWithTag("Player")
	{
		p1.AddCollectable();
		c[i].setAlive(false);
		world->RemoveGameObject(c[i]);
	}
	*/
	CollectableText.setString(" Crystal Hearts: " + std::to_string(p1.getCollectableCount()) + " Collected");

	if (p1.CollisionWithTag("Collectable")) {
		//std::cout << "Collision with Collectable\n";
		p1.AddCollectable();
		c1.setAlive(false);
		world->RemoveGameObject(c1);
	
	}

	if (p1.CollisionWithTag("Enemy"))
	{
		if (p1.getCollisionDirection() == "Down")
		{
			std::cout << "Collision with enemy\n";
			world->RemoveGameObject(e1);
			e1.setAlive(false);
		}

		p1.ReduceHealth(0.1*dt);
		std::cout << p1.getHealth() << std::endl;

	}
	if (p1.getHealth() <= 0)
	{
		p1.setAlive(false);
		world->RemoveGameObject(p1); 
		//gameState->setCurrentState(State::MENU);
	}

	if (e1.CollisionWithTag("Wall"))
	{
		std::cout << "Collision with wall\n";
		e1.setVelocity(-e1.getVelocity().x, e1.getVelocity().y);
	}

	if (editMode)
	{
		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Editing mode\nLeft Mouse Button to place tile\nPress B to set collider as a wall (allows bouncing) \nPress E to exit and Save");
		tileManager.handleInput(dt);
		tileManager.update(dt);
	}
	else
	{
		

		// Lock camera y-axis position
		sf::View view = window->getView();
		view.setCenter(view.getCenter().x, 540);

		// Follow player on the x-axis
		sf::Vector2f playerPosition = p1.getPosition();
		float newX = std::max(playerPosition.x, view.getSize().x / 2.0f); // Ensure left side doesn't go past x = 0
		view.setCenter(newX, view.getCenter().y);

		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Press E to edit tiles");

		window->setView(view);
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


	window->draw(CollectableText);
	window->draw(TileEditorText);


	if (c1.isAlive())
	{
		window->draw(c1);
		window->draw(c1.getDebugCollisionBox());
	}

	if (p1.isAlive())
	{
		window->draw(p1);
		window->draw(p1.getDebugCollisionBox());
	}

	if (e1.isAlive())
	{
		window->draw(e1);
		window->draw(e1.getDebugCollisionBox());
	}

	if(editMode) tileManager.render();
	

	endDraw();
}

void Level::moveView(float dt)
{

	// Move the view
	view.setSize(window->getSize().x, window->getSize().y);	

	//Printing the view size
	//std::cout << "View size: " << view.getSize().x << " " << view.getSize().y << std::endl;
	float MovementSpeed = 500.0f;
	if (input->isKeyDown(sf::Keyboard::W))
	{
		view.move(0, -MovementSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		view.move(0, MovementSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-MovementSpeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(MovementSpeed * dt, 0);
	}

	window->setView(view);

}

void Level::adjustViewToWindowSize(unsigned int width, unsigned int height) 
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view.setSize(static_cast<float>(width), static_cast<float>(height));
	view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}
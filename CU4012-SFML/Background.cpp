#include "Background.h"

Background::Background()
{

	view.setSize(1920.f, 1080.f);
	view.setCenter(960.f, 540.f);
	//view.zoom(1.f);
}

Background::~Background()
{
}

void Background::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-200 * dt, 0);
		
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(200 * dt, 0);
	}

	window->setView(view);

}

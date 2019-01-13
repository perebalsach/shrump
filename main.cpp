#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;

int main()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width * .8;
	resolution.y = VideoMode::getDesktopMode().height * .8;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Shrump", Style::Default);
	
	// Enable vertical sync. (vsync)
	// window.setVerticalSyncEnabled(true);
	// When a key is pressed, sf::Event::KeyPressed will be true only once
	// window.setKeyRepeatEnabled(true);

	Player player;

	while (window.isOpen())
	{
		
		Clock clock;
		Time globalTime;

		Event event;
		// Handle events
		
		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// ---------- Handle player controls ----------
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveDown();
		}
		else
		{
			player.stopDown();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveUp();
		}
		else
		{
			player.stopUp();
		}

		// Update Frame	//
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();

		player.update(dtAsSeconds);

		// Draw Frame	//
		window.clear();

		window.draw(player.getSprite());

		window.display();
	}

	return 0;
}


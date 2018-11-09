#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Level.h"
#include "Thing.h"

int const gridWidth = 6;
int const gridHeight = 4;

int const tileWidth = 100;
int const tileHeight = 100;

int main()
{
	Thing **grid;
	// Set the boundary grid items to be walls
	for (int i = 1; i <= gridWidth; i++)
		for (int j = 1; j <= gridHeight; j++)
			if (i == 1 || j == 1 || i == gridWidth || j == gridHeight)
				grid[i][j].SetType("wall");

	// Set specific parts of the grid to be items
	grid[1][1].SetType("item");
	grid[4][1].SetType("npc");
	grid[3][3].SetType("door");

	sf::RenderWindow window(sf::VideoMode(gridWidth * tileWidth, gridHeight * tileHeight), "Howdy ho.");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux.png");
	playerTexture.setRepeated(true);
	playerTexture.setSmooth(true);

	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 300.0f);

	Level level(player, grid);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
					printf("%c", event.text.unicode);
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		player.Update(deltaTime);

		window.clear(sf::Color(180,250,255));
		player.Draw(window);
		window.display();
	}

	return 0;
}
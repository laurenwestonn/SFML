#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Level.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Howdy ho.");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux.png");
	playerTexture.setRepeated(true);
	playerTexture.setSmooth(true);

	Level level(0, 300, 0, 300);
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f, level);

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
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Howdy ho.");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux.png");
	//playerTexture.setRepeated(true);
	//playerTexture.setSmooth(true);

	//sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f,512.0f));


	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);

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
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || 
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			player.move(-0.1f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			player.move(0.0f, -0.1f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			player.move(0.1f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			player.move(0.0f, 0.1f);*/

		player.Update(deltaTime);

		window.clear(sf::Color(180,250,255));
		//window.setView(view);
		player.Draw(window);
		window.display();
	}

	return 0;
}
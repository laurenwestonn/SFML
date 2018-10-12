#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Howdy ho.");
	sf::RectangleShape player(sf::Vector2f(50.f,75.f));


	player.setPosition((window.getSize().x / 2) - (player.getSize().x / 2), 
		(window.getSize().y / 2) - (player.getSize().y / 2));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

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
			player.move(0.0f, 0.1f);

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear(sf::Color(180,250,255));
		window.draw(player);
		window.display();
	}

	return 0;
}
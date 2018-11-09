#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player();
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	bool CanMove(sf::Vector2f playerPosition, float pHalfWidth, float pHalfHeight);

	sf::Vector2f GetPosition() { return body.getPosition(); }

private: 
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};


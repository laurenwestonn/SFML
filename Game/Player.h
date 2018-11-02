#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Level.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, Level level);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	bool CanMove(sf::Vector2f playerPosition, float pHalfWidth, float pHalfHeight, Level level);

	sf::Vector2f GetPosition() { return body.getPosition(); }

private: 
	sf::RectangleShape body;
	Animation animation;
	Level level;
	unsigned int row;
	float speed;
	bool faceRight;
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Level.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, Level level);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }

private: 
	sf::RectangleShape body;
	Level level;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};


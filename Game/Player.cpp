#include "Player.h"
#include "Level.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, Level level) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	this->level = level;


	body.setSize(sf::Vector2f(50.f, 75.f));
	body.setPosition(220, 220);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	float halfWidth = body.getSize().x / 2;
	float halfHeight = body.getSize().y / 2;
	sf::Vector2f centre = body.getPosition() + (sf::Vector2f(halfWidth, halfHeight));

	// Make character move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (CanMove(sf::Vector2f(centre.x - (speed * deltaTime), centre.y), halfWidth, halfHeight, level))
			movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (CanMove(sf::Vector2f(centre.x + (speed * deltaTime), centre.y), halfWidth, halfHeight, level))
			movement.x += speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (CanMove(sf::Vector2f(centre.x, centre.y - (speed * deltaTime)), halfWidth, halfHeight, level))
			movement.y -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (CanMove(sf::Vector2f(centre.x, centre.y + (speed * deltaTime)), halfWidth, halfHeight, level))
			movement.y += speed * deltaTime;

	// Set the animation
	if (movement.x == 0.0f) {
		row = 0;
	} else {
		row = 1;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

bool Player::CanMove(sf::Vector2f playerPosition, float pHalfWidth, float pHalfHeight, Level level)
{
	if (playerPosition.x - pHalfWidth >= level.minXBound & playerPosition.x + pHalfWidth <= level.maxXBound
		& playerPosition.y  - pHalfHeight >= level.minYBound & playerPosition.y + pHalfHeight <= level.maxYBound)
		return true;
	else
		return false;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

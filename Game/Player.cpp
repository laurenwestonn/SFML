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
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	// Make character move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (CanMove(sf::Vector2f(body.getPosition().x - (speed * deltaTime), body.getPosition().y), level))
			movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (CanMove(sf::Vector2f(body.getPosition().x + (speed * deltaTime), body.getPosition().y), level))
			movement.x += speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (CanMove(sf::Vector2f(body.getPosition().x, body.getPosition().y - (speed * deltaTime)), level))
			movement.y -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (CanMove(sf::Vector2f(body.getPosition().x, body.getPosition().y + (speed * deltaTime)), level))
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

bool Player::CanMove(sf::Vector2f playerPosition, Level level)
{
	if (playerPosition.x >= level.minXBound & playerPosition.x <= level.maxXBound
		& playerPosition.y >= level.minYBound & playerPosition.y <= level.maxYBound)
		return true;
	else
		return false;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

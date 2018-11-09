#pragma once
#include <SFML/Graphics.hpp>
class Thing
{
public:
	Thing();
	Thing(sf::String type);
	bool SetType(sf::String type);
	~Thing();


private:
	sf::String type;
	bool interactable;
	bool blockable;
};


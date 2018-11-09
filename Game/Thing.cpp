#include "Thing.h"

enum ThingType
{
	item,
	door,
	wall,
	npc
};

Thing::Thing()
{
}

Thing::Thing(sf::String type)
{
	this->type = type;

	// You can walk over objects, but not doors, walls and npcs.
	this->blockable = !(type == "item");
	// You can interact with objects and npcs, but not doors and walls 
	this->interactable = ((type == "item") || (type == "npc"));
}

bool Thing::SetType(sf::String type)
{
	this->type = type;
	return true;
}

Thing::~Thing()
{
}

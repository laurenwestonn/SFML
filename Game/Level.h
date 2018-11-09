#pragma once
#include "Player.h"
#include "Thing.h"

class Level
{
public:
	Level(Player player, Thing **grid);

private:
	Player player;
	Thing **grid;

	/*
	Who gets this?
	int const gridWidth;
	int const gridHeight;

	int const tileWidth;
	int const tileHeight;*/
};


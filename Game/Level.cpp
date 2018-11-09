#include "Level.h"

Level::Level(Player player, Thing** grid)
{
	this->player = player;
	//strcpy(this->grid, grid);
	this->grid = grid;
}

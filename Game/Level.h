#pragma once
class Level
{
public:
	Level(float minXBound = 0, float maxXBound = 0, float minYBound = 0, float maxYBound = 0);

	float minXBound, maxXBound, minYBound, maxYBound;
};


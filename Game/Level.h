#pragma once
class Level
{
public:
	Level(float minXBound, float maxXBound, float minYBound, float maxYBound);
	~Level();

	float minXBound, maxXBound, minYBound, maxYBound;
};


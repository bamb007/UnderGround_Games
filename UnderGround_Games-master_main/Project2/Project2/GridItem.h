#pragma once
class GridItem
{
public:
	GridItem();
	GridItem(float x, float y, int type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}

	~GridItem();
	
	float x;
	float y;

	int type;
};
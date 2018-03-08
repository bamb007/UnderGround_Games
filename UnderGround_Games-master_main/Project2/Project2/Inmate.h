#pragma once
#include <string>
#include "Enemy.h"

class Inmate
{
public:
	string name;
	int strength;
	int health;
	int intel;
	Inmate(string name, int strength, int health, int intel);
	~Inmate();
};


#include "Inmate.h"



Inmate::Inmate(string name, int strength, int health, int intel)
{
	this->name = name;
	this->strength = strength;
	this->health = health;
	this->intel = intel;
}

Inmate::~Inmate()
{
}

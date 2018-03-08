#include "stdafx.h"
#include "Item.h"


Item::Item(string name, int amount)
{
	this->name = name;
	this->amount = amount;
}

Item::~Item()
{
}

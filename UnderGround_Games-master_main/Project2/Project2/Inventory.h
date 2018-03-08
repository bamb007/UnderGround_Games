#pragma once

#include "IncludeFunctions.h"
#include "Item.h"

class Inventory
{
private:
	int lastRandomNumber;
	int inventoryNumber;
	int randomNumber;
	bool addItemToInventory;
	bool showText;
	bool itemNotFound;
	string name;
	vector<Item>inventory;
	vector<Item>::iterator iter;
	string itemList[23] = {
		"Knife",
		"Toothbrush",
		"Sharp toothbrush",
		"Glass",
		"Sharp glass",
		"Water 40cl",
		"Water 1L",
		"Apple",
		"Bullet",
		"Gunpowder",
		"Metalpipe",
		"Short metalpipe",
		"Gaffa",
		"Rope 1M",
		"Pistol",
		"Nail",
		"Cellkey",
		"Bedshed",
		"Bedshed rope",
		"Plastic piece",
		"Plastic spork",
		"Plastic wrap",
		"Metal spring"
	};
public:


	Inventory(string name);
	~Inventory();

	void Replace(string replace, int amountToRemove, string keep, int amountToAdd, bool showText);
	void Display();
	void ClearInventory();
	void ClearSreen();
	void Add(Item, bool showText);
	void Remove(string remove, int amountToRemove, bool showText);
	void RandomSpawnItem(int amountToSpawn);
};


#include "stdafx.h"
#include "Inventory.h"

#include "Item.h"

Inventory::Inventory(string name)
{
	this->name = name;
}


Inventory::~Inventory()
{
}

void Inventory::ClearSreen()
{
	system("CLS");
}

void Inventory::Add(Item item, bool showText)
{
	ClearSreen();
	addItemToInventory = true;

	cout << "----<" << name << ">----" << "\n\n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		if (iter->name == item.name)
		{
			if (showText == true)
			{
				cout << item.amount << " " << item.name << " was added" << endl;
			}

			iter->amount += item.amount;
			addItemToInventory = false;
		}
	}

	if (addItemToInventory == true)
	{
		if (showText == true)
		{
			cout << item.amount << " " << item.name << " was added" << endl;
		}

		inventory.push_back(item);
		addItemToInventory = false;
	}
	if (showText == true)
	{
		cin.get();
	}

}


void Inventory::Remove(string remove, int amountToRemove, bool showText)
{
	ClearSreen();
	itemNotFound = true;
	cout << "----<" << name << ">----" << "\n\n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		if (iter->name == remove && iter->amount == amountToRemove)
		{
			if (showText == true)
			{
				cout << remove << " was removed from inventory" << endl;
			}
			itemNotFound = false;
			inventory.erase(iter);
			break;
		}
		else if (iter->name == remove && iter->amount > amountToRemove)
		{
			if (showText == true)
			{
				cout << amountToRemove << " " << remove << " was removed" << endl;
			}
			itemNotFound = false;
			iter->amount -= amountToRemove;
			break;
		}

	}
	if (showText == true && itemNotFound == true)
	{
		cout << "The item you tried to remove was not found or the remove amout was to high" << endl;
	}
	if (showText == true)
	{
		cin.get();
	}

}

void Inventory::RandomSpawnItem(int amountToSpawn)
{

	for (amountToSpawn > 0; amountToSpawn--;)
	{

		randomNumber = rand() % 23;
		srand(time(NULL));
		while (lastRandomNumber == randomNumber)
		{
			srand(time(NULL));
			randomNumber = rand() % 23;
		}
		lastRandomNumber = randomNumber;
		Add(Item(itemList[randomNumber], 1), false);
	}
}

void Inventory::Replace(string replace, int amountToRemove, string keep, int amountToAdd, bool showText)
{
	ClearSreen();
	itemNotFound = true;
	addItemToInventory = false;

	//Text before replace
	cout << "----<" << name << ">----" << "\n\n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{

		if (iter->name == replace && iter->amount == amountToRemove)
		{
			if (showText == true)
			{
				cout << replace << " was replaced with " << keep << endl;
			}
			itemNotFound = false;
			Remove(replace, amountToRemove, true);
			addItemToInventory = true;
			break;
		}
		else if (iter->name == replace && iter->amount > amountToRemove)
		{
			if (showText == true)
			{
				cout << amountToRemove << " " << replace << " was replaced with " << amountToAdd << " " << keep << endl;
			}
			itemNotFound = false;
			iter->amount -= amountToRemove;
			addItemToInventory = true;
			break;

		}
	}
	if (showText == true && itemNotFound == true)
	{
		cout << "The item you tried to replace was not found or the replace amout was to high" << endl;
	}
	if (showText == true)
	{
		cin.get();
	}

	if (addItemToInventory == true)
	{
		Add(Item(keep, amountToAdd), false);
		addItemToInventory = false;
	}

}

void Inventory::Display()
{

	ClearSreen();
	cout << "----<" << name << ">----" << "\n\n";
	inventoryNumber = 1;

	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		cout << inventoryNumber << ". " << iter->name << " / Amount: " << iter->amount << endl;
		inventoryNumber += 1;
	}
	//cin.get();
}

void Inventory::ClearInventory()
{
	inventory.clear();
}


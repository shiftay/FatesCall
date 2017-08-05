// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Inventory.h"

Inventory::Inventory()
{
	amountOfBombs = 0;
	amountOfKeys = 0;
	amountOfHealthP = 0;

	maxSpace = 6;
}

Inventory::~Inventory()
{
//	amountOfBombs = NULL;
//	amountOfKeys = NULL;
//	amountOfHealthP = NULL;
//	amountOfManaP = NULL;
//
//	maxSpace = NULL;
}

// Determines whether the inventory is full or not
bool Inventory::isFull()
{
	// amountoOfHealthP and amountOfManap will be the one to use the maxSpace
	if ( (amountOfHealthP + amountOfBombs) >= maxSpace )
	{ 
		return true;
	}

	return false;
}

void Inventory::Reset()
{
	amountOfBombs = 0;
	amountOfKeys = 0;
	amountOfHealthP = 0;

	maxSpace = 6;
}
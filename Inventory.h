// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-10-04
// Version: 1.0.2
#pragma once

//
//	Inventory holder
//
class Inventory
{
private:
	int amountOfBombs;
	int amountOfKeys;
	int amountOfHealthP;

	int maxSpace;

public:
	Inventory();
	~Inventory();

	// Determines whether the inventory is full or not
	bool isFull();

	// Accessors and Mutators
	inline int GetBombs() const					{ return amountOfBombs; }
	inline int GetKeys() const					{ return amountOfKeys; }
	inline int GetHPot() const					{ return amountOfHealthP; }

	inline int GetMaxSpace() const				{ return maxSpace; }

	inline void UpdateBomb(const int newVal)	{ amountOfBombs += newVal; }
	inline void UpdateKeys(const int newVal)	{ amountOfKeys += newVal; }
	inline void UpdateHPot(const int newVal)	{ amountOfHealthP += newVal; }
	inline void SetMaxSpace(const int newVal)	{ maxSpace += newVal; }

	void Reset();
};

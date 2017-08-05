// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#pragma once

#include "Texture.h"
//	Enum to hold the itemType for collision
//	and use
enum ItemType
{
	BOMB,
	GOLD,
	HEALTH_POTION,
	FOOD, 
	KEY
};

//
//	Virtual Class for all the items in the game
//
class Item
{
protected:
	Texture texture;
	int type;
	int goldValue;
	bool isPickedUp;

public:
	Item(){}
	Texture GetTexture() { return texture; }
	void SetPickedUp(bool newVal) { isPickedUp = newVal; }
	bool IsPickedUp() { return isPickedUp;  }
	int GetGold() {return goldValue;}
	int GetType() {return type;}

	virtual int ItemUse() = 0;
};
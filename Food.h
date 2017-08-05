// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#pragma once

#include "Item.h"
//
//	Food, instant health restore
//
class Food : public Item
{
private:
	int heal;

public:
	Food(SDL_Renderer* r, Point);

	virtual int ItemUse();
};
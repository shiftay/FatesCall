// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#pragma once

#include "Item.h"
//
//	Bombs?
//
class Bomb : public Item
{
private:
	int dmg;

public:
	Bomb(SDL_Renderer* r, Point);

	virtual int ItemUse();
};
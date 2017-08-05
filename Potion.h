// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#pragma once

#include "Item.h"

class Potion : public Item
{
private:
	int heal;

public:
	Potion();
	Potion(SDL_Renderer*, Point);

	virtual int ItemUse();
};
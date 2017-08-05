// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
//
// Last Update: 1/10/2016
// Version: 1.0.1
#pragma once
#include "Item.h"
//
//	Gold for buying keys
//
class Gold : public Item
{
private:
	int amount;

public:
	Gold(SDL_Renderer* r, int, Point);
	virtual int ItemUse() { return amount; }

};
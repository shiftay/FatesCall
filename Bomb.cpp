// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Bomb.h"

//Sets the type to BOMB
//		   dmg to 4
//		   goldValue to 20;
//Assigns texture to bomb
Bomb::Bomb(SDL_Renderer* r, Point spawnArea)
{
	texture.LoadTexture(r, "resources\\Items\\bomb.png");
	texture.Collider().position = spawnArea;
	type = BOMB;
	dmg = 4;
	goldValue = 20;
	isPickedUp = false;
}

//Notifies that the item has been used by returning dmg
int Bomb::ItemUse()
{
	return dmg;
}
// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-10-05
// Version: 1.0.2
// SHR ADDED IMAGES
#include "Food.h"

//Sets the type to FOOD
//		   heal to 1 | 0.5 Heart
Food::Food(SDL_Renderer* r, Point spawn)
{
	texture.LoadTexture(r,"resources\\Items\\Food.png");
	texture.Collider().position = spawn;
	texture.Collider().width = 32;
	texture.Collider().height = 32;
	type = FOOD;
	heal = 2;
	isPickedUp = false;
}

//Notifies that the item has been used by returning heal
int Food::ItemUse()
{
	return heal;
}
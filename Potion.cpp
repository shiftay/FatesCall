// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Potion.h"

Potion::Potion()
{
}

//'val' is to deterime which type of potion is being assigned.
// 1 = Health Potion
// 2 = Mana   Potion
Potion::Potion(SDL_Renderer* r, Point spawnArea)
{
	//Depending on which type of potion, the heal value is then assigned.
	// Health Potion = 4 | 2 Hearts
	// Mana   Potion = 6 | 3 Mana
	//Assigns texture to potion

	texture.LoadTexture(r, "resources\\HUD\\Potion.png");
	texture.Collider().position = spawnArea;
	type = HEALTH_POTION;
	heal = 4;
	goldValue = 10;
	isPickedUp = false;
}
//Notifies that the item has been used by returning heal
int Potion::ItemUse()
{
	return heal;
}
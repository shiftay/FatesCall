#include "Gold.h"

Gold::Gold(SDL_Renderer* r, int amtofGold, Point spawnArea)
{
	type = GOLD;
	isPickedUp = false;
	amount = amtofGold;
	goldValue = amtofGold;

	texture.LoadTexture(r, "resources\\Items\\goldCoin1.png");
	texture.Collider().position = spawnArea;
}
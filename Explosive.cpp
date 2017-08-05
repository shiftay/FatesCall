#include "Explosive.h"


Explosive::Explosive(SDL_Renderer* r, Point spawn, int whoDrop)
{
	type = whoDrop;
	dmg = 4;
	exploded = false;

	texture.LoadTexture(r, "resources/HUD/Bombs.png");
	texture.Collider().height = 32;
	texture.Collider().width = 32;
	texture.Collider().position = spawn;

	explosion.LoadTexture(r, "resources/explosion1.png");
	explosion.Collider().width = 100;
	explosion.Collider().height = 100;
	
	timer.Start();
}

void Explosive::Move()
{
	int xHolder, yHolder;

	xHolder = texture.Collider().position.x;
	yHolder = texture.Collider().position.y;
	texture = explosion;
	texture.Collider().position.x = xHolder;
	texture.Collider().position.y = yHolder;
	exploded = true;
}
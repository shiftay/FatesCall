#include "Dragon.h"

bool Dragon::phase2 = false;
int Dragon::counter = 0;

Dragon::Dragon()
{
	
}

Dragon::~Dragon()
{
	// Nothing inside
}

Dragon::Dragon(SDL_Renderer* r)
{
	size = BOSS_NME;
	dmg = HEART_THREE;
	type = 2;
	name = "Dragon";
	handspd = 5;

	canBeDamaged = true;
	health.Set(15,15);
	leftGoingDown = true;
	rightGoingDown = true;
	leftCanMove = false;
	rightCanMove = false;
	isFlying = false;
	
	texture.LoadTexture(r, "resources\\dolan.png");
	texture.Collider().width = 300;
	texture.Collider().height = 300;
	texture.Collider().position.x = 350;
	texture.Collider().position.y = 295;
}


void Dragon::AIMove()
{
	if (phase2timer.getTicks() > 20000 && phase2)
	{
		phase2 = false;
		phase2timer.Stop();
		isFlying = false;
		Show();
		counter++;
	}

	if (health.Current() <= health.Max() / 2 && !phase2 && counter == 0)
	{
		phase2 = true;
		phase2timer.Start();
		Hide();
		isFlying = true;
		counter++;
	}
}

void Dragon::Hide()
{
	texture.Collider().position.y += 2000;
}

void Dragon::Show()
{
	texture.Collider().position.y -= 2000;
}

void Dragon::HandleCollision(int collided, int damaged)
{
	if (!canBeDamaged && timer.getTicks() > 1000)
	{
		canBeDamaged = true;
	}

	switch (collided)
	{
	case PLAYER:
		// take damage
		// check dead
		//		if dead, determine drop
		//		instantiate drop
		//		delete this instance
		// if not dead
		// immunity frames / cc
		if (canBeDamaged)
		{
			health -= dmg;
		}
		if (IsAlive())
		{
			timer.Start();
			canBeDamaged = false;
		}
		else
		{
			isActive = false;
		}
		break;
	}
}



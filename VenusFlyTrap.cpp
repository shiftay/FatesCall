// Author: Jeffherson Vega	
// Email:jeffhersonlim@gmail.com
//
// Last Update: 6/10/2016
// Version: 1.0.2


#include "VenusFlyTrap.h"
#include "Player.h"
#include <iostream>

using std::cout;

VenusFlyTrap::VenusFlyTrap()
{ 
}

VenusFlyTrap::VenusFlyTrap(SDL_Renderer* r)
{
	type = ENEMY;
	size = BOSS_NME;
	
	isFlying = false;

	speed = 2;
	dmg = HEART_ONE;
	
	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//VenHead.png");
	texture.Collider().height = 120;
	texture.Collider().width = 120;

	texture.Collider().position.x = 450;
	texture.Collider().position.y = 0;
	health.Set(10, 10);
}

void VenusFlyTrap::Draw(SDL_Renderer* r)
{
	
}

VenusFlyTrap::~VenusFlyTrap() {}

void VenusFlyTrap::AIMove()
{	
}

void VenusFlyTrap::Attack()
{
}

void VenusFlyTrap::HandleCollision(int collided, int damage)
{
	if (!canBeDamaged && timer.getTicks() > 2000)
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
			health -= damage;
		}
		if (IsAlive())
		{
			timer.Start();
			canBeDamaged = false;
		}
		else
		{
			cout << "Died!";
			isActive = false;
		}

		break;
	}


}


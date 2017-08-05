#include "Slime.h"
#include <iostream>
using std::cout;


Slime::Slime(SDL_Renderer* r, Point startPos)
{
	type = ENEMY;
	size = SMALL_NME;

	speed = 2;
	dmg = HEART_ONE;
	direction = 1;

	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Slimev1.png");
	texture.Collider().height = 64;
	texture.Collider().width = 64;

	startPointX = startPos.x;
	startPointY = startPos.y;

	texture.Collider().position.x = startPos.x;
	texture.Collider().position.y = startPos.y;
	health.Set(2,2);
}


// Slime moves in a box
void Slime::AIMove()
{

	if(status == STATUS_NEUTRAL)
	{
		// move

		if(direction == 1)
		{
			if (texture.Collider().position.x <= startPointX + 100)
				texture.Collider().position.x += (speed * direction);
			else if (texture.Collider().position.y <= startPointY + 150)
			{
				texture.Collider().position.y += (speed * direction);
			}

			if (texture.Collider().position.y == startPointY + 150)
			{
				direction *= -1;
			}
		}
		else
		{
			if (texture.Collider().position.x >= startPointX)
				texture.Collider().position.x += (speed * direction);
			else if (texture.Collider().position.y >= startPointY)
				texture.Collider().position.y += (speed * direction);

			if (texture.Collider().position.y == startPointY)
			{
				direction *= -1;
			}
		}
	}
	else
	{
		// stunned
	}
}

void Slime::Attack()
{

}

void Slime::HandleCollision(int collided, int damage)
{
	if(!canBeDamaged && timer.getTicks() > 1000)
	{
		canBeDamaged = true;
	}

	switch(collided)
	{
	case PLAYER:
		// take damage
		// check dead
		//		if dead, determine drop
		//		instantiate drop
		//		delete this instance
		// if not dead
		// immunity frames / cc
		if(canBeDamaged)
		{
			health -= damage;
		}
		if(IsAlive())
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
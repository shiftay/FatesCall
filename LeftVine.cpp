#include "LeftVine.h"
#include "Player.h"
#include <iostream>

using std::cout;

LeftVine::LeftVine()
{

}

LeftVine::LeftVine(SDL_Renderer* r)
{
	type = ENEMY;
	size = SMALL_NME;
	isFlying = false;
	speed = 2;
	dmg = HEART_FOUR;

	canBeDamaged = false;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Sideways-L.png");
	texture.Collider().height = 60;
	texture.Collider().width = 800;

	texture.Collider().position.x = -100;
	texture.Collider().position.y = 300;

	health.Set(20, 20);
}

void LeftVine::AIMove()
{
	if (status == STATUS_NEUTRAL)
	{
		int direction = 1;

		if (texture.Collider().position.y >= 0 && texture.Collider().position.y <= 600)
		{
			if (AI() == 2)
			{
				texture.Collider().position.y = texture.Collider().position.y + direction;
			}
			else
			{
				texture.Collider().position.y = texture.Collider().position.y + (direction * -1);
			}

		}
	}
}

void LeftVine::Attack()
{

}

void LeftVine::HandleCollision(int collided, int damage)
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
			isActive = false;
		}

		break;
	}


}
	
int LeftVine::AI()
{
	srand(static_cast<unsigned int>(time(0)));
	int move = (rand() % 2) + 1; // The Max Number for now is 3
	return move;
}


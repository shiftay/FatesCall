#include "RightVine.h"

#include "Player.h"
#include <iostream>

using std::cout;

RightVine::RightVine()
{

}

RightVine::RightVine(SDL_Renderer* r)
{	
	type = ENEMY;
	size = SMALL_NME;

	isFlying = false;

	speed = 2;
	dmg = HEART_FOUR;

	canBeDamaged = false;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Sideways-R.png");
	texture.Collider().height = 60;
	texture.Collider().width = 800;

	texture.Collider().position.x = 300;
	texture.Collider().position.y = 200;

	health.Set(20, 20);
	
}

void RightVine::AIMove()
{
	if (status == STATUS_NEUTRAL)
	{	
		int direction = 1;

		if (texture.Collider().position.y >= 0 && texture.Collider().position.y <= 600)
		{
			if (AI() == 1)
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

void RightVine::Attack()
{

}

void RightVine::HandleCollision(int collided, int damage)
{
	if (!canBeDamaged && timer.getTicks() > 2000)
	{
		canBeDamaged = true;
	}

	switch (collided)
	{
	case PLAYER:
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

int RightVine::AI()
{
	srand(static_cast<unsigned int>(time(0)));
	int move = (rand() % 2) + 1; // The Max Number for now is 3
	return move;
}


#include "Goblin.h"


Goblin::Goblin(SDL_Renderer* r, Point spawn)
{
	type = ENEMY;
	size = SMALL_NME;

	speed = 5;
	dmg = HEART_TWO;
	direction = 1;

	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Goblin.png");
	texture.Collider().height = 64;
	texture.Collider().width = 64;

	texture.Collider().position = spawn;
	health.Set(2,2);
	speedX = -5;
	speedY = -5;
	counter = 0;
}



void Goblin::AIMove()
{
	int startPosX = 350;
	int startPosY = 300;
	bool run = true;


	if(status == STATUS_NEUTRAL)
	{
		// move
		counter++;

		if (counter >= 25) // Condition to make the direction reverse
		{
			speedY = 5;
			speedX = -5;
		}
			
		if (counter >= 50) // Condition to make the direction reverse
		{
			speedY = 5;
			speedX = 5;
		}

		if (counter >= 75)
		{
			speedY = -5;
			speedX = 5;
		}

		if(counter >= 100)
		{
			speedX = -5;
			speedY = -5;
			counter = 0;
		}
		texture.Collider().position.x += speedX;
		texture.Collider().position.y += speedY;
	}
}
			

void Goblin::Attack()
{
}

void Goblin::HandleCollision(int collided, int damage)
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
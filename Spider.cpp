#include "Spider.h"


Spider::Spider(SDL_Renderer* r, Point spawn)
{
	type = ENEMY;
	size = SMALL_NME;

	speed = 5;
	dmg = HEART_TWO;
	direction = 1;

	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Spider.png");
	texture.Collider().height = 64;
	texture.Collider().width = 64;

	texture.Collider().position = spawn;

	middlePoint = spawn;


	health.Set(3,3);


	rotation = 100;
	counter = 0;
	angle = 0;
}



void Spider::AIMove()
{
	int startPosX = 350;
	int startPosY = 300;
	bool run = true;
		

	if(status == STATUS_NEUTRAL)
	{

		if (counter <= 10000)
		{
		//An if statement that loops the movement
			if (counter >= 10000)
				counter = 0;


			if (rotation <= -350)
			{
				rotation = 350;
			}
		// Earth coordinates
			angle += 0.01;
			texture.Collider().position.x = ( middlePoint.x ) + ((rotation)*(cos(angle)));
			texture.Collider().position.y = ( middlePoint.y ) + ((rotation)*(sin(angle)));

			counter++;
		}
	}
}
			

void Spider::Attack()
{
}

void Spider::HandleCollision(int collided, int damage)
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
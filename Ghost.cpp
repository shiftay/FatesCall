#include "Ghost.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;


Ghost::Ghost(SDL_Renderer* r)
{
	type = ENEMY;
	size = SMALL_NME;

	speed = 1;
	dmg = HEART_ONE;
	direction = 1;

	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	texture.LoadTexture(r, "resources//Ghost.png");
	texture.Collider().height = 64;
	texture.Collider().width = 64;

	texture.Collider().position.x = 350;
	texture.Collider().position.y = 300;
	health.Set(2,2);
}



void Ghost::AIMove()
{
	int startPosX = 350;
	int startPosY = 300;
	bool run = true;



	if(status == STATUS_NEUTRAL)
	{
		// move
			speed = 3;
			if (Rng() == 1)
			{
				texture.Collider().position.y += (speed * direction);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}
			}
			if (Rng() == 2)
			{
				texture.Collider().position.x += (speed * direction);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}
			 }
			else if (Rng() == 3)
			{
				texture.Collider().position.y += ((speed * direction) * -1);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}

			}

			else if (Rng() == 4)
			{
					texture.Collider().position.x += ((speed * direction) * -1);
					if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
					{
						speed = 0;
						texture.Collider().position.y = 0;
					}
					else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
					{
						speed = 0;
						texture.Collider().position.x = 0;
					}
			}
			else if (Rng() == 5)
			{
						texture.Collider().position.x += ((speed * direction) * -1);
						texture.Collider().position.y += ((speed * direction) * -1);
						if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
						{
							speed = 0;
							texture.Collider().position.y = 0;
						}
						else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
						{
							speed = 0;
							texture.Collider().position.x = 0;
						}
	        }
			else if (Rng() == 6)
			{
				texture.Collider().position.x += ((speed * direction) * 1);
				texture.Collider().position.y += ((speed * direction) * -1);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}
			}
			else if (Rng() == 7)
			{
				texture.Collider().position.x += ((speed * direction) * -1);
				texture.Collider().position.y += ((speed * direction) * 1);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}
			}
			else if (Rng() == 8)
			{
				texture.Collider().position.x += ((speed * direction) * 1);
				texture.Collider().position.y += ((speed * direction) * 1);
				if (texture.Collider().position.y + (speed * direction) < 0 || texture.Collider().position.y + (speed * direction) > 800 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.y = 0;
				}
				else if (texture.Collider().position.x + (speed * direction) < 0 || texture.Collider().position.x + (speed * direction) > 1000 - texture.Collider().height)
				{
					speed = 0;
					texture.Collider().position.x = 0;
				}
			}
	}
}
			

void Ghost::Attack()
{
}

void Ghost::HandleCollision(int collided, int damage)
{
}

int Ghost::Rng()
{
	srand(static_cast<unsigned int>(time(0)));
	int rng = (rand() % 8) + 1;
	return rng;
}
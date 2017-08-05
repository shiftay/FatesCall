// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Thunderbolt.h"

Thunderbolt::Thunderbolt()
{
	//
}

Thunderbolt::~Thunderbolt()
{
	// No pointers yet but I think there will be so we might need to put something in here...
}

// HLDR -- 2 ENEMY | 1 PLAYER
Thunderbolt::Thunderbolt(SDL_Renderer* r, int hldr)
{	
	// Set values for fireballs
	dmg = 1;
	type = hldr;			
	range = 200;
	speed = 15;
	travel = 0;
	exploded = false;

	// Rendering the fireball
	texture.LoadTexture(r, "resources\\thunderbolt.png");
	texture.Collider().height = 32;
	texture.Collider().width = 32;
	texture.name("Thunderbolt");
	texture.Collider().position.x = -100;
}

// handles the collision
void Thunderbolt::HandleCollision(int collided, int damage)
{
	switch (collided)
	{
	case 1:
		if (type == 2)	 // enemy shot
		Thunderboom();
		break;
	case 2:
		if (type == 1)	// player shot
		Thunderboom();
		cout << "Projectile hit";
		break;
	}
}


// general movement
void Thunderbolt::Move()
{
	// Moving the fireball

	// NEED MORE INFORMATION FOR HITTING WALL
	// up / down
	if(yAxis && !exploded)
	{
		// Added functionality when the thunderbolt hits the sides of the screen it will explode
		if ( texture.Collider().position.y <= 0 || texture.Collider().position.y >= 600 )
		{
			Thunderboom();
		}
		else
		{
			texture.Collider().position.y = texture.Collider().position.y + (speed * direction);
			travel += speed;
		}
	}
	else if (!yAxis && !exploded) // left / right
	{
		// Added functionality when the thunderbolt hits the sides of the screen it will explode
		if ( texture.Collider().position.x <= 0 || texture.Collider().position.x >= 1000 )
		{
			Thunderboom();
		}
		else
		{
			texture.Collider().position.x = texture.Collider().position.x + (speed * direction);
			travel += speed;
		}
	}


	// When the thunderbolt reaches the max range it willl  explode
	if (travel >= range)
	{
		speed = 0;
		Thunderboom();
	}
}

void Thunderbolt::Thunderboom()
{
	if (!timer.isStarted())
	{
		timer.Start();
		cout << "zap";
		exploded = true;
	}
}
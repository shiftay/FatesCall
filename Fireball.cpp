// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Fireball.h"

Fireball::Fireball()
{

}

Fireball::~Fireball()
{
	// No pointers yet but I think there will be so we might need to put something in here...
}

// HLDR -- 2 ENEMY | 1 PLAYER
Fireball::Fireball(SDL_Renderer* r, int hldr)
{	
	// Set values for fireballs
	dmg = 2;
	type = hldr;			
	range = 400;
	speed = 10;
	travel = 0;
	exploded = false;
	// Rendering the fireball
	texture.LoadTexture(r, "resources/fireball.png");
	texture.Collider().height = 32;
	texture.Collider().width = 32;
	texture.name("Fireball");
	aoe.LoadTexture(r, "resources/explosion1.png");
	aoe.Collider().width = 100;
	aoe.Collider().height = 100;

	texture.Collider().position.x = -100;


}

// handles the collision
void Fireball::HandleCollision(int collided, int damage)
{
	switch (collided)
	{
	case 1:
		if (type == 2)	 // enemy shot
			FBAOEffect();
		break;
	case 2:
		if (type == 1)	// player shot
			FBAOEffect();
		cout << "Projectile hit";
		break;
	}
}

// Sets up the AOE
void Fireball::FBAOEffect()
{
	int xHolder, yHolder;

	if( !timer.isStarted() )
	{
		timer.Start();
		// Edited: Transferred so that the explosion wont get updated constantly
		xHolder = texture.Collider().position.x;
		yHolder = texture.Collider().position.y;
		cout << "boom";
		speed = 0;
		texture = aoe;
		exploded = true;
		if(yAxis && direction == -1) // up 
		{
			texture.Collider().position.x = xHolder;
			texture.Collider().position.y = yHolder + 10; 
		}
		else if(yAxis && direction == 1) // down
		{
			texture.Collider().position.x = xHolder;
			texture.Collider().position.y = yHolder - texture.Collider().height/2; 
		}
		else if(!yAxis && direction == 1) // right?
		{
			texture.Collider().position.x = xHolder - texture.Collider().width/2;
			texture.Collider().position.y = yHolder; 
		}
		else if(!yAxis && direction == -1) // left
		{
			texture.Collider().position.x = xHolder + 10;
			texture.Collider().position.y = yHolder; 
		}
	}
}
// general movement
void Fireball::Move()
{
	// Moving the fireball
	// up / down
	if(yAxis && !exploded)
	{
		// Added functionality when the fireball hits the sides of the screen it will explode
		if ( texture.Collider().position.y <= 0 || texture.Collider().position.y >= 600 )
		{
			FBAOEffect();
		}
		else
		{
			texture.Collider().position.y = texture.Collider().position.y + (speed * direction);
			travel += speed;
		}
	}
	else if (!yAxis && !exploded) // left / right
	{
		// Added functionality when the fireball hits the sides of the screen it will explode
		if ( texture.Collider().position.x <= 0 || texture.Collider().position.x >= 1000 )
		{
			FBAOEffect();
		}
		else
		{
			texture.Collider().position.x = texture.Collider().position.x + (speed * direction);
			travel += speed;
		}
	}


	// When the fireball reaches the max range it willl  explode
	if (travel == range)
	{
		speed = 0;
		FBAOEffect();
	}
}

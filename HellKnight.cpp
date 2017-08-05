#include "HellKnight.h"

HellKnight::HellKnight(SDL_Renderer* r)
{
	type = ENEMY;
	size = BOSS_NME;
	speed = 3;
	
	dmg = HEART_THREE;
	isFlying = false;

	isOffensive = true;
	canBeDamaged = true;
	status = STATUS_NEUTRAL;

	firstPhase.LoadTexture(r, "resources//feelsgoodman.png");
	secondPhase.LoadTexture(r, "resources//feelsamazingman.png");
	explodedDude.LoadTexture(r, "resources//New.png");
	texture = secondPhase;
	texture.Collider().height = 64;
	texture.Collider().width = 64;

	health.Set(15, 15);
	amountofChanges = 0;
	exploded = false;
}


void HellKnight::AIMove()
{
	Point hldr;
	// Can see current quadrant the player is in
	if (isOffensive)
	{
		
		if (amountofChanges == 0 && health.Current() < health.Max() / 2)
		{
			isOffensive = false;
			amountofChanges++;
			phaseTimer.Start();
			hldr = texture.Collider().position;
			texture = firstPhase;
			texture.Collider().position = hldr;
			texture.Collider().height = 64;
			texture.Collider().width = 64;
			//change texture
			//start secondphase timer
		}

		if (amountofChanges == 1 && health.Current() < health.Max() / 4)
		{
			isOffensive = false;
			amountofChanges++;
			//change texture
			phaseTimer.Start();
			hldr = texture.Collider().position;
			texture = firstPhase;
			texture.Collider().position = hldr;
			texture.Collider().height = 64;
			texture.Collider().width = 64;
			//start secondphase timer
		}

		if (!timer.isStarted())
			timer.Start();

		if (timer.getTicks() > 500 && exploded)
		{
			hldr = texture.Collider().position;
			texture = secondPhase;
			texture.Collider().position = hldr;
			texture.Collider().height = 64;
			texture.Collider().width = 64;
		}


		if (timer.getTicks() > 2000)
		{
			//lunge at player
			if (Player::currentPos == TOPLEFT)
			{
				texture.Collider().position.x = 250;
				texture.Collider().position.y = 150;
				Attack();
			}
			else if (Player::currentPos == TOPRIGHT)
			{
				texture.Collider().position.x = 750;
				texture.Collider().position.y = 150;
				Attack();
			}
			else if (Player::currentPos == BOTTOMLEFT)
			{
				texture.Collider().position.x = 250;
				texture.Collider().position.y = 450;
				Attack();
			}
			else if (Player::currentPos == BOTTOMRIGHT)
			{
				texture.Collider().position.x = 750;
				texture.Collider().position.y = 450;
				Attack();
			}
			Attack();
			//stop timer
			timer.Stop();
		}


	}
	else
	{



		if (phaseTimer.getTicks() > 25000)
		{
			isOffensive = true;
			isFlying = false;
			phaseTimer.Stop();
			//change texture
		}

		if (!timer.isStarted())
			timer.Start();

		if (timer.getTicks() > 1000)
		{
			//dive away
			if (Player::currentPos == TOPLEFT)
			{
				texture.Collider().position.x = 750;
				texture.Collider().position.y = 450;

			}
			else if (Player::currentPos == TOPRIGHT)
			{
				texture.Collider().position.x = 250;
				texture.Collider().position.y = 450;

			}
			else if (Player::currentPos == BOTTOMLEFT)
			{
				texture.Collider().position.x = 750;
				texture.Collider().position.y = 150;

			}
			else if (Player::currentPos == BOTTOMRIGHT)
			{

				texture.Collider().position.x = 250;
				texture.Collider().position.y = 150;

			}
			timer.Stop();
		}


	}
	// lunge towards the player, every 10 calls, just dash away
	// cast an "ATTACK"
	
	// check health to set offensive off.


}

void HellKnight::Attack()
{
	//exploded pepe
	Point hldr;

	hldr = texture.Collider().position;

	texture = explodedDude;
	texture.Collider().position = hldr;
	texture.Collider().height = 128;
	texture.Collider().width = 128;
	exploded = true;

}


void HellKnight::HandleCollision(int collided, int damage)
{
	if (!canBeDamaged && immunity.getTicks() > 1000)
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
		if (canBeDamaged && isOffensive)
		{
			health -= damage;
		}
		else if (canBeDamaged && !isOffensive) // if hit when in defensive heal for the damage
		{
			health += damage;
		}
		if (IsAlive())
		{
			immunity.Start();
			canBeDamaged = false;
		}
		else
		{
			isActive = false;
		}
		break;
	}
}
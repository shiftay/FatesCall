#include "LeftHand.h"

LeftHand::LeftHand(SDL_Renderer* r)
{
	isFlying = false;
	canMove = false;
	isgoingDown = false;
	health.Set(15, 15);
	dmg = 2;
	speed = 5;
	type = 2;
	direction = -1;
	size = MEDIUM_NME;

	texture.LoadTexture(r, "resources//lefthand.png");
	texture.Collider().height = 300;
	texture.Collider().width = 300;
	texture.Collider().position.x = 100;
	texture.Collider().position.y = 299;
}

void LeftHand::AIMove()
{
	if (Dragon::counter == 2 && phase2Timer.isStarted())
	{
		Show();
		phase2Timer.Stop();
	}
	if (Dragon::phase2 && !phase2Timer.isStarted())
	{
		Hide();
		phase2Timer.Start();
	}

	if (!Dragon::phase2)
	{
		if (!leftTime.isStarted())
		{
			leftTime.Start();
		}
		if (leftTime.getTicks() > 2000)
		{
			if (Player::currentPos == BOTTOMLEFT || Player::currentPos == TOPLEFT)
			{
				leftTime.Pause();
				canMove = true;
			}
			if (canMove)
				Attack();
		}
	}
	

}

void LeftHand::Hide()
{
	texture.Collider().position.y += 2000;
}

void LeftHand::Show()
{
	texture.Collider().position.y -= 2000;
}

void LeftHand::Attack()
{
	if (texture.Collider().position.y >= 300)
	{
		isgoingDown = true;
		leftTime.Stop();
		leftTime.Start();
		canMove = false;
	}
	else if (texture.Collider().position.y <= 0)
	{
		isgoingDown = false;
	}

	// Movement of left hand
	if (isgoingDown)
	{
		texture.Collider().position.y = texture.Collider().position.y + (speed * direction);
	}
	else
	{
		texture.Collider().position.y = texture.Collider().position.y + speed;
	}
}


void LeftHand::HandleCollision(int collided, int damaged)
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
			health -= dmg;
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
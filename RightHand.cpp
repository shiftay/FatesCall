#include "RightHand.h"

RightHand::RightHand(SDL_Renderer* r)
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

	texture.LoadTexture(r, "resources//righthand.png");
	texture.Collider().height = 300;
	texture.Collider().width = 300;
	texture.Collider().position.x = 600;
	texture.Collider().position.y = 299;
}

void RightHand::AIMove()
{	
	if (!Dragon::phase2)
	{
		if (!rightTime.isStarted())
		{
			rightTime.Start();
		}
		if (rightTime.getTicks() > 2000)
		{
			if (Player::currentPos == BOTTOMRIGHT || Player::currentPos == TOPRIGHT)
			{
				rightTime.Pause();
				canMove = true;
			}
			if (canMove)
				Attack();
		}
	}

	if (Dragon::phase2 && !phase2Timer.isStarted())
	{
		Hide();
		phase2Timer.Start();
	}

	if (Dragon::counter == 2 && phase2Timer.isStarted())
	{
		Show();
		phase2Timer.Stop();
	}

}

void RightHand::Attack()
{
	if (texture.Collider().position.y >= 300)
	{
		isgoingDown = true;
		rightTime.Stop();
		rightTime.Start();
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

void RightHand::Hide()
{
	texture.Collider().position.y += 2000;
}

void RightHand::Show()
{
	texture.Collider().position.y -= 2000;
}

void RightHand::HandleCollision(int collided, int damaged)
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
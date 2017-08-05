#include "Locked.h"

Locked::Locked(SDL_Renderer* r, int area)
{
	currentDoor = NONE;
	exits.push_back(FillSouth(r));


	switch (area)
	{
	case 0:
		backGround.LoadTexture(r, "resources\\Rooms\\CaveTileset.png");
		break;
	case 1:
		backGround.LoadTexture(r, "resources\\Rooms\\Desert.png");
		break;
	case 2:
		backGround.LoadTexture(r, "resources\\Rooms\\Graveyard.png");
		break;
	case 3:
		break;
	}

	BossDoor.LoadTexture(r, "resources\\ClosedDoor.png");
	BossDoor.Collider().height = 50;
	BossDoor.Collider().width = 50;
	BossDoor.Collider().position.x = 475;
	BossDoor.Collider().position.y = 0;
	isLocked = false;
}

void Locked::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
	BossDoor.Draw(r);
	if (!Doors.empty())
	{
		for (int i = 0; i < Doors.size(); i++)
			Doors[i].Draw(r);
	}
}

void Locked::Obstacles(SDL_Renderer* r, Player* p)
{
	if (Player::isInteracting)
	{
		if (p->GetTexture()->Collider().position.x >= 475 && p->GetTexture()->Collider().position.x <= 525)
		{
			if (p->GetTexture()->Collider().position.y >= 0 && p->GetTexture()->Collider().position.y <= 50)
			{
				if (p->GetInventory().GetKeys() > 0)
				{
					p->GetInventory().UpdateKeys(-1);
					exits.push_back(FillNorth(r));
					Player::isInteracting = false;
				}
			}
		}
	}
}
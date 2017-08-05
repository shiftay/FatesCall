#include "Boss.h"

Boss::Boss(SDL_Renderer* r, BossType currentRoom, int area)
{
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

	}
	switch (currentRoom)
	{
	case HELLKNIGHT:
		activeUnits.push_back(new HellKnight(r));
		break;
	case DRAGON:
		activeUnits.push_back(new Dragon(r));
		activeUnits.push_back(new LeftHand(r));
		activeUnits.push_back(new RightHand(r));
		break;
	case FLYTRAP:
		activeUnits.push_back(new VenusFlyTrap(r));
		activeUnits.push_back(new LeftVine(r));
		activeUnits.push_back(new RightVine(r));
		break;
	}

	currentDoor = NONE;
}

void Boss::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);

	if (!activeUnits.empty())
	{
		if (activeUnits[0]->IsFlying())
		{
			for (int i = 0; i < proj.size(); i++)
				proj[i]->GetTexture()->Draw(r);
		}
	}

	int tally = 0;

	if(!proj.empty())
	{
		for(int i = 0; i < proj.size(); i++)
		{
			if(proj[i]->IsExploded())
			{
				tally++;
			}
		}
	}

	if(tally == proj.size())
	{
		for(int i = 0; i < proj.size(); i++)
		{
				delete proj[i];
				proj[i]= nullptr;
				proj.erase(proj.begin() + i);
		}
	}
	//GameStateManager::setCurrentState(HI);
}


void Boss::Obstacles(SDL_Renderer* r, Player* p)
{
	if (!activeUnits.empty())
	{
		if (activeUnits[0]->IsFlying())
		{
				if (proj.empty())
				{
					FillProj(r, p->NMESpawns(), 1);
				}
				Explode();
			
		}
	}	
}

void Boss::Explode()
{ 	
	if (!timer.isStarted())
	{
		timer.Start();
	}
	for(int i = 0; i < proj.size(); i++)
    {
		
		if (timer.getTicks() > 2000)
		{
			if(!proj[i]->IsExploded())
					proj[i]->Move();
		}
    }
}

void Boss::FillProj(SDL_Renderer* r, vector<Point> potentialSpawns, int x)
{
    for(int i = 0; i < x; i++)
    {
        proj.push_back(new Explosive(r, potentialSpawns[Player::DiceRoll(0,14)], 2));
    }
}
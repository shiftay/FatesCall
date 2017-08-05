// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 10/2/2016
// Version: 1.0.1
#include "Puzzle.h"

Puzzle::Puzzle(SDL_Renderer* r, int area)
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
	case 3:
		break;
	}

	//Creating the Projectiles as ENEMY for collision detection
	for (int i = 0; i < 25; i++)
	{
		proj.push_back(new Fireball(r, 2));
	}

	backGround.Collider().width = 1000;
	backGround.Collider().height = 600;

	SetSpawn();

	currentDoor = NONE;
	FillExits(r);

}

void Puzzle::SetSpawn()
{
		#pragma region SpawnPoints of Projectiles
		//NORTH WALL
		proj[0]->GetTexture()->Collider().position.x = 100;
		proj[0]->GetTexture()->Collider().position.y = 100;

		proj[1]->GetTexture()->Collider().position.x = 200;
		proj[1]->GetTexture()->Collider().position.y = 100;

		proj[2]->GetTexture()->Collider().position.x = 300;
		proj[2]->GetTexture()->Collider().position.y = 100;

		proj[3]->GetTexture()->Collider().position.x = 400;
		proj[3]->GetTexture()->Collider().position.y = 100;

		proj[4]->GetTexture()->Collider().position.x = 500;
		proj[4]->GetTexture()->Collider().position.y = 100;

		proj[5]->GetTexture()->Collider().position.x = 600;
		proj[5]->GetTexture()->Collider().position.y = 100;

		proj[6]->GetTexture()->Collider().position.x = 700;
		proj[6]->GetTexture()->Collider().position.y = 100;

		proj[7]->GetTexture()->Collider().position.x = 800;
		proj[7]->GetTexture()->Collider().position.y = 100;

		//SOUTH WALL
		proj[8]->GetTexture()->Collider().position.x = 100;
		proj[8]->GetTexture()->Collider().position.y = 400;

		proj[9]->GetTexture()->Collider().position.x = 200;
		proj[9]->GetTexture()->Collider().position.y = 400;

		proj[10]->GetTexture()->Collider().position.x = 300;
		proj[10]->GetTexture()->Collider().position.y = 400;

		proj[11]->GetTexture()->Collider().position.x = 400;
		proj[11]->GetTexture()->Collider().position.y = 400;

		proj[12]->GetTexture()->Collider().position.x = 500;
		proj[12]->GetTexture()->Collider().position.y = 400;

		proj[13]->GetTexture()->Collider().position.x = 600;
		proj[13]->GetTexture()->Collider().position.y = 400;

		proj[14]->GetTexture()->Collider().position.x = 700;
		proj[14]->GetTexture()->Collider().position.y = 400;

		proj[15]->GetTexture()->Collider().position.x = 800;
		proj[15]->GetTexture()->Collider().position.y = 400;

		//WEST WALL
		proj[16]->GetTexture()->Collider().position.x = 100;
		proj[16]->GetTexture()->Collider().position.y = 150;

		proj[17]->GetTexture()->Collider().position.x = 100;
		proj[17]->GetTexture()->Collider().position.y = 200;

		proj[18]->GetTexture()->Collider().position.x = 100;
		proj[18]->GetTexture()->Collider().position.y = 250;

		proj[19]->GetTexture()->Collider().position.x = 100;
		proj[19]->GetTexture()->Collider().position.y = 300;

		proj[20]->GetTexture()->Collider().position.x = 100;
		proj[20]->GetTexture()->Collider().position.y = 350;

		//EAST WALL
		proj[21]->GetTexture()->Collider().position.x = 800;
		proj[21]->GetTexture()->Collider().position.y = 150;

		proj[22]->GetTexture()->Collider().position.x = 800;
		proj[22]->GetTexture()->Collider().position.y = 200;

		proj[23]->GetTexture()->Collider().position.x = 800;
		proj[23]->GetTexture()->Collider().position.y = 250;

		proj[24]->GetTexture()->Collider().position.x = 800;
		proj[24]->GetTexture()->Collider().position.y = 300;

		/*proj[25]->GetTexture()->Collider().position.x = 800;
		proj[25]->GetTexture()->Collider().position.y = 350;*/
		#pragma endregion
	#pragma region Setting Speed and Direction of Projectiles
		//Setting speed of all Projectiles to 3
		for (int i = 0; i < 25; i++)
		{
			proj[i]->SetSpeed(3);
			proj[i]->SetDmg(1);
		}

		//Setting direction of NORTH WALL Projectiles -- FIRES TOP TO BOTTOM
		for (int i = 0; i < 8; i++)
		{
			proj[i]->SetAxis(true);
			proj[i]->SetDirection(1);
		}

		//Setting direction of SOUTH WALL Projectiles -- FIRES BOTTOM TO TOP
		for (int i = 8; i <= 15; i++)
		{
			proj[i]->SetAxis(true);
			proj[i]->SetDirection(-1);
		}

		//Setting direction of WEST WALL Projectiles -- FIRES LEFT TO RIGHT
		for (int i = 16; i <= 20; i++)
		{
			proj[i]->SetAxis(false);
			proj[i]->SetDirection(-1);
		}
		//Setting direction of EAST WALL Projectiles -- FIRES RIGHT TO LEFT
		for (int i = 21; i < 25; i++)
		{
			proj[i]->SetAxis(false);
			proj[i]->SetDirection(1);
		}
		#pragma endregion
}


void Puzzle::Refill(SDL_Renderer* r)
{
	for (int i = 0; i < 25; i++)
	{
		proj.push_back(new Fireball(r, 2));
	}
	SetSpawn();
}

void Puzzle::Obstacles(SDL_Renderer* r, Player* p)
{
	if(proj.empty())
		Refill(r);

	for(int i = 0; i < proj.size(); i++)
	{
		if(proj[i]->GetTravel() > 0 && proj[i]->IsExploded())
		{
			delete proj[i];
			proj[i] = nullptr;
			proj.erase(proj.begin() + i);
		}
	}

	#pragma region Moving the Projectiles
	for (int i = 0; i < proj.size(); i++)
	{
		proj[i]->Move();
	}
	#pragma endregion

}

void Puzzle::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
	for(int i = 0; i < proj.size(); i++)
	{
		proj[i]->GetTexture()->Draw(r);
	}
	if (!Doors.empty())
	{
		for (int i = 0; i < Doors.size(); i++)
			Doors[i].Draw(r);
	}
}
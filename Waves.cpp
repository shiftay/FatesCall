// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 10/4/2016
// Version: 1.0.1
#include "Waves.h"

Waves::Waves(SDL_Renderer* r, int area, vector<Point> spawnPoints)
{
	//Set the rooms background image
	counter = 0;

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

	//Stretch the background
	backGround.Collider().width = 1000;
	backGround.Collider().height = 600;

	//Roll the number of enemies for individual waves
	waveEnemies = Player::DiceRoll(2,5);

	//Initialize bools to false
	waveOneCompleted = false;
	waveTwoCompleted = false;

	//Spawn the enemies
	SpawnEnemies(r, spawnPoints);

	//Set doors to none -- locked
	currentDoor = NONE;
}

//used to spawn enemies
void Waves::SpawnEnemies(SDL_Renderer* r, vector<Point> spawnP)
{

		vector<Point> spawnPoints;

		for (int x =0 ; x < waveEnemies; x++)
		{
			spawnPoints.push_back(spawnP[Player::DiceRoll(0,14)]);
		}

		for(int j = 0; j < waveEnemies; j++)
		{
			int nmeType = Player::DiceRoll(1,3);

			switch(nmeType)
			{
			default:
				activeUnits.push_back(new Slime(r,spawnPoints[j]));
				break;
			}
		}
}


// check logic for the room
void Waves::Obstacles(SDL_Renderer* r, Player* p)
{
	if(!waveOneCompleted)
	{
		if(activeUnits.empty())
		{
			waveOneCompleted = true;
			SpawnEnemies(r, p->NMESpawns());
		}
	}
	
	if(!waveTwoCompleted && waveOneCompleted)
	{
		if(activeUnits.empty())
		{
			waveTwoCompleted = true;
			
		}
	}

	if(waveOneCompleted && waveTwoCompleted)
	{
		if(counter == 0)
		{		
			FillExits(r);//Allow access to doors
			counter++;
		}
	}
}

void Waves::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
	if (!Doors.empty())
	{
		for (int i = 0; i < Doors.size(); i++)
			Doors[i].Draw(r);
	}
}
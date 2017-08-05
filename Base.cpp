#include "Base.h"

Base::Base(SDL_Renderer* r, int area, vector<Point> potentialSpawns)
{
	currentDoor = NONE;
	int amountofNME = Player::DiceRoll(1, 5);
	vector<Point> spawnPoints;
	// Switch based off of AREA
	switch(area)
	{
	case 0:
		backGround.LoadTexture(r, "resources\\Rooms\\CaveTileset.png");
		for (int x = 0; x < amountofNME; x++)
		{
			spawnPoints.push_back(potentialSpawns[Player::DiceRoll(0, 14)]);
		}
		for (int j = 0; j < amountofNME; j++)
		{
			int nmeType = Player::DiceRoll(1, 3);
			switch (nmeType)
			{
			case 1:
				activeUnits.push_back(new Ghost(r)); // ghost
				break;
			case 2:
				activeUnits.push_back(new Slime(r, spawnPoints[j])); // slime
				break;
			case 3:
				activeUnits.push_back(new Skeleton(r, spawnPoints[j])); // skeleton
				break;
			}
		}
		break;
	case 1:
		backGround.LoadTexture(r, "resources\\Rooms\\Desert.png");
		for (int x = 0; x < amountofNME; x++)
		{
			spawnPoints.push_back(potentialSpawns[Player::DiceRoll(0, 14)]);
		}
		for (int j = 0; j < amountofNME; j++)
		{
			int nmeType = Player::DiceRoll(1, 3);
			switch (nmeType)
			{
			case 1:
				activeUnits.push_back(new Ghost(r)); // ghost
				break;
			case 2:
				activeUnits.push_back(new Spider(r, spawnPoints[j])); // spider
				break;
			case 3:
				activeUnits.push_back(new Goblin(r, spawnPoints[j])); // goblin
				break;
			}
		}
		break;
	case 2:
		backGround.LoadTexture(r, "resources\\Rooms\\Graveyard.png");
		for (int x = 0; x < amountofNME; x++)
		{
			spawnPoints.push_back(potentialSpawns[Player::DiceRoll(0, 14)]);
		}
		for (int j = 0; j < amountofNME; j++)
		{
			int nmeType = Player::DiceRoll(1, 3);
			switch (nmeType)
			{
			case 1:
				activeUnits.push_back(new Ghost(r)); // ghost
				break;
			case 2:
				activeUnits.push_back(new Skeleton(r, spawnPoints[j])); // spider
				break;
			case 3:
				activeUnits.push_back(new Goblin(r, spawnPoints[j])); // goblin
				break;
			}
		}

		break;

	}
	
	backGround.Collider().width = 1000;
	backGround.Collider().height = 600;
	
	FillExits(r);

	// enemy spawns.
	// exit locations
	// playerSpawn

}


void Base::SpawnEnemies(vector<Point> potentialSpawns)
{

}


void Base::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
	if (!Doors.empty())
	{
		for (int i = 0; i < Doors.size(); i++)
			Doors[i].Draw(r);
	}
}
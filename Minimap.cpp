// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-28
// Version: 1.0.1
#include "Minimap.h"

Minimap::Minimap()
{
	//Randomizes dungeons every instance
	srand(time(NULL));

	playerLocation.x = 0;
	playerLocation.y = 0;

}

//Create minimap 
//Dim has to be 2 OR 3 OR 4
void Minimap::CreateMap(const int dim)
{
	//Hardcoding one boss and one locked room before boss round
	array_map[0][2] = BOSS;
	array_map[1][2] = LOCKED;

	//Filling the minimap without boss and locked
	//Rooms will be randomized according to ReturnRoom
	//Setting rooms beside locked and boss rooms to EMPTY
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(array_map[i][j] == BOSS || array_map[i][j] == LOCKED)
			{
				continue;
			}
			else if(i == 0 || i == 1)
			{
				array_map[i][j] = EMPTY;
			}
			else
			{
				array_map[i][j] = ReturnRoom(0,5);
			}
		}
	}

	//Loop to make sure there is only one shop room
	for(int i = dim; i < dim + 1; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(array_map[i][j] == PUZZLE || array_map[i][j] == BASE)
			{
				array_map[i][j] = SHOP;
				break;
			}
		}
	}

	
	array_map[2][2] = BASE;


	for (int i = 0; i < 5; i++)
	{
		if (array_map[3][i] == EMPTY)
		{
			array_map[3][i] = BASE;
		}
	}
	
	int test = 0;
	for (int i = 0; i < 5; i++)
	{
		if (array_map[4][i] == EMPTY || array_map[4][i] == PUZZLE)
			test++;
	}
	if (test == 5)
	{
		array_map[4][3] = BASE;
	}

}

//Function which randomizes the rooms to be filled in for the minimap
RoomType Minimap::ReturnRoom(int min, int max)
{
	//Specific = Max has to be 1 and Min has to be the exact value
	int diceroll = rand() % max + min; 

	switch(diceroll)
	{
		case 0:
			return EMPTY;

		case 1:
			return PUZZLE;

		case 2:
			return BASE;
		
		case 3:
			return PUZZLE;

		case 4:
			return BASE;
	}
}

RoomType Minimap::CheckRoom(int x, int y)
{
	if (x > 4 || x < 0)
		return EMPTY;
	else if (y > 4 || y < 0)
		return EMPTY;
	else
		return array_map[x][y];
}


// Draws the minimap to the portion of the HUD
void Minimap::DrawMap(SDL_Renderer* r)
{
	// load in textures
	if (base.texture() == nullptr)
		base.LoadTexture(r, "resources\\HUD\\minimap\\baseRoom.png");
	if (shop.texture() == nullptr)
		shop.LoadTexture(r, "resources\\HUD\\minimap\\shopRoom.png");
	if (empty.texture() == nullptr)
		empty.LoadTexture(r, "resources\\HUD\\minimap\\emptyRoom.png");
	if (locked.texture() == nullptr)
		locked.LoadTexture(r, "resources\\HUD\\minimap\\lockedRoom.png");
	if (boss.texture() == nullptr)
		boss.LoadTexture(r, "resources\\HUD\\minimap\\bossRoom.png");
	if (playerH.texture() == nullptr)
		playerH.LoadTexture(r, "resources\\HUD\\minimap\\MinimapP.png");

	SDL_Rect holder = { 770, 628, 34, 27 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			switch (array_map[i][j])
			{
			case EMPTY:
				empty.Draw(r, &holder);
				break;
			case SHOP:
				shop.Draw(r, &holder);
				break;
			case BOSS:
				boss.Draw(r, &holder);
				break;
			case LOCKED:
				locked.Draw(r, &holder);
				break;
			case BASE:
				base.Draw(r, &holder);
				break;
			case PUZZLE:
				base.Draw(r, &holder);
				break;
			}
			if (i == playerLocation.x && j == playerLocation.y)
			{
				playerH.Draw(r, &holder);
			}

			holder.x += 34;
		}
		holder.x = 770;
		holder.y += 27;
	}
}
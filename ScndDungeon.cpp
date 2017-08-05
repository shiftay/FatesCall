// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#include "ScndDungeon.h"

void ScndDungeon::Init(ScreenUtil* w, Player* p)
{
	cout << "|-->ScndDungeon::Init() Invoked" << endl;
	area = 1;
	isinBossR = false; // tell that not in bossRoom

	// Create Minimap
	Player::testMinimap.CreateMap(2);
	Player::testMinimap.PlayerLocation().x = 4;
	testP = p;

	for (int i = 4; i >= 0; i--)
	{
		if (Player::testMinimap.CheckRoom(4, i) == BASE)
		{
			Player::testMinimap.PlayerLocation().y = i;
			current_room = new Base(w->getRenderer(), area, testP->NMESpawns());
			break;
		}
	}

	testP->GetTexture()->Collider().position = p->GetSpawns()[3];

	loadingScreen.LoadTexture(w->getRenderer(), "resources\\Rooms\\loading.png");

	Point holder = { 450, 350 };
}

void ScndDungeon::Clean()
{
	cout << "|-->ScndDungeon::Clean() Invoked" << endl;

	// clear vectors and everything.

}

//Handles the main menu's button's events
void ScndDungeon::HandleEvents(SDL_Event* event)
{
	//Event Handler
	switch (event->type)
	{
	case SDL_KEYDOWN:
		testP->HandleEvents(event);
		break;
	}

	current_room->HandleEvent(event);
}

//Checks to see if either of the buttons have been clicked
// If so the current game state is changed
void ScndDungeon::Update(ScreenUtil* w)
{
	int count = 0;
	// make sure nothing is active during load screen
	if (!loading.isStarted())
	{
		if (isinBossR)
		{
			for (int i = 0; i < current_room->ActiveUnits().size(); i++)
			{
				if (current_room->ActiveUnits()[i]->Size() != BOSS_NME)
					count++;
			}


			if (count == current_room->ActiveUnits().size() || current_room->ActiveUnits().empty())
			{
				GameStateManager::setCurrentState(GAMESTATE_HELLPROGR);
				return;
			}
		}

		if(!testP->IsAlive())
		{
			GameStateManager::setCurrentState(GAMESTATE_GAMEOVER); // send to "GAME OVER" screen.
			return;
		}


		MoveEnemies(w->getRenderer());

		CheckActiveItems();

		if(Player::isBombPlaced)
		{
			testP->GetProjectiles().push_back(new Explosive(w->getRenderer(), testP->GetTexture()->Collider().position, 1));
			Player::isBombPlaced = false;
		}

	
		testP->PlayerProjectiles(w->getRenderer());
		
		// creating current room breaks from time to time???
		current_room->Obstacles(w->getRenderer(), testP);

		// run collision checks
		testCollision.HandleEvents(current_room->GetProjectiles(),testP->GetProjectiles(), current_room->ActiveUnits(), current_room, ActiveItems, testP);

		if (Player::doorUsed)
		{
			ChangeRoom(w->getRenderer());
		}
	}
	else
	{
		if (loading.getTicks() > 5000)
		{
			loading.Stop();
		}
	}
}

//All draw operations for the main menu state are preformed here. Everything
// drawn within this method is drawn to the Rendering Engine scene_ property
void ScndDungeon::Render(ScreenUtil* w)
{
	// Dont draw this scene while in loadScreen
	if (!loading.isStarted())
	{
		// render current room
		current_room->Draw(w->getRenderer());

		// render Items
		if (!ActiveItems.empty())
		{
			for (int i = 0; i < ActiveItems.size(); i++)
			{
				if (!ActiveItems[i]->IsPickedUp())
				{
					ActiveItems[i]->GetTexture().Draw(w->getRenderer());
				}
			}
		}

		// Render Enemies
		if (!current_room->ActiveUnits().empty())
		{
			for (int i = 0; i < current_room->ActiveUnits().size(); i++)
			{
				if (current_room->ActiveUnits()[i]->IsAlive())
					current_room->ActiveUnits()[i]->GetTexture()->Draw(w->getRenderer());
			}
		}

		testP->GetTexture()->Draw(w->getRenderer());

		if (Player::spellFire)
		{
			testP->GetProjectiles()[0]->GetTexture()->Draw(w->getRenderer());
		}
		if (Player::spellThunder)
		{
			testP->GetProjectiles()[1]->GetTexture()->Draw(w->getRenderer());
		}
		if (Player::spellFrost)
		{
			testP->GetProjectiles()[2]->GetTexture()->Draw(w->getRenderer());
		}

		if(testP->GetProjectiles().size() > 3)
		{
			for(int i = 3; i < testP->GetProjectiles().size(); i++)
			{
				testP->GetProjectiles()[i]->GetTexture()->Draw(w->getRenderer());
			}
		}

	}
	else
	{
		if (isinBossR)
			return; // load other loading screen 
		else
			loadingScreen.Draw(w->getRenderer());
	}
}

// private methods to encapsulate various utilities used within update
void ScndDungeon::ChangeRoom(SDL_Renderer* r)
{

	RoomType newRoom;

	// roll for amount of enemies on creating new room
	// clear activeunits vector
	// for loop
	// switch off random number diceroll(3,0) (3 enemies)
	// fill with enemies each roll will be a diff enemy type
	// use current room for potential spawns


	switch (current_room->GetDoor())
	{
	case NORTH:
		newRoom = Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x - 1, Player::testMinimap.PlayerLocation().y);

		if (newRoom != EMPTY)
		{
			Player::testMinimap.PlayerLocation().x -= 1;
			delete current_room;
			current_room = nullptr;

			switch (newRoom)
			{
			case PUZZLE:
				current_room = new Waves(r, area, testP->NMESpawns());
				break;
			case BASE:
				current_room = new Base(r, area, testP->NMESpawns());
				break;
			case SHOP:
				current_room = new Shop(r, area);
				break;
			case BOSS:
				current_room = new Boss(r, DRAGON, area);
				isinBossR = true;
				break;
			case LOCKED:
				current_room = new Locked(r, area);
				break;
			}
			//	// when creating room, STARTING POSITION
			// Set up enemy spawns
			loading.Start();
			Player::doorUsed = false;
			if (newRoom == BOSS)
				testP->GetTexture()->Collider().position = testP->GetSpawns()[1];
			else
				testP->GetTexture()->Collider().position = testP->GetSpawns()[3];
			
			

			//	// potentialSpawn[3]
			//RUN FAKE LOADING
		}
		else
			Player::doorUsed = false;

		break;

		case EAST:
			 newRoom = Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x - 1, Player::testMinimap.PlayerLocation().y + 1);

			if (newRoom != EMPTY)
			{
				Player::testMinimap.PlayerLocation().y += 1;
				delete current_room;
				current_room = nullptr;

				switch (newRoom)
				{
				case PUZZLE:
					current_room = new Waves(r, area, testP->NMESpawns());
					break;
				case BASE:
					current_room = new Base(r, area, testP->NMESpawns());
					break;
				case SHOP:
					current_room = new Shop(r, area);
					break;
				case BOSS:
					current_room = new Boss(r, DRAGON, area);
					isinBossR = true;
					break;
				case LOCKED:
					current_room = new Locked(r, area);
					break;
				}
				//	// when creating room, STARTING POSITION
				// Set up enemy spawns
				loading.Start();
				Player::doorUsed = false;
				testP->GetTexture()->Collider().position = testP->GetSpawns()[0];

				

				//RUN FAKE LOADING
			}
			else
				Player::doorUsed = false;

			break;
		case SOUTH:
			newRoom = Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x + 1, Player::testMinimap.PlayerLocation().y);

			if (newRoom != EMPTY)
			{
				Player::testMinimap.PlayerLocation().x += 1;
				delete current_room;
				current_room = nullptr;

				switch (newRoom)
				{
				case PUZZLE:
					current_room = new Waves(r, area, testP->NMESpawns());
					break;
				case BASE:
					current_room = new Base(r, area, testP->NMESpawns());
					break;
				case SHOP:
					current_room = new Shop(r, area);
					break;
				case BOSS:
					current_room = new Boss(r, DRAGON, area);
					isinBossR = true;
					break;
				case LOCKED:
					current_room = new Locked(r, area);
					break;
				}
				//	// when creating room, STARTING POSITION
				// Set up enemy spawns
				loading.Start();
				Player::doorUsed = false;
				testP->GetTexture()->Collider().position = testP->GetSpawns()[1];

				//	// potentialSpawn[3]
				//RUN FAKE LOADING
			}
			else
				Player::doorUsed = false;
			break;
		case WEST:
			newRoom = Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x, Player::testMinimap.PlayerLocation().y - 1);

			if (newRoom != EMPTY)
			{
				Player::testMinimap.PlayerLocation().y -= 1;
				delete current_room;
				current_room = nullptr;

				switch (newRoom)
				{
				case PUZZLE:
					current_room = new Waves(r, area, testP->NMESpawns());
					break;
				case BASE:
					current_room = new Base(r, area, testP->NMESpawns());
					break;
				case SHOP:
					current_room = new Shop(r, area);
					break;
				case BOSS:
					current_room = new Boss(r, DRAGON, area);
					isinBossR = true;
					break;
				case LOCKED:
					current_room = new Locked(r, area);
					break;
				}
				//	// when creating room, STARTING POSITION
				// Set up enemy spawns
				loading.Start();
				Player::doorUsed = false;
				testP->GetTexture()->Collider().position = testP->GetSpawns()[2];

				//	// potentialSpawn[3]
				//RUN FAKE LOADING
			}
			else
				Player::doorUsed = false;
	}
}

// If item is picked up delete it.
void ScndDungeon::CheckActiveItems()
{
	if (!ActiveItems.empty())
	{
		for (int i = 0; i < ActiveItems.size(); i++)
		{
			if (ActiveItems[i]->IsPickedUp())
			{
				ActiveItems[i] = nullptr;
				ActiveItems.erase(ActiveItems.begin() + i);
			}
		}
	}

}

// Switch to move enemies around and potentially spawn
// items
void ScndDungeon::MoveEnemies(SDL_Renderer* r)
{
	if (!current_room->ActiveUnits().empty())
	{
		for (int i = 0; i < current_room->ActiveUnits().size(); i++)
		{
			if (current_room->ActiveUnits()[i]->IsAlive())
			{
				current_room->ActiveUnits()[i]->AIMove();
			}
			else
			{
				// put this in a function 
				switch (current_room->ActiveUnits()[i]->DetermineDrop())
				{
				case 0:
					ActiveItems.push_back(new Bomb(r, current_room->ActiveUnits()[i]->GetTexture()->Collider().position));
					break;
				case 2:
					ActiveItems.push_back(new Potion(r, current_room->ActiveUnits()[i]->GetTexture()->Collider().position));
					break;
				case 4:
					ActiveItems.push_back(new Food(r, current_room->ActiveUnits()[i]->GetTexture()->Collider().position));
					break;
				case 6:
					ActiveItems.push_back(new Gold(r, 10, current_room->ActiveUnits()[i]->GetTexture()->Collider().position));
					break;
				case 8:
					ActiveItems.push_back(new Gold(r, 20, current_room->ActiveUnits()[i]->GetTexture()->Collider().position));
					break;
				default:
					break;
				}

				current_room->ActiveUnits()[i] = nullptr;
				current_room->EraseUnit(i);
			}
		}
	}
}

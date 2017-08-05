// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#include "StateManager.h"

//Static member properties must be initialized like so:
GameState* GameStateManager::ptr_current_state_ = nullptr;
bool GameStateManager::is_state_change_ = false;
StateType GameStateManager::state_type_ = GAMESTATE_NULL;
bool GameStateManager::gameplaystarted = false;

GameStateManager::GameStateManager()
{}


//If there is an active state, it's Clean() method is invoked, and the
// associated memory of ptr_current_state_ is freed. if there is no
//active state then the ptr_current_state_ is freed
GameStateManager::~GameStateManager()
{
	if (ptr_current_state_)
	{
		ptr_current_state_->Clean();
		delete ptr_current_state_;
	}
	else
	{
		delete ptr_current_state_;
	}
}

// if there is no state changing occuring and there is an active
// state then the init method of ptr_current_state_ is invoked
void GameStateManager::Init(ScreenUtil* w, Player* p)
{
	is_state_change_ = false;

	testPlayer = p;


	if (ptr_current_state_ && !is_state_change_)
	{
		ptr_current_state_->Init(w, testPlayer);
	}
}

//If there is no state change occuring and there is an active state
// then the HandleEvents(SDL_Event* event) method of ptr_current_state_
// is invoked
void GameStateManager::HandleEvents(SDL_Event* event)
{
	if (ptr_current_state_ && !is_state_change_)
	{
		ptr_current_state_->HandleEvents(event);
	}
}

//If there is no state change occuring and there is an active state
// then the Update(WindowManager* w) method of ptr_current_state_
// is invoked
void GameStateManager::Update(ScreenUtil* w)
{
	if (ptr_current_state_ && !is_state_change_)
	{
		ptr_current_state_->Update(w);
	}
}

//If there is no state change occuring and there is an active state
// then the Render(WindowManager* w) method of ptr_current_state_
// is invoked
void GameStateManager::Render(ScreenUtil* w)
{
	if (ptr_current_state_ && !is_state_change_)
	{
		ptr_current_state_->Render(w);
	}
}

void GameStateManager::setCurrentState(int gameStateID)
{
	is_state_change_ = true;
	state_type_ = (StateType)gameStateID;

	//If ptr_current_state_ isn't nullptr then it means another state is active
	// Before switching to the next state. Clean() is called on the current
	// state then the memory associated with the object is deallocated.
	if (ptr_current_state_)
	{
		ptr_current_state_->Clean();
		delete ptr_current_state_;
		ptr_current_state_ = nullptr;
	}

	switch (gameStateID)
	{
	case GAMESTATE_FIRSTDUNGEON:
		gameplaystarted = true;
		if (Mix_PlayingMusic() == 0)
		{
			// Play the music
			Mix_PlayMusic(AudioManager::GetInstance()->GetBG(), -1);
		}
		ptr_current_state_ = new Dungeon();
		break;
	case GAMESTATE_MAINMENU:
		ptr_current_state_ = new MainMenuState();
		break;
	case GAMESTATE_HELLPROGR:
		ptr_current_state_ = new ProgressionStatePepe();
		break;
	case GAMESTATE_DRGNPROGR:
		ptr_current_state_ = new ProgressionStateDolan();
		break;
	case GAMESTATE_CREDITS:
		ptr_current_state_ = new Credits();
		break;
	case GAMESTATE_SCNDDUNGEON:
		ptr_current_state_ = new ScndDungeon();
		break;
	case GAMESTATE_THRDDUNGEON:
//		ptr_current_state_ = new Dungeon();
		break;
	case GAMESTATE_GAMEOVER:
		ptr_current_state_ = new GameOver();
		break;
	case GAMESTATE_GAMEWON:
		ptr_current_state_ = new GameWon();
		break;
	case GAMESTATE_SUBMENU:
		ptr_current_state_ = new NewGame();
		break;
	}


}
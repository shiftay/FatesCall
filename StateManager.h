// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#pragma once

#include "GameState.h"
#include "MainMenuState.h"
#include "Credits.h"
#include "ProgressionStateDolan.h"
#include "ProgressionStatePepe.h"
#include "Dungeon.h"
#include "GameOver.h"
#include "GameWon.h"
#include "NewGame.h"
#include "ScndDungeon.h"

// Possible GameState Types
enum StateType
{
	// Special - Terminate
	GAMESTATE_TERMINATE = -1,

	//Transistion State
	GAMESTATE_NULL,

	//MAINMENU STATE
	GAMESTATE_MAINMENU,

	//FIRST DUNGEON
	GAMESTATE_FIRSTDUNGEON,

	// SECOND DUNGEON
	GAMESTATE_SCNDDUNGEON,

	//THIRD DUNGEON
	GAMESTATE_THRDDUNGEON,

	//HELLKNIGHT PROGRESSION
	GAMESTATE_HELLPROGR,

	//DRAGON PROGRESSION
	GAMESTATE_DRGNPROGR,

	//CREDITS STATE
	GAMESTATE_CREDITS,

	//GAMEOVER STATE
	GAMESTATE_GAMEOVER,

	//GAMEWON STATE
	GAMESTATE_GAMEWON,

	//SUBMENU STATE
	GAMESTATE_SUBMENU
};


// GameStateManager is responsible for tracking the current GameState
// switching states and executing the logic of the current GameState
class GameStateManager
{
	//================================================================
	//		Properties
	//================================================================
private:
	// The active Game State
	static GameState* ptr_current_state_;

	//Stores the type of the active GameState
	static StateType state_type_;

	//Tracks whether or not a state change is occuring
	static bool is_state_change_;


	Player* testPlayer;

	//=================================================================
	//		Behaviours
	//=================================================================
public:
	GameStateManager();
	~GameStateManager();

	//Invokes the Init() function of the Current GameState
	//	@param w Pointer to the applications window manager
	void Init(ScreenUtil* w, Player*);

	//Invokes the HandleEvents(SDL_Event* event) function of the current GameState
	//		@param event structure
	void HandleEvents(SDL_Event* event);

	//Invokes the Update function of the current gameState
	void Update(ScreenUtil* w);

	//Invokes the render window manager function of the current GameState
	//	@param w pointer to the application's window manager
	void Render(ScreenUtil* w);

	// Accessors
	inline static StateType getStateType() { return state_type_; }
	inline static bool isNewState() { return is_state_change_; }
	//Mutator for method
	static void setCurrentState(int gameStateID);
	static 	bool gameplaystarted;
};
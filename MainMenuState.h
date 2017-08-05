// Author: Giane Carlo
// Class MainMenuState
// Date : 4/10/2016
//
// Version : 0.0.1

#pragma once
#include "Button.h"
#include "GameState.h"
#include "ScreenUtil.h"
#include "StateManager.h"

//
//	State for the MainMenu
//
class MainMenuState : public GameState
{
private:
	Button* new_game_btn_;

	Texture background;

	Player* testP;

	Button* load_game_btn_; // maybe

	Button* quit_game_btn_;

public:
	MainMenuState() {}
	~MainMenuState() {}
	

	//Main menu state initialization method
	virtual void Init(ScreenUtil* w, Player*);

	//Main menu state clean method
	virtual void Clean();

	//Main menu state event handler method
	virtual void HandleEvents(SDL_Event* event);

	//Main menu state logic update method
	virtual void Update(ScreenUtil* w);

	//Main menu state render method
	virtual void Render(ScreenUtil* w);

};

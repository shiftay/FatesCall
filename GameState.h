// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#pragma once

#include <iostream>
#include "Player.h"
#include "RenderingEngine.h"

//(Pure) Abstract Base Class for all GameState's.
class GameState
{
	//============================================================//
	//						Behaviors							  //
	//============================================================//
public:
	virtual ~GameState() {}

	//GameState initialization method
	virtual void Init(ScreenUtil* w, Player*) = 0;

	//GameState clean (destruction) method
	virtual void Clean() = 0;

	//GameState event handler method
	virtual void HandleEvents(SDL_Event* event) = 0;

	//GameState logic method
	virtual void Update(ScreenUtil* w) = 0;

	//GameState render method
	virtual void Render(ScreenUtil* w) = 0;

protected:
	GameState() {}
};
// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Class ProgressionStateDolan.h
//
// Date : 4/10/2016
// Version : 0.0.1
#pragma once

#include "Button.h"
#include "GameState.h"
#include "ScreenUtil.h"
#include "StateManager.h"


class ProgressionStateDolan : public GameState
{
private:
	Button* inventory_btn_;
	Button* health_btn_;

	Player* hldr;

	Texture backGround;

public:
	ProgressionStateDolan() {}
	~ProgressionStateDolan() {}

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

	virtual void Draw(SDL_Renderer* r);

};

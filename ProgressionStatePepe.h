// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Class ProgressionStatPepe.h
//
// Date : 5/10/2016
// Version : 1.0.1
#pragma once

#include "Button.h"
#include "GameState.h"
#include "ScreenUtil.h"
#include "StateManager.h"


class ProgressionStatePepe : public GameState
{
private:
	Button* inventory_btn_;
	Button* health_btn_;

	Player* hldr;

	Texture backGround;

public:
	ProgressionStatePepe() {}
	~ProgressionStatePepe() {}

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

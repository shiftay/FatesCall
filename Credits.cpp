// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Date : 6/10/2016
// Version : 1.0.1
#include "Credits.h"

void Credits::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	backGround.LoadTexture(w->getRenderer(), "resources//States//Credits.png");

	hldr = p;
}

void Credits::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
}

void Credits::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;
}

// Handles the main menu's button's events
void Credits::HandleEvents(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT)
		{
			cout << "|-->Mouse Click(" << event->button.x << "."
				<< event->button.y << ")|Current State:Main Menu State" << endl;
		}
		break;
	case SDL_KEYDOWN:
		if(event->key.keysym.sym == SDLK_ESCAPE)
		{
			GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
			return;
		}
	}
}

// Checks to see if the either of the buttons have been clicked
// If so the current game state is changed.
void Credits::Update(ScreenUtil* w)
{
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void Credits::Render(ScreenUtil* w)
{
	// Background
	Draw(w->getRenderer());
}
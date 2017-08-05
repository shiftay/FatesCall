// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Date : 6/10/2016
// Version : 1.0.1
#include "GameWon.h"

void GameWon::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	backGround.LoadTexture(w->getRenderer(), "resources//States//GameWon.png");

	string str = "Main Menu";
	string str2 = "Credits";

	hldr = p;

	SDL_Color button_text_color = { 255,0,0,255 };

	//Stores the x-axis value of tex's center point
	int center_x_of_texture;

	//*Round down (so we end up with a whole number then explicity converts
	// value to integer so there is no data loss, Failing to do so will reuslt
	// in lost data (through the implicity conversion of double to int)
	//int center_x_of_window = (int)floor(w->getWidth() * 0.5);//*
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);//*

	main_menu_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(main_menu_btn_->getBoundingBox().w * 0.5);//*
	main_menu_btn_->setPosition(100, window_height_one_eighth * 4);

	credits_btn_ = new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(credits_btn_->getBoundingBox().w * 0.5);//*
	credits_btn_->setPosition(700, window_height_one_eighth * 4);
}

void GameWon::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
}

void GameWon::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;

	delete main_menu_btn_;
	delete credits_btn_;
}

// Handles the main menu's button's events
void GameWon::HandleEvents(SDL_Event* event)
{
	// Event Handler for new_game_btn_
	main_menu_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	credits_btn_->HandleEvents(event);

	switch (event->type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT)
		{
			cout << "|-->Mouse Click(" << event->button.x << "."
				<< event->button.y << ")|Current State:Main Menu State" << endl;
		}
		break;
	}
}

// Checks to see if the either of the buttons have been clicked
// If so the current game state is changed.
void GameWon::Update(ScreenUtil* w)
{
	if (main_menu_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
		return;
	}

	if (credits_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_CREDITS);
		return;
	}
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void GameWon::Render(ScreenUtil* w)
{
	// Background
	Draw(w->getRenderer());

	//Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), main_menu_btn_->getTexture(),
		main_menu_btn_->getBoundingBox().x, main_menu_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), credits_btn_->getTexture(),
		credits_btn_->getBoundingBox().x, credits_btn_->getBoundingBox().y);
}
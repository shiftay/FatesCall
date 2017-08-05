// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Date : 6/10/2016
// Version : 1.0.1
#include "GameOver.h"

void GameOver::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	backGround.LoadTexture(w->getRenderer(), "resources//States//GameOver.png");

	string str = "Main Menu";
	string str2 = "New Game";

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

	play_again_btn_= new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(play_again_btn_->getBoundingBox().w * 0.5);//*
	play_again_btn_->setPosition(700, window_height_one_eighth * 4);
}

void GameOver::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
}

void GameOver::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;

	delete main_menu_btn_;
	delete play_again_btn_;
}

// Handles the main menu's button's events
void GameOver::HandleEvents(SDL_Event* event)
{
	// Event Handler for new_game_btn_
	main_menu_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	play_again_btn_->HandleEvents(event);

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
void GameOver::Update(ScreenUtil* w)
{
	if (main_menu_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_MAINMENU);
		return;
	}

	if (play_again_btn_->getState() == CLICKED)
	{
		hldr->Refill();
		GameStateManager::setCurrentState(GAMESTATE_FIRSTDUNGEON);
		return;
	}
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void GameOver::Render(ScreenUtil* w)
{
	// Background
	Draw(w->getRenderer());

	//Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), main_menu_btn_->getTexture(),
		main_menu_btn_->getBoundingBox().x, main_menu_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), play_again_btn_->getTexture(),
		play_again_btn_->getBoundingBox().x, play_again_btn_->getBoundingBox().y);
}
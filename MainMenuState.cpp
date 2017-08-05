#include "MainMenuState.h"


void MainMenuState::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	string str = "New Game!";
	string str2 = "Credits";
	string str3 = "Exit";

	background.LoadTexture(w->getRenderer(), "resources//States//Splash.png");

	testP = p;

	SDL_Color button_text_color = { 255,0,0,255 };

	//Stores the x-axis value of tex's center point
	int center_x_of_texture;

	//*Round down (so we end up with a whole number then explicity converts
	// value to integer so there is no data loss, Failing to do so will reuslt
	// in lost data (through the implicity conversion of double to int)
	int center_x_of_window = (int)floor(w->getWidth() * 0.5);//*
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);//*

	new_game_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(new_game_btn_->getBoundingBox().w * 0.5);//*
	new_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 2);

	load_game_btn_ = new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(load_game_btn_->getBoundingBox().w * 0.5);//*
	load_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 3);

	quit_game_btn_ = new Button(w->getRenderer(), str3, button_text_color);
	center_x_of_texture = (int)floor(quit_game_btn_->getBoundingBox().w * 0.5);//*
	quit_game_btn_->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 4);
}

void MainMenuState::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;

	delete new_game_btn_;
	delete load_game_btn_;
	delete quit_game_btn_;
}

// Handles the main menu's button's events
void MainMenuState::HandleEvents(SDL_Event* event)
{
	// Event Handler for new_game_btn_
	new_game_btn_->HandleEvents(event);

	load_game_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	quit_game_btn_->HandleEvents(event);

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
void MainMenuState::Update(ScreenUtil* w)
{
	if (new_game_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_SUBMENU);
		return;
	}

	if (load_game_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_CREDITS);
		return;
	}

	if (quit_game_btn_->getState() == CLICKED)
	{
		GameStateManager::setCurrentState(GAMESTATE_TERMINATE);
	}
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void MainMenuState::Render(ScreenUtil* w)
{
	// Background Fill

	//Set the Renderer Color to desired value for drawing the background.
	SDL_SetRenderDrawColor(w->getRenderer(), 0, 0, 162, 255);

	//Define the x and event y as well as width and height properties of the
	//background image
	SDL_Rect bgRect = { 0,0, w->getWidth(), w->getHeight() };

	//Paint the are defined by bgRect to the Scene2D object within
	//RenderingEngine
	SDL_RenderFillRect(w->getRenderer(), &bgRect);


	background.Draw(w->getRenderer());


	//Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), new_game_btn_->getTexture(),
		new_game_btn_->getBoundingBox().x, new_game_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), load_game_btn_->getTexture(),
		load_game_btn_->getBoundingBox().x, load_game_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), quit_game_btn_->getTexture(),
		quit_game_btn_->getBoundingBox().x, quit_game_btn_->getBoundingBox().y);
}




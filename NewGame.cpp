// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Date : 6/10/2016
// Version : 1.0.1
#include "NewGame.h"

void NewGame::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	backGround.LoadTexture(w->getRenderer(), "resources//States//Splash.png");

	string str = "Start Game";
	string str2 = "Load Game";

	hldr = p;

	SDL_Color button_text_color = { 255,0,0,255 };

	//Stores the x-axis value of tex's center point
	int center_x_of_texture;

	//*Round down (so we end up with a whole number then explicity converts
	// value to integer so there is no data loss, Failing to do so will reuslt
	// in lost data (through the implicity conversion of double to int)
	//int center_x_of_window = (int)floor(w->getWidth() * 0.5);//*
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);//*

	start_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(start_btn_->getBoundingBox().w * 0.5);//*
	start_btn_->setPosition(100, window_height_one_eighth * 4);

	load_btn_= new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(load_btn_->getBoundingBox().w * 0.5);//*
	load_btn_->setPosition(700, window_height_one_eighth * 4);
}

void NewGame::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
}

void NewGame::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;

	delete start_btn_;
	delete load_btn_;
}

// Handles the main menu's button's events
void NewGame::HandleEvents(SDL_Event* event)
{
	// Event Handler for new_game_btn_
	start_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	load_btn_->HandleEvents(event);

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
void NewGame::Update(ScreenUtil* w)
{
	if (start_btn_->getState() == CLICKED)
	{
		hldr->Refill();
		GameStateManager::setCurrentState(GAMESTATE_FIRSTDUNGEON);
		return;
	}

	if (load_btn_->getState() == CLICKED)
	{
		Load();
		return;
	}
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void NewGame::Render(ScreenUtil* w)
{
	// Background
	Draw(w->getRenderer());

	//Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), start_btn_->getTexture(),
		start_btn_->getBoundingBox().x, start_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), load_btn_->getTexture(),
		load_btn_->getBoundingBox().x, load_btn_->getBoundingBox().y);
}

void NewGame::Load()
{
	int holder;

	ifstream inFile("resources\\savedPlayer.txt");
	if(inFile)
	{
		hldr->LoadPlayer(inFile);
	}
	else
	{
		cout << "Failed to load";
	}
	inFile.close();

	ifstream inFile2("resources\\savedLocation.txt");

	if(inFile2)
	{
		inFile2 >> holder;
		inFile2.close();
		GameStateManager::setCurrentState(holder);
	}
	else
	{
		cout << "Failed to load";
	}
}
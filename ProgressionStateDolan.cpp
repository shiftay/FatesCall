// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Date : 5/10/2016
// Version : 1.0.1
#include "ProgressionStateDolan.h"

void ProgressionStateDolan::Init(ScreenUtil* w,Player* p)
{
	cout << "|-->MainMenuState::Init() Invoked" << endl;

	string str = "+ Inventory";
	string str2 = "+ Health";

	hldr = p;

	backGround.LoadTexture(w->getRenderer(), "resources//Rooms//DolanDefeat.png");
	SDL_Color button_text_color = { 255,0,0,255 };

	//Stores the x-axis value of tex's center point
	int center_x_of_texture;

	//*Round down (so we end up with a whole number then explicity converts
	// value to integer so there is no data loss, Failing to do so will reuslt
	// in lost data (through the implicity conversion of double to int)
	//int center_x_of_window = (int)floor(w->getWidth() * 0.5);//*
	int window_height_one_eighth = (int)floor(w->getHeight() * 0.125);//*

	inventory_btn_ = new Button(w->getRenderer(), str, button_text_color);
	center_x_of_texture = (int)floor(inventory_btn_->getBoundingBox().w * 0.5);//*
	inventory_btn_->setPosition(100, window_height_one_eighth * 4);

	health_btn_ = new Button(w->getRenderer(), str2, button_text_color);
	center_x_of_texture = (int)floor(health_btn_->getBoundingBox().w * 0.5);//*
	health_btn_->setPosition(700, window_height_one_eighth * 4);
}

void ProgressionStateDolan::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
}

void ProgressionStateDolan::Clean()
{
	cout << "|-->MainMenuState::Clean() Invoked" << endl;

	delete inventory_btn_;
	delete health_btn_;
}

// Handles the main menu's button's events
void ProgressionStateDolan::HandleEvents(SDL_Event* event)
{
	// Event Handler for new_game_btn_
	inventory_btn_->HandleEvents(event);

	// Event Handler for quit_game_btn_
	health_btn_->HandleEvents(event);

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
void ProgressionStateDolan::Update(ScreenUtil* w)
{
	if (inventory_btn_->getState() == CLICKED)
	{
		hldr->GetInventory().SetMaxSpace(2);
		GameStateManager::setCurrentState(GAMESTATE_THRDDUNGEON);
		return;
	}

	if (health_btn_->getState() == CLICKED)
	{
		hldr->Health().Max(hldr->Health().Max() + 2);
		hldr->Health().Current(hldr->Health().Max());
		GameStateManager::setCurrentState(GAMESTATE_THRDDUNGEON);
	}
}

// All Draw operations for the main menu state are performed here. Everything
// drawn within this method is drawn to the RenderingEngine's scene_ property.
void ProgressionStateDolan::Render(ScreenUtil* w)
{
	// Background
	Draw(w->getRenderer());

	//Buttons
	RenderingEngine::DrawTexture(w->getRenderer(), inventory_btn_->getTexture(),
		inventory_btn_->getBoundingBox().x, inventory_btn_->getBoundingBox().y);
	RenderingEngine::DrawTexture(w->getRenderer(), health_btn_->getTexture(),
		health_btn_->getBoundingBox().x, health_btn_->getBoundingBox().y);
}
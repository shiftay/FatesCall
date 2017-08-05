// Author: Giane Carlo
// Class Shop
// Date : 4/10/2016
//
// Version : 0.0.2
// SHR		Added functionality for buying things
#pragma once

#include "Room.h"
#include "Button.h"

class Shop : public Room
{
private:
	Texture texShop_;
	Texture texSWindow_;

	Button* potion_btn_;
	Button* key_btn_; 
	Button* bomb_btn_;


	SDL_Rect shopWinPos_;
	SDL_Rect potionButtonPos_;
	SDL_Rect keyButtonPos_;
	SDL_Rect bombButtonPos_;


	bool isinShop;

	void BuyKey(Player*);
	void BuyPotion(Player*);
	void BuyBomb(Player*);


public:
	Shop(SDL_Renderer*, int);
	~Shop();
	
	virtual void Obstacles(SDL_Renderer*, Player*);
	virtual void Draw(SDL_Renderer*);
	virtual void HandleEvent(SDL_Event*);
};


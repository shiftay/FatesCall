// Author: Giane Carlo
// Class HUD
// Date : 29/9/2016
//
// Version : 0.0.1
// 
#pragma once
#include "Texture.h"
#include "Player.h"
#include <iostream>
#include <sstream>

//
//	Displays and creates the HUD
//
using std::stringstream;

class HUD
{
private:

	Texture texHud_;
	Texture texMap_;
	Texture texInven_;
	Texture texSpell_;
	Texture texFireball_;
	Texture texBlizzard_;
	Texture texLightning_;

	Texture texHealth10_;
	Texture texHealth9_;
	Texture texHealth8_;
	Texture texHealth7_;
	Texture texHealth6_;
	Texture texHealth5_;
	Texture texHealth4_;
	Texture texHealth3_;
	Texture texHealth2_;
	Texture texHealth1_;

	Texture texGold_;
	Texture texKeys_;
	Texture texGoldCount_;
	Texture texKeyCount_;
	
	Texture texBomb_;
	Texture texPotion_;
	

	SDL_Texture *texSpellWord_;
	SDL_Texture *textInvenWord_;

	SDL_Rect hudPos_;
	SDL_Rect miniMap_;
	SDL_Rect inventoryBox_;
	SDL_Rect potion_;
	SDL_Rect bomb_;
	SDL_Rect spellBox_;
	SDL_Rect fireball_;
	SDL_Rect blizzard_;
	SDL_Rect lightning_;
	SDL_Rect health10_;
	SDL_Rect health9_;
	SDL_Rect health8_;
	SDL_Rect health7_;
	SDL_Rect health6_;
	SDL_Rect health5_;
	SDL_Rect health4_;
	SDL_Rect health3_;
	SDL_Rect health2_;
	SDL_Rect health1_;
	SDL_Rect gold_;
	SDL_Rect keys_;
	SDL_Rect goldCount_;
	SDL_Rect keyCount_;
	SDL_Rect inventoryWord_;
	SDL_Rect spellWord_;
	SDL_Rect test;
	SDL_Rect itemAmount_;


public:
	HUD(SDL_Renderer*);
	~HUD();
	void Init(SDL_Renderer*,int spell,int bag,int goldamount,int keycount,int health, Inventory);
	string ToString(const int);
};


#include "HUD.h"

HUD::HUD(SDL_Renderer* r)
{
	texBlizzard_.LoadTexture(r, "resources\\HUD\\Blizzard.png");
	texFireball_.LoadTexture(r, "resources\\HUD\\Fireball.png");
	texLightning_.LoadTexture(r, "resources\\HUD\\Lightning.png");
	texHealth1_.LoadTexture(r, "resources\\HUD\\Health1.png");
	texHealth2_.LoadTexture(r, "resources\\HUD\\Health2.png");
	texHealth3_.LoadTexture(r, "resources\\HUD\\Health3.png");
	texHealth4_.LoadTexture(r, "resources\\HUD\\Health4.png");
	texHealth5_.LoadTexture(r, "resources\\HUD\\Health5.png");
	texHealth6_.LoadTexture(r, "resources\\HUD\\Health6.png");
	texHealth7_.LoadTexture(r, "resources\\HUD\\Health7.png");
	texHealth8_.LoadTexture(r, "resources\\HUD\\Health8.png");
	texHealth9_.LoadTexture(r, "resources\\HUD\\Health9.png");
	texHealth10_.LoadTexture(r, "resources\\HUD\\Health10.png");
	texHud_.LoadTexture(r, "resources\\HUD\\HUD.png");
	texBomb_.LoadTexture(r, "resources\\HUD\\Bombs.png");
	texPotion_.LoadTexture(r, "resources\\HUD\\Potion.png");



	SDL_Rect hudPos_h =				{-15,600,1035,200};
	SDL_Rect miniMap_h =				{ 760,613,200,165};
	SDL_Rect potion_h =				{ 375,695,50,30 };
	SDL_Rect bomb_h =					{ 385,685,100,50 };

	hudPos_ = hudPos_h;
	miniMap_ = miniMap_h;
	potion_ = potion_h;
	bomb_ = bomb_h;

	SDL_Rect itemAmount_h =					{ 460,730,33,33 };
	itemAmount_ = itemAmount_h;

	SDL_Rect fireball_h =				{ 590,690,50,40 };
	SDL_Rect blizzard_h =				{ 590,690,70,50 };
	SDL_Rect lightning_h =			{ 590,680,70,70 };

	fireball_ = fireball_h;
	blizzard_ = blizzard_h;
	lightning_ = lightning_h;

	SDL_Rect goldCount_h =			{ 110,740,33,33};
	SDL_Rect keyCount_h =			{ 260,740,33,33};
	SDL_Rect inventoryWord_h =		{ 485,610,60,60};
	SDL_Rect spellWord_h =			{ 640,610,50,50};

	goldCount_ = goldCount_h;
	keyCount_ = keyCount_h;
	inventoryWord_ = inventoryWord_h;
	spellWord_ = spellWord_h;

	SDL_Rect health10_h =				{ 100,630,200,50 };
	SDL_Rect health9_h =				{ 100,630,172,50 };
	SDL_Rect health8_h =			    { 100,630,154,50 };
	SDL_Rect health7_h =				{ 100,630,135,50 };
	SDL_Rect health6_h =				{ 100,630,118,50 };
	SDL_Rect health5_h =				{ 100,630,99,50 };
	SDL_Rect health4_h =				{ 100,630,81,50 };
	SDL_Rect health3_h =				{ 100,630,61,50 };
	SDL_Rect health2_h =				{ 100,630,44,50 };
	SDL_Rect health1_h =				{ 100,630,24,50 };


	health10_ = health10_h;
	health9_ = health9_h;
	health8_ = health8_h;
	health7_ = health7_h;
	health6_ = health6_h;
	health5_ = health5_h;
	health4_ = health4_h;
	health3_ = health3_h;
	health2_ = health2_h;
	health1_ = health1_h;
}

HUD::~HUD()
{

}

void HUD::Init(SDL_Renderer* r, int spell, int bag, int gold, int keys, int health , Inventory playerInv)
{
	texHud_.Draw(r, &hudPos_);			// Hud Position
	//texGold_.Draw(r, &gold_);		// Gold Icon
	//texKeys_.Draw(r, &keys_);		// Key Icon
	//texSpell_.Draw(r, &spellBox_);		// Spell Box Holder
	//texInven_.Draw(r, &inventoryBox_);	// Inventory Box holder

	switch (spell)
	{
	case 0:
		texFireball_.Draw(r, &fireball_);
		break;
	case 1:
		texBlizzard_.Draw(r, &blizzard_);
		break;
	case 2:
		texLightning_.Draw(r, &lightning_);
		break;
	}

	switch (health)
	{
	case 1:
		texHealth1_.Draw(r, &health1_);
			break;
	case 2:
		texHealth2_.Draw(r, &health2_);
			break;
	case 3:
		texHealth3_.Draw(r, &health3_);
		break;
	case 4:
		texHealth4_.Draw(r, &health4_);
		break;
	case 5:
		texHealth5_.Draw(r, &health5_);
		break;
	case 6:
		texHealth6_.Draw(r, &health6_);
		break;
	case 7:
		texHealth7_.Draw(r, &health7_);
		break;
	case 8:
		texHealth8_.Draw(r, &health8_);
		break;
	case 9:
		texHealth9_.Draw(r, &health9_);
		break;
	case 10:
		texHealth10_.Draw(r, &health10_);
		break;
	}

	int hldr;
	//switch for items
	switch(bag)
	{
	case 0:
		texBomb_.Draw(r, &bomb_);
		hldr = playerInv.GetBombs();
		break;
	case 1:
		texPotion_.Draw(r, &bomb_);
		hldr = playerInv.GetHPot();
		break;
	}
	// currently have bombs and potion
	//switch(item)

	



	TTF_Font* Sans = TTF_OpenFont("resources\\HUD\\Sans.ttf", 24);
	SDL_Color White = { 255, 255, 255 };

	SDL_Surface *amount = TTF_RenderText_Solid(Sans, ToString(gold).c_str(), White);
	SDL_Texture *GoldAmount = SDL_CreateTextureFromSurface(r, amount);
	SDL_FreeSurface(amount);

	SDL_Surface *count = TTF_RenderText_Solid(Sans, ToString(keys).c_str(), White);
	SDL_Texture *KeyCount = SDL_CreateTextureFromSurface(r, count);
	SDL_FreeSurface(count);
	
	SDL_Surface *BAGamount = TTF_RenderText_Solid(Sans, ToString(hldr).c_str(), White);
	SDL_Texture *ItemAmount = SDL_CreateTextureFromSurface(r, BAGamount);
	SDL_FreeSurface(BAGamount);

	SDL_RenderCopy(r, ItemAmount, NULL, &itemAmount_ );
	SDL_RenderCopy(r, GoldAmount, NULL,&goldCount_);
	SDL_RenderCopy(r, KeyCount, NULL, &keyCount_);

	SDL_DestroyTexture(ItemAmount);
	SDL_DestroyTexture(GoldAmount);
	SDL_DestroyTexture(KeyCount);

	TTF_CloseFont(Sans);
}

string HUD::ToString(const int intVal)
{
	stringstream ss;  // Create stringstream
	ss << intVal;	  // add value of intVal to stringstream

	return ss.str();  // return the contents as a string stream
}


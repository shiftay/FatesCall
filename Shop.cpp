#include "Shop.h"

Shop::Shop(SDL_Renderer* r, int area)
{
	string str = " ";
	SDL_Color button_text_color = { 255,255,255,255 };

	isinShop = false;
	FillExits(r);

	switch (area)
	{
	case 0:
		backGround.LoadTexture(r, "resources\\Rooms\\CaveTileset.png");
		break;
	case 1:
		backGround.LoadTexture(r, "resources\\Rooms\\Desert.png");
		break;
	case 2:
		backGround.LoadTexture(r, "resources\\Rooms\\Graveyard.png");
		break;
	case 3:
		break;
	}

	texShop_.LoadTexture(r, "resources\\Shop\\Shop Sprite.png");
	texSWindow_.LoadTexture(r, "resources\\Shop\\Shop Window.png");

     SDL_Rect winPos_hldr  =      { 270,170,500,300};
	 shopWinPos_  = winPos_hldr;
    //potionButtonPos_ =      { 335,308,47,61 };
    //keyButtonPos_    =      { 473,308,48,61 };
    //bombButtonPos_   =      { 615,308,48,61 };
    texShop_.Collider().position.x = 0;
    texShop_.Collider().position.y = 0; 
    potion_btn_ = new Button(r, str, button_text_color);
    potion_btn_->setPosition(335, 308);
	potion_btn_->SetWidth(47);
	potion_btn_->SetHeight(61);
	key_btn_ = new Button(r, str, button_text_color);
    key_btn_->setPosition(473, 308);
	key_btn_->SetWidth(47);
	key_btn_->SetHeight(61);
	bomb_btn_ = new Button(r, str, button_text_color);
    bomb_btn_->setPosition(615, 308);
	bomb_btn_->SetWidth(47);
	bomb_btn_->SetHeight(61);
}

Shop::~Shop()
{
}

void Shop::BuyBomb(Player* p)
{
	if(p->Gold() < 60)
		return;				

	if(p->GetInventory().isFull())
		return;

	p->BuySomething(60);
	p->GetInventory().UpdateBomb(1);
}

void Shop::BuyKey(Player* p)
{
	if(p->Gold() < 100)
		return;

	p->BuySomething(100);
	p->GetInventory().UpdateKeys(1);
}

void Shop::BuyPotion(Player* p)
{
	if(p->Gold() < 20)
		return;				

	if(p->GetInventory().isFull())
		return;

	p->BuySomething(20);
	p->GetInventory().UpdateHPot(1);

}


void Shop::Obstacles(SDL_Renderer* r, Player* p)
{
	// Check if player collided with if so activate shop

	if(Player::isInteracting && Player::currentPos == TOPLEFT)
	{
		isinShop = true;
	}
	else
	{
		Player::isInteracting = false;
		isinShop = false;
	}

	if(isinShop)
	{
		if(potion_btn_->getState() == CLICKED)
		{
			BuyPotion(p);
		}
		if(bomb_btn_->getState() == CLICKED)
		{
			BuyBomb(p);
		}
		if(key_btn_->getState() == CLICKED)
		{
			BuyKey(p);
		}
	}
}

void Shop::Draw(SDL_Renderer* r)
{
	backGround.Draw(r);
	texShop_.Draw(r);

	if (isinShop)
		texSWindow_.Draw(r, &shopWinPos_);

	if (!Doors.empty())
	{
		for (int i = 0; i < Doors.size(); i++)
			Doors[i].Draw(r);
	}
}

void Shop::HandleEvent(SDL_Event* e)
{
	if (isinShop)
	{
		potion_btn_->HandleEvents(e);
		bomb_btn_->HandleEvents(e);
		key_btn_->HandleEvents(e);
	}
}
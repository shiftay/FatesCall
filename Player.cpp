#include "Player.h"
#include <iostream>
using std::cout;

// Initiate Static variables
bool Player::spellFire = false;
bool Player::spellThunder = false;
bool Player::spellFrost = false;
CurrentQuadrant Player::currentPos = BOTTOMLEFT;
LastDirectionPressed Player::lastKey = UPARROW;
bool Player::doorUsed = false;
Minimap Player::testMinimap;
bool Player::isBombPlaced = false;
bool Player::isInteracting = false;

int Player::DiceRoll(int min, int max)
{
	return rand() % max + min;
}


Player::Player(SDL_Renderer* r)
{
	srand(time(NULL));
	
	name = "Beramha";
	goldAmount = 0;
	speed = 8;
	blinkDistance = 100;

	status = STATUS_NEUTRAL;
	
	type = PLAYER;

	canBlink = true;
	canBeDamaged = true;
	isAttacking = false;

	ActiveProj.push_back(new Fireball(r, 1));
	ActiveProj.push_back(new Thunderbolt(r, 1));
	ActiveProj.push_back(new Frostbolt(r, 1));

	canBeDamaged = true;

	spellBook.push_back(FIREBALL);
	spellBook.push_back(THUNDERBOLT);
	spellBook.push_back(FROSTBOLT);


	currentSpell = spellBook[0];
	currentItem = 0;


	health.Set(HEART_SIX, HEART_SIX);
	mana.Set(10, 10);

	texture.LoadTexture(r, "resources/testPlayer.png");
	texture.Collider().height = 50;
	texture.Collider().width = 50;

	Point a = { 100, 300 };
	Point b = { 500, 100 };
	Point c = { 900, 300 };
	Point d = { 500, 500 };

	potentialSpawns.push_back(a);
	potentialSpawns.push_back(b);
	potentialSpawns.push_back(c);
	potentialSpawns.push_back(d);

	Point e = { 280, 90 };
	Point f = { 180, 170};
	Point g = { 380, 170};
	Point h = { 290, 240};
	Point i = { 180, 320};
	Point j = { 380, 320};
	Point k = { 290, 410};
	Point l = { 680, 90};
	Point m = { 580, 170};
	Point n = { 580, 320};
	Point o = { 690, 240};
	Point p = { 780, 170};
	Point q = { 780, 320};
	Point s = { 700, 410};

	enemySpawns.push_back(e);
	enemySpawns.push_back(f);
	enemySpawns.push_back(g);
	enemySpawns.push_back(h);
	enemySpawns.push_back(i);
	enemySpawns.push_back(j);
	enemySpawns.push_back(k);
	enemySpawns.push_back(l);
	enemySpawns.push_back(m);
	enemySpawns.push_back(n);
	enemySpawns.push_back(o);
	enemySpawns.push_back(p);
	enemySpawns.push_back(q);
	enemySpawns.push_back(s);





}

void Player::PlayerProjectiles(SDL_Renderer* r)
{
	if (spellFire)
	{
		if (ActiveProj[0]->GetTravel() == 0)
		{
			ActiveProj[0]->GetTexture()->Collider().position.x = texture.Collider().position.x;
			ActiveProj[0]->GetTexture()->Collider().position.y = texture.Collider().position.y;
			switch (Player::lastKey)
			{
			case UPARROW:
				ActiveProj[0]->SetAxis(true);
				ActiveProj[0]->SetDirection(-1);
				break;
			case DOWNARROW:
				ActiveProj[0]->SetAxis(true);
				ActiveProj[0]->SetDirection(1);
				break;
			case LEFTARROW:
				ActiveProj[0]->SetDirection(-1);
				ActiveProj[0]->SetAxis(false);
				break;
			case RIGHTARROW:
				ActiveProj[0]->SetAxis(false);
				ActiveProj[0]->SetDirection(1);
				break;
			}
			AudioManager::GetInstance()->PlayFB();
		}

		if (ActiveProj[0]->GetTimer()->getTicks() > 1000)
		{
			spellFire = false;
		}

		ActiveProj[0]->Move();
	}
	else
	{
		if (ActiveProj[0]->GetTravel() > 0 && !spellFire)
		{
			delete ActiveProj[0];
			ActiveProj[0] = nullptr;
			ActiveProj[0] = new Fireball(r, 1);
		}
	}

	// for thunderbolt
	if (Player::spellThunder)
	{
		if (ActiveProj[1]->GetTravel() == 0)
		{
			ActiveProj[1]->GetTexture()->Collider().position.x = texture.Collider().position.x;
			ActiveProj[1]->GetTexture()->Collider().position.y = texture.Collider().position.y;
			switch (Player::lastKey)
			{
			case UPARROW:
				ActiveProj[1]->SetAxis(true);
				ActiveProj[1]->SetDirection(-1);
				break;
			case DOWNARROW:
				ActiveProj[1]->SetAxis(true);
				ActiveProj[1]->SetDirection(1);
				break;
			case LEFTARROW:
				ActiveProj[1]->SetDirection(-1);
				ActiveProj[1]->SetAxis(false);
				break;
			case RIGHTARROW:
				ActiveProj[1]->SetAxis(false);
				ActiveProj[1]->SetDirection(1);
				break;
			}
			AudioManager::GetInstance()->PlayTB();
		}

		if (ActiveProj[1]->GetTimer()->getTicks() > 10)
		{
			spellThunder = false;
		}

		ActiveProj[1]->Move();

	}
	else
	{
		if (ActiveProj[1]->GetTravel() > 0 && !spellThunder)
		{
			delete ActiveProj[1];
			ActiveProj[1] = nullptr;
			ActiveProj[1] = new Thunderbolt(r, 1);
		}
	}

	// for frostbolt
	if (spellFrost)
	{
		if (ActiveProj[2]->GetTravel() == 0)
		{
			ActiveProj[2]->GetTexture()->Collider().position.x = texture.Collider().position.x;
			ActiveProj[2]->GetTexture()->Collider().position.y = texture.Collider().position.y;
			switch (lastKey)
			{
			case UPARROW:
				ActiveProj[2]->SetAxis(true);
				ActiveProj[2]->SetDirection(-1);
				break;
			case DOWNARROW:
				ActiveProj[2]->SetAxis(true);
				ActiveProj[2]->SetDirection(1);
				break;
			case LEFTARROW:
				ActiveProj[2]->SetDirection(-1);
				ActiveProj[2]->SetAxis(false);
				break;
			case RIGHTARROW:
				ActiveProj[2]->SetAxis(false);
				ActiveProj[2]->SetDirection(1);
				break;
			}
			AudioManager::GetInstance()->PlayFrost();
		}
		if (ActiveProj[2]->GetTimer()->getTicks() > 10)
		{
			spellFrost = false;
		}

		ActiveProj[2]->Move();
	}
	else
	{
		if (ActiveProj[2]->GetTravel() > 0 && !spellFrost)
		{
			delete ActiveProj[2];
			ActiveProj[2] = nullptr;
			ActiveProj[2] = new Frostbolt(r, 1);
		}
	}



	if(ActiveProj.size() > 3)
	{
		for(int i = 3; i < ActiveProj.size(); i++)
		{
			if(ActiveProj[i]->GetTimer()->getTicks() > 2000)
			{
				ActiveProj[i]->Move();
			}
			if(ActiveProj[i]->GetTimer()->getTicks() > 4000 && ActiveProj[i]->IsExploded())
			{
				delete ActiveProj[i];
				ActiveProj[i] = nullptr;
				ActiveProj.erase(ActiveProj.begin() + i);
			}
		}
	}
}


void Player::CycleInventory()
{
	currentItem++;

	if (currentItem >= 2)
		currentItem = 0;
}


// handles keyboard events for the player
void Player::HandleEvents(SDL_Event* e)
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

	if(timer.getTicks() > 3000 && !canBlink)
	{
		canBlink = true;
		timer.Stop();
	}

    if( currentKeyStates[ SDL_SCANCODE_UP ] )
    {
		Move(-1, true);
	}
    if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
    {
		Move(1, true);		// move
    }
	if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
    {
		Move(-1, false);		// move
    }
	if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
    {
		Move(1, false);		// move
    }

	if(currentKeyStates[ SDL_SCANCODE_SPACE ] )
	{
		// attack
		CastSpell();
	}

	if(currentKeyStates[ SDL_SCANCODE_F ] )
	{
		isInteracting = true;
	}

	if(currentKeyStates[ SDL_SCANCODE_E ] )
	{
		//cycle inventory
		CycleInventory();
	}

	if (currentKeyStates[SDL_SCANCODE_A])
	{
		// use item
		UseItem();
	}

	if (currentKeyStates[SDL_SCANCODE_Q])
	{
		//cycle spells
		CycleSpells();
	}

	if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_LSHIFT])
	{
		// blink
		Blink(-1, true);
	}
	if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_LSHIFT])
	{
		// blink
		Blink(1, true);
	}

	if (currentKeyStates[SDL_SCANCODE_LEFT] && currentKeyStates[SDL_SCANCODE_LSHIFT])
	{
		// blink
		Blink(-1, false);
	}
	if (currentKeyStates[SDL_SCANCODE_RIGHT] && currentKeyStates[SDL_SCANCODE_LSHIFT])
	{
		// blink
		Blink(1, false);
	}

}

void Player::UseItem()
{
	switch(currentItem)
	{
	case 0: // bomb.
		if(inventory.GetBombs() <= 0)
			return;
		else if(!isBombPlaced)
		{
			isBombPlaced = true;
			inventory.UpdateBomb(-1);
		}
		break;
	case 1: // potion
		if(inventory.GetHPot() <= 0)
			return;
		else
		{
			health += 4;
			inventory.UpdateHPot(-1);
		}
		break;
	}



}




// cycles through the currently selected spell
void Player::CycleSpells()
{
	if (currentSpell + 1 >= 3)
		currentSpell = 0;
	else
		currentSpell++;
}


void Player::HandleCollision(int itemType)
{

	switch (itemType)
	{
	case 0: // bomb
		inventory.UpdateBomb(1);
		break;
	case 1: // gold

		inventory.UpdateBomb(1);
		break;
	case 2:	// health pot
		inventory.UpdateHPot(1);
		break;
	case 3: // food
		health += 1;
		break;
	}


}


// handles collisions with damage involved
void Player::HandleCollision(int collided, int damage)
{
	if (!canBeDamaged && timer.getTicks() > 1000)
	{
		canBeDamaged = true;
	}

	switch(collided)
	{
	case ENEMY:
		if (canBeDamaged)
		{
			health -= damage;		//take damage
		}
		if (IsAlive())
		{
			timer.Start();		// start invincibility frames
			canBeDamaged = false;
		}
		else
		{
			isActive = false;
		}
		break;
	case PLAYER:
		break;
	}

}


// moves the player
void Player::Move(int direction, bool isYaxis)
{
	// up / down
	if(isYaxis)
	{
		if (texture.Collider().position.y + (speed * direction) < 0)
			texture.Collider().position.y = 0;
		else if (texture.Collider().position.y + (speed * direction) >= 600 - texture.Collider().height)
			texture.Collider().position.y = 600 - texture.Collider().height;
		else
			texture.Collider().position.y = texture.Collider().position.y + (speed * direction);

		if (direction > 0)
			lastKey = DOWNARROW;
		else
			lastKey = UPARROW;
	}
	else // left / right
	{
		if (texture.Collider().position.x + (speed * direction) < 0)
			texture.Collider().position.x = 0;
		else if (texture.Collider().position.x + (speed * direction) >= 1000 - texture.Collider().width)
			texture.Collider().position.x = 1000 - texture.Collider().width;
		else
			texture.Collider().position.x = texture.Collider().position.x + (speed * direction);

		if (direction > 0)
			lastKey = RIGHTARROW;
		else
			lastKey = LEFTARROW;
	}
	
	UpdateQuad();
}

void Player::UpdateQuad()
{
	if (texture.Collider().position.x > 500 && texture.Collider().position.y > 300)
		currentPos = BOTTOMRIGHT;
	else if (texture.Collider().position.x < 500 && texture.Collider().position.y < 300)
		currentPos = TOPLEFT;
	else if (texture.Collider().position.x < 500 && texture.Collider().position.y > 300)
		currentPos = BOTTOMLEFT;
	else if (texture.Collider().position.x > 500 && texture.Collider().position.y < 300)
		currentPos = TOPRIGHT;
}



// cast spell
void Player::CastSpell()
{
	if (mana.Current() <= 0) // not enough mana for casting spell
		return;

	switch (currentSpell)
	{
	case FIREBALL:
		spellFire = true;
		break;
	case THUNDERBOLT:
		spellThunder = true;
		break;
	case FROSTBOLT:
		spellFrost = true;
		break;
		// LOGIC
		break;
	}
}

// players swordarc is active
void Player::Attack()
{
	isAttacking = true;
}

// Blinks player based on direction, 
void Player::Blink(int direction, bool isYaxis)
{
	if(!canBlink)
		return;

	// up / down
	if(isYaxis)
	{
		if (texture.Collider().position.y + (blinkDistance * direction) < 0) // attempts to keep them in the screen
		{
			texture.Collider().position.y = 0;
		}
		else if (texture.Collider().position.y + (blinkDistance * direction)  > 800 - texture.Collider().height) // attempts to keep them in the screen
		{
			texture.Collider().position.y = 800 - texture.Collider().height;
		}
		else
			texture.Collider().position.y = texture.Collider().position.y + (blinkDistance * direction);

		if (direction > 0)
			lastKey = DOWNARROW;
		else
			lastKey = UPARROW;

		timer.Start(); // starts timer for blink cooldown
		canBlink = false; // disallows them to blink again
	}
	else // left / right
	{
		if (texture.Collider().position.x + (blinkDistance * direction)	< 0) // attempts to keep them in the screen
		{
			texture.Collider().position.x = 0;
		}
		else if (texture.Collider().position.x + (blinkDistance * direction) > 1000 - texture.Collider().width) // attempts to keep them in the screen
		{
			texture.Collider().position.x = 1000 - texture.Collider().width;
		}
		else
			texture.Collider().position.x = texture.Collider().position.x + (blinkDistance * direction);

		if (direction > 0)
			lastKey = RIGHTARROW;
		else
			lastKey = LEFTARROW;

		timer.Start(); // starts timer for blink cooldown
		canBlink = false; // disallows them to blink again
	}
	UpdateQuad();
}


void Player::SavePlayer(ofstream& oFile)
{
	oFile << health.Current() << endl;
	oFile << health.Max() << endl;
	oFile << goldAmount << endl;
	oFile << inventory.GetBombs() << endl;
	oFile << inventory.GetHPot() << endl;
	oFile << inventory.GetKeys() << endl;
	oFile << inventory.GetMaxSpace() << endl;

}

void Player::LoadPlayer(ifstream& oFile)
{
	int a, b, c, d, e, f;

	oFile >> a;
	oFile >> b;
	oFile >> goldAmount;
	oFile >> c;
	oFile >> d;
	oFile >> e;
	oFile >> f;

	health.Max(b);
	health.Current(a);
	inventory.UpdateBomb(c);
	inventory.UpdateHPot(d);
	inventory.UpdateKeys(e);
	inventory.SetMaxSpace(f - inventory.GetMaxSpace());
}

void Player::Refill()
{
	health.Current(0);
	health.Set(HEART_SIX,HEART_SIX);

	goldAmount = 0;
	inventory.Reset();
}
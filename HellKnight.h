// Class HellKnight
// v0.0.1
// Author : Stephen Roebuck
// Date : 21/09/2016
//
// Logic for the HellKnight boss
//
#pragma once
#include "Enemy.h"
#include "Player.h"

//
//	Hellknight boss
//
class HellKnight : public Enemy
{
private:
	bool isOffensive;

	bool exploded;
	Texture secondPhase;
	Texture firstPhase;
	Texture explodedDude;

	Timer phaseTimer;
	Timer immunity;
	int amountofChanges;


public:
	HellKnight(SDL_Renderer*);
	virtual void Attack();
	virtual void AIMove();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void HandleCollision(int, int);
};


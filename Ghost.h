// Author: Jeffherson Vega	
// Email:jeffhersonlim@gmail.com
//
// Last Update: 6/10/2016
// Version: 1.0.2
#pragma once
#include "Enemy.h"

//
//	Spooky Ghost
//
class Ghost : public Enemy
{
private:
	int direction;
	int Rng();
public:
	Ghost(SDL_Renderer*);
	virtual void Attack();
	virtual void AIMove();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void HandleCollision(int, int);
	virtual bool CheckAttack() { return true; }
	virtual Collider GetAttackSwing() { return texture.Collider(); }
};
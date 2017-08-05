// Author:Isaac Walsh
//
// 
// Updated: 9/30/2016
// Version 1.0.0
#pragma once
#include "Enemy.h"


class Goblin : public Enemy
{
private:
	int direction;
	int speedX, speedY, counter;
public:
	Goblin(SDL_Renderer*, Point);
	virtual void Attack();
	virtual void AIMove();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void HandleCollision(int, int);
	virtual bool CheckAttack() { return true; }
	virtual Collider GetAttackSwing() { return texture.Collider(); }
};
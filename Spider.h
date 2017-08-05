// Author: Micheal Nedantsis
// Email: mikecool1324@hotmail.com
// 
// Updated: 10-05-2016
// Version 1.0.0
#pragma once
#include "Enemy.h"


class Spider : public Enemy
{
private:
	int direction;
	int counter;
	int rotation;
	float angle;

	Point middlePoint;

public:
	Spider(SDL_Renderer*, Point);
	virtual void Attack();
	virtual void AIMove();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void HandleCollision(int, int);
	virtual bool CheckAttack() { return true; }
	virtual Collider GetAttackSwing() { return texture.Collider(); }
};
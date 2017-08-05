// Author: Jeffherson Vega	
// Email:jeffhersonlim@gmail.com
//
// Last Update: 6/10/2016
// Version: 1.0.2
#pragma once
#include "Enemy.h"
#include "Fireball.h"

//
//	FlyTrap's left vine
//
class LeftVine : public Enemy
{
private:
	int AI();
public:
	LeftVine();
	LeftVine(SDL_Renderer*);
	~LeftVine();

	virtual void Attack();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);
	static bool fireblast;
	void Draw(SDL_Renderer* r);


};

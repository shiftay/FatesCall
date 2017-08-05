// Author: Jeffherson Vega	
// Email:jeffhersonlim@gmail.com
//
// Last Update: 6/10/2016
// Version: 1.0.2
#pragma once
#include "Enemy.h"
#include "Fireball.h"

#include <vector>
using std::vector;

//
// Flytrap boss
//
class VenusFlyTrap : public Enemy
{
private:
	
public: 
	VenusFlyTrap();
	VenusFlyTrap(SDL_Renderer*);
	~VenusFlyTrap();

	virtual void Attack();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);
	void Draw(SDL_Renderer* r);

};




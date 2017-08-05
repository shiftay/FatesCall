#pragma once
#include "Enemy.h"


class Slime : public Enemy
{
private:
	int direction;
	int startPointX, startPointY;
public:
	Slime(SDL_Renderer*, Point);
	virtual void Attack();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);

};
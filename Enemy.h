// Author: Stephen Roebuck	
// Email: shroebuck@gmail.com
//
// Last Update: 9/28/2016
// Version: 1.0.1
#pragma once
#include "Actor.h"





//
//		Virtual class for holding the different type
//		of enemies
//
class Enemy : public Actor
{
protected:
	
public:


	virtual void Attack() = 0;
	virtual void AIMove() = 0;
	virtual void HandleEvents(SDL_Event*) = 0;
	virtual void HandleCollision(int, int) = 0;

};
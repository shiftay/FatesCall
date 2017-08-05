// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 4/10/2016
// Version: 1.0.1
#pragma once
#include "Room.h"
#include "Explosive.h"

//
//	Controls the room that boss spawns in
//
class Boss : public Room
{
private:
	Timer timer;
	// Fils active projectiles
	void FillProj(SDL_Renderer*, vector<Point>, int);
	// Blows up the projectiles manually
	void Explode();
public:
	Boss(SDL_Renderer*, BossType, int);

	virtual void Obstacles(SDL_Renderer*, Player*);
	virtual void Draw(SDL_Renderer*);
	virtual void HandleEvent(SDL_Event*) { return; }
};



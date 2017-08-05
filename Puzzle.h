// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 10/2/2016
// Version: 1.0.1
#pragma once

#include "Room.h"

class Puzzle : public Room
{
protected:
	void SetSpawn();

public:
	Puzzle(SDL_Renderer*, int);
	~Puzzle() {}

	void Obstacles(SDL_Renderer*, Player*);
	void Refill(SDL_Renderer*);
	virtual void Draw(SDL_Renderer*);
	virtual void HandleEvent(SDL_Event*) {}
};
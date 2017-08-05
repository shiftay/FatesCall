// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 10/4/2016
// Version: 1.0.1
#pragma once

#include "Room.h"
#include "Timer.h"

class Waves : public Room
{
protected:
	int waveEnemies;
	int counter;
	bool waveOneCompleted;
	bool waveTwoCompleted;
	void SpawnEnemies(SDL_Renderer*, vector<Point>);

public:
	Waves(SDL_Renderer*, int, vector<Point>);
	~Waves() {}

	virtual void Draw(SDL_Renderer*);
	virtual void Obstacles(SDL_Renderer*, Player*);
	virtual void HandleEvent(SDL_Event*) {}
};
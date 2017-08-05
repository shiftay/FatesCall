// Author: Vraj Patel
//
// Last Update: 05/10/2016
// Version: 1.0.1

#pragma once
#include "Room.h"

//
//	Locked Room to progress towards Boss
//
class Locked : public Room
{
private:
	vector<Collider> obstacles;
	Texture BossDoor;
	bool isLocked;
public:
	Locked(SDL_Renderer*, int);
	~Locked() {}
	virtual void Draw(SDL_Renderer*);
	virtual void Obstacles(SDL_Renderer*, Player*);
	virtual void HandleEvent(SDL_Event*) { return; }
};
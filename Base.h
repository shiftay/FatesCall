// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
//
// Last Update: 30/09/2016
// Version: 1.0.1

#pragma once
#include "Room.h"

//
//	The regular room within the game.
//
class Base : public Room
{
private:
	vector<Collider> obstacles;
	// Used to spawn enemies.
	void SpawnEnemies(vector<Point>); 

public:
	Base(SDL_Renderer*, int, vector<Point>); // Parameter helps specify which area.
	~Base() {}
	virtual void Draw(SDL_Renderer*);
	virtual void Obstacles(SDL_Renderer*, Player*) { return; }
	virtual void HandleEvent(SDL_Event*) { return; }
};
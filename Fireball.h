// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-28
// Version: 1.0.2
// SHR - change constructor to take a TYPE
#pragma once

#include <iostream>
#include "Projectile.h"

using std::cout;

// Fireball will be any fire move in the game used by the player
// enemies and the bosses. It will be an AOE shaped like a square.
class Fireball : public Projectile
{
private:
	Texture aoe;
	bool exploded;

public:
	virtual void Move();

	Fireball();
	~Fireball();

	Fireball(SDL_Renderer*, int);

	void FBAOEffect();
	bool IsExploded() { return exploded; }
	virtual void HandleCollision(int, int);

};
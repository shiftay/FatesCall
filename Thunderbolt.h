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

// Thunderbolt can be used by the player, enemies,and bosses.
// It will be a single unit damaging spell.
class Thunderbolt : public Projectile
{
private:
	bool exploded;

public:
	virtual void Move();

	Thunderbolt();
	~Thunderbolt();

	Thunderbolt(SDL_Renderer*, int);
	void Thunderboom();

	virtual bool IsExploded() { return false; }
	virtual void HandleCollision(int, int);
};
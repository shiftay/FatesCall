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

// Frostbolt can be used by the player, enemies,and bosses.
// It will be a single unit damaging spell.
class Frostbolt : public Projectile
{
private:
	bool exploded;

public:
	virtual void Move();

	Frostbolt();
	~Frostbolt();

	Frostbolt(SDL_Renderer*, int);
	void Freeze();

	virtual bool IsExploded() { return false; }
	virtual void HandleCollision(int, int);

};
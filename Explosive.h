// Author: Giane Carlo
// Explosives
// Date : 10/4/2016
//
// Version : 0.0.1
// 

#pragma once
#include "Projectile.h"

//
//	Used for placing bombs
//
class Explosive : public Projectile
{
private:
	Texture explosion;
	bool exploded;

public:
	Explosive(SDL_Renderer*, Point, int);

	virtual void HandleCollision(int, int) { }
	virtual bool IsExploded() { return exploded; }
	virtual void Move();
};
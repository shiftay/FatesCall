// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-28
// Version: 1.0.2
// SHR - change constructor to take a TYPE
#pragma once
#include "Enemy.h"
#include "Fireball.h"
#include "Player.h"

#include <iostream>

using std::cout;

// Boss Dragon
class Dragon : public Enemy
{
private:
//	int counter;

	Texture handtexture;
	Texture rhandtexture;
	Texture flyingmeme;
	Timer leftTime;
	Timer rightTime;
	Timer phase2timer;
	int handdmg;
	int handspd;
	int travel;
	int direction;
	bool leftGoingDown;
	bool rightGoingDown;
	bool leftCanMove;
	bool rightCanMove;
	void Hide();
	void Show();


public:
	Dragon();
	~Dragon();

	Dragon(SDL_Renderer*);
	void Draw(SDL_Renderer*);
	void MoveLeft();
	void MoveRight();
	virtual void Attack() {}
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);

	static bool phase2;
	static int counter;
};
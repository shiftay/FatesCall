// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-09-29
// Version: 1.0.2
// SHR  added direction / yAxis for
//		later calculation
#pragma once 
#include "Texture.h"
#include "Timer.h"


class Projectile
{
protected:
	Texture texture;
	Timer timer;
	int speed;
	int dmg;
	int type;
	int range;
	int travel;
	int direction;
	bool yAxis;

public:
	virtual void Move() = 0;

	Projectile();
	~Projectile();

	// Accessors and Mutators
	inline int GetDmg() const 					{ return dmg; }
	inline int GetType() const 					{ return type; }
	inline int GetRange() const 				{ return range; }
	inline int GetSpeed() const					{ return speed; }
	Texture* GetTexture()						{ return &texture; }
	inline int GetTravel() const				{ return travel; }
	Timer* GetTimer()							{ return &timer; }


	inline void SetDmg(const int newVal) 		{ dmg = newVal; }
	inline void SetType(const int newVal)		{ type = newVal; }
	inline void SetRange(const int newVal)		{ range = newVal; }
	inline void SetSpeed(const int newVal)		{ speed = newVal; }
	inline void SetDirection(const int newVal)  { direction = newVal; }
	inline void SetAxis(bool newVal)			{ yAxis = newVal; }

	virtual void HandleCollision(int, int) = 0;
	virtual bool IsExploded() = 0;
};
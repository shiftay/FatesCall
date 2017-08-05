// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
//
// Last Update: 30/09/2016
// Version: 1.0.1

#pragma once
#include "Player.h"
#include "Skeleton.h"
#include "Slime.h"
#include "Ghost.h"
#include "Spider.h"
#include "Goblin.h"
#include "HellKnight.h"
#include "VenusFlyTrap.h"
#include "LeftVine.h"
#include "RightVine.h"
#include "LeftHand.h"
#include "RightHand.h"
#include <vector>

using std::vector;

enum DoorUsed
{
	NONE,
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum BossType
{
	HELLKNIGHT,
	DRAGON,
	FLYTRAP
};

class Room
{
protected:	
//	int area;
	vector<Actor*> activeUnits;

	vector<Texture> Doors;

	DoorUsed currentDoor;
	Texture backGround;
	vector<Collider> exits;
	Point playerSpawn;
	// Methods for filling exits
	Collider FillNorth(SDL_Renderer*);
	Collider FillSouth(SDL_Renderer*);
	Collider FillEast(SDL_Renderer*);
	Collider FillWest(SDL_Renderer*);
	vector<Projectile*> proj;

public:
	~Room();
	// Accessor
	vector <Actor*> ActiveUnits() { return activeUnits; }
	vector<Projectile*> GetProjectiles() { return proj; }
	vector<Collider> Exits() { return exits; }
	inline DoorUsed GetDoor() { return currentDoor; }
	inline void SetDoor(DoorUsed newVal) { currentDoor = newVal; }
	void EraseUnit(int);


	// Other methods
	void FillExits(SDL_Renderer*);
	virtual void Obstacles(SDL_Renderer*, Player*) = 0;
	virtual void Draw(SDL_Renderer*) = 0;
	virtual void HandleEvent(SDL_Event*) = 0;
};
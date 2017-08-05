// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 29/09/2016
// Version: 1.0.1
#pragma once
#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Room.h"
#include "Item.h"

class CollisionDetection
{
private:
	// Checks the collision
	bool IsCollision(Collider, Collider);
	// Handles the collisions of the actors
	void HandleActors(vector<Actor*>, Player*);
	// Handles the collision with doors
	void HandleDoors(Room*, Player*);
	// Handles the collisions with projectiles
	void CheckProjectiles(vector<Projectile*>, vector<Actor*>, Player*);
	// Handles the collision with items
	void HandleItems(vector<Item*>, Player*);

public:
	void HandleEvents(vector<Projectile*>,vector<Projectile*>, vector<Actor*>, Room*, vector<Item*>, Player*);

};

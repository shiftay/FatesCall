// Author: Stephen Roebuck	
// Email: shroebuck@gmail.com
//
// Last Update: 9/28/2016
// Version: 1.0.1

#pragma once
#include "Texture.h"
#include "Proportion.h"
#include "Timer.h"
#include <string>
#include <vector>

using std::vector;
using std::string;
// enum to hold type of player
enum ActorType
{
	PLAYER = 1,
	ENEMY
};

// enumeration to help hold the status effects
enum StatusEffect
{
	STATUS_NEUTRAL,
	STATUS_FROZEN,
	STATUS_STUNNED,
	STATUS_POISONED
};

// Holder for spells
enum Spells
{
	FIREBALL,
	FROSTBOLT,
	THUNDERBOLT
};

// Hearts for holding how much health each person has
// Each heart value inside represents 0.5 health
// HEART_ONE = 0.5 health
// HEART_TWO = 1 health.
// etc..
enum Hearts
{
	HEART_ONE = 1,
	HEART_TWO,
	HEART_THREE,
	HEART_FOUR,
	HEART_FIVE,
	HEART_SIX,
	HEART_SEVEN,
	HEART_EIGHT,
	HEART_NINE,
	HEART_TEN,
};

// might need enum for type.
enum EnemySize
{
	SMALL_NME,
	MEDIUM_NME,
	LARGE_NME,
	BOSS_NME
};
//
//	Actor is responsible to hold all types of NPCs in the game.
//
class Actor
{
protected:
	int speed;
	int dmg;
	int status;			// holder for status effects on the individual
	Proportion health;
	Proportion mana;
	string name; 
	Texture texture;	// holds the image for the various actors in the game
	Timer timer;		// used for timing invuln frames etc...
	int type;			// Player OR Enemy
	int size; 			// used to delimit what type of enemy.
	bool canBeDamaged;	// For immunity frames.
	bool isActive;		// so when not drawn it wont affect collision
	bool isFlying;


	vector<int> spellBook;
	vector<Point> potentialSpawns;
	vector<Point> enemySpawns;

public:
	//Accessors
	inline const int Size() { return size; }
	inline bool IsFlying() { return isFlying; }
	inline const int Type() { return type; }
	inline bool IsActive() { return isActive; }
	inline Proportion& Health() { return health; }
	inline Proportion& Mana() { return mana; }
	inline const string Name() const { return name; }
	inline const int GetDamage() const { return dmg; }
	inline const int GetSpeed() const { return speed; }
	Texture* GetTexture() { return &texture; }
	vector<Point> GetSpawns() { return potentialSpawns; }
	vector<Point> NMESpawns() { return enemySpawns; }
	// Determines if the enemy is dropping something
	int DetermineDrop();
	// Checks if the Actor is alive.
	bool IsAlive();


	// Mutators
	inline void SetName(string newVal) { name = newVal; }
	inline void SetDamage(int newVal) { dmg = newVal; }
	virtual void HandleEvents(SDL_Event*) = 0;
	virtual void AIMove() = 0;
	virtual void HandleCollision(int,int) = 0;
};
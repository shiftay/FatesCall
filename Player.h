//
//	Player v0.0.1
//The creator for a player object.
#pragma once
#include <fstream>

#include "Actor.h"
#include "Inventory.h"
#include "Minimap.h"
//#include "Item.h"
#include "Fireball.h"
#include "Frostbolt.h"
#include "Thunderbolt.h"
#include "Explosive.h"
#include "AudioManager.h"

using std::ofstream;
using std::ifstream;
using std::endl;

// Used to track the last direction press
enum LastDirectionPressed
{
	UPARROW,
	DOWNARROW,
	LEFTARROW,
	RIGHTARROW
};
// Used to track what Quadrant the player is in.
enum CurrentQuadrant
{
	TOPLEFT,
	TOPRIGHT,
	BOTTOMLEFT,
	BOTTOMRIGHT
};

// 
//	Object that the player controls for the entirety
//	of the game
//
class Player : public Actor
{
private:
	int goldAmount;
	int blinkDistance;
	int currentSpell;
	int currentItem;
	bool canBlink;
	bool canBeDamaged;
	Inventory inventory;
	// Optional
	Collider swordArc;
	bool isAttacking;

	void CastSpell();
	void Attack();
	void Move(int, bool); 
	void Blink(int, bool);

	void CycleSpells();
	void CycleInventory();
	void UpdateQuad();

	void UseItem();

	vector<Projectile*> ActiveProj;
	

public:
	Player() {};
	Player(SDL_Renderer*);
	// Mutators / Accessors
	inline void BuySomething(const int newVal) { goldAmount -= newVal; }
	inline void GainGold(const int newVal) { goldAmount += newVal; }
	inline void Damaged(const int newVal) { health -= newVal; }
	inline void Healed(const int newVal) { health += newVal; }

	inline int GetCurrentSpell() { return currentSpell; }
	inline int GetCurrentItem() { return currentItem; }

	inline const int Gold() const { return goldAmount; }
	inline bool CanBlink() { return canBlink; }
	inline Inventory& GetInventory() { return inventory; }
	vector<Projectile*>& GetProjectiles() { return ActiveProj; }

	void PlayerProjectiles(SDL_Renderer*);

	void Refill();

	// Functionality
	//inline bool IsAlive();

	virtual void AIMove() {}
	void HandleCollision(int);
	virtual void HandleCollision(int, int);
	void HandleEvents(SDL_Event*);


	//STATIC VARIABLES FOR TRACKING SPELLCASTS AND MOVEMENT
	static LastDirectionPressed lastKey;
	static CurrentQuadrant currentPos;
	static bool spellFire;
	static bool spellThunder;
	static bool spellFrost;
	static bool doorUsed;
	static Minimap Player::testMinimap;
	static int DiceRoll(int, int);
	static bool isBombPlaced;
	static bool isInteracting;

	void LoadPlayer(ifstream&);
	void SavePlayer(ofstream&);




};
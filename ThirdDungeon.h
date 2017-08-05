// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 5/10/2016
// Version: 1.0.2
#pragma once

#include "GameState.h"
#include "StateManager.h"
#include "CollisionDetection.h"

#include "Potion.h"
#include "Bomb.h"
#include "Gold.h"
#include "Food.h"
#include "Locked.h"

#include "Minimap.h"
#include "Base.h"
#include "Boss.h"
#include "Puzzle.h"
#include "Shop.h"
#include "Waves.h"


class ThirdDungeon : public GameState
{
	//=====================================================
	//	Properties
	//=====================================================
private:
	Player* testP;
	CollisionDetection testCollision;
	vector<Item*> ActiveItems;
	Room* current_room;

	bool isinBossR;
	int area;

	Timer loading;
	Texture loadingScreen;

	// PRIVATE METHODS
	void MoveEnemies(SDL_Renderer*);
	void CheckActiveItems();
	void ChangeRoom(SDL_Renderer*);

	//====================================================
	//	Behaviours
	//====================================================
public:
	ThirdDungeon() {}
	~ThirdDungeon() {}

	virtual void Init(ScreenUtil* w, Player*);

	virtual void Clean();

	virtual void HandleEvents(SDL_Event* event);

	virtual void Update(ScreenUtil* w);

	virtual void Render(ScreenUtil* w);
};
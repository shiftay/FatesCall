// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
//
// Last Update: 28/9/2016
// Version: 1.0.1

#pragma once
#include "Player.h"
#include "RenderTarget.h"
#include "RenderingEngine.h"
#include "StateManager.h"
#include "HUD.h"
#include "Button.h"

#include <fstream>

using std::ifstream;
using std::ofstream;


//
//	Used to control the main game loop
//
class GameEngine
{
private:
	RenderingEngine renderingEngine;

	GameStateManager game_state_manager_;

	HUD* hud;
	Button* quit;
	Button* resume;
	Button* save;


	SDL_Event event;

	bool isRunning;

	Player* testPlayer;

	bool isPaused;

	bool Init();
	void Clean();
	void HandleEvents();
	void Render();
	void Paused(SDL_Event*);

	void Save();


public:
	GameEngine();
	~GameEngine() {};

	void GameLoop();

};








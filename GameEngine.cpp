#include "GameEngine.h"

GameEngine::GameEngine()
{
	isRunning = true;

}

void GameEngine::GameLoop()
{
	//Initializes the GameEngine object
	if (!Init())
	{
		//GameEngine failed to init()
		cout << "GameEngine initialization failed" << endl;
	}

	while (isRunning)
	{
		 // GAME LOGIC
		if (GameStateManager::isNewState())
		{
			//Init Active GameState
			game_state_manager_.Init(&renderingEngine.getWindow(), testPlayer);
		}



		while (SDL_PollEvent(&event))
		{
			HandleEvents();
		}
		if (!isPaused)
		{
			//Update Logic
			game_state_manager_.Update(&renderingEngine.getWindow());
		}
		else
		{

		}
		Render();
	}
}

bool GameEngine::Init()
{
	if (!renderingEngine.Init())
	{
		cout << "Failure to initialize RenderingEngine! @GameEngine::Init()" << endl;
		return false;
	}

	hud = new HUD(renderingEngine.getRenderer());
	testPlayer = new Player(renderingEngine.getRenderer());

	int center_x_of_texture;
	string str = "RESUME";
	string str2 = "QUIT";
	string str3 = "SAVE";

	SDL_Color textColor = { 255, 0, 0, 255 };
	int center_x_of_window = (int)floor(renderingEngine.getWindow().getWidth() * 0.5);//*
	int window_height_one_eighth = (int)floor(renderingEngine.getWindow().getHeight() * 0.125);//*


	resume = new Button(renderingEngine.getRenderer(), str, textColor);
	center_x_of_texture = (int)floor(resume->getBoundingBox().w * 0.5);//*
	resume->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 2);

	save = new Button(renderingEngine.getRenderer(), str3, textColor);
	center_x_of_texture = (int)floor(save->getBoundingBox().w * 0.5);//*
	save->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 4);

	quit = new Button(renderingEngine.getRenderer(), str2, textColor);
	center_x_of_texture = (int)floor(quit->getBoundingBox().w * 0.5);
	quit->setPosition(center_x_of_window - center_x_of_texture, window_height_one_eighth * 6);


	isPaused = false;

	GameStateManager::setCurrentState(GAMESTATE_MAINMENU);

	return true;
}

void GameEngine::Clean()
{
	renderingEngine.Clean();
	isRunning = false;
}

void GameEngine::HandleEvents()
{
	switch (event.type)
	{
	case SDL_QUIT:
		GameStateManager::setCurrentState(-1);
		Clean();
		break;
	case SDL_KEYDOWN:
		if(event.key.keysym.sym == SDLK_ESCAPE)
		{
			isPaused = true;
		}
		break;
	}
	if (isPaused)
	{
		resume->HandleEvents(&event);
		quit->HandleEvents(&event);
		save->HandleEvents(&event);
		Paused(&event);
	}
	renderingEngine.getWindow().HandleEvents(&event);


	game_state_manager_.HandleEvents(&event);

	if((int)game_state_manager_.getStateType() == -1)
	{
		//Exit Application
		Clean();
	}

}

void GameEngine::Paused(SDL_Event* event)
{
	if (isPaused)
	{
		if (resume->getState() == CLICKED)
		{
			isPaused = false;
			return;
		}

		if(save->getState() == CLICKED)
		{
			Save();
			return;
		}

		if (quit->getState() == CLICKED)
		{
			SDL_Event quit;
			quit.type = SDL_QUIT;
			isPaused = false;
			SDL_PushEvent(&quit);
			return;
		}
	}
}


void GameEngine::Render()
{
	renderingEngine.Begin();
	if (GameStateManager::gameplaystarted)
	{
		if (!isPaused)
		{
			game_state_manager_.Render(&renderingEngine.getWindow());

			hud->Init(renderingEngine.getRenderer(), testPlayer->GetCurrentSpell(), testPlayer->GetCurrentItem(), testPlayer->Gold(), testPlayer->GetInventory().GetKeys(), testPlayer->Health().Current(), testPlayer->GetInventory());

			Player::testMinimap.DrawMap(renderingEngine.getRenderer());
		}
		else
		{
			RenderingEngine::DrawTexture(renderingEngine.getRenderer(), resume->getTexture(), resume->getBoundingBox().x, resume->getBoundingBox().y);
			RenderingEngine::DrawTexture(renderingEngine.getRenderer(), save->getTexture(), save->getBoundingBox().x, save->getBoundingBox().y);
			RenderingEngine::DrawTexture(renderingEngine.getRenderer(), quit->getTexture(), quit->getBoundingBox().x, quit->getBoundingBox().y);
		}
	}
	else
	{
		game_state_manager_.Render(&renderingEngine.getWindow());
	}

	renderingEngine.End();
}

void GameEngine::Save()
{
	ofstream oFile("resources\\savedPlayer.txt");
	if(oFile)
	{
		testPlayer->SavePlayer(oFile);
	}
	else
	{
		cout << "Saving failed";
	}
	oFile.close();

	ofstream oFile2("resources\\savedLocation.txt");
	if(oFile2)
	{
		oFile2 << GameStateManager::getStateType();
	}
	else
	{
		cout << "Saving Failed";
	}

}
// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#include "RenderingEngine.h"

bool RenderingEngine::Init()
{
	//Initializes the SDL Library and checks to ensure there were no errors
	//during the creation of the game window
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL_Init Failer @RenderingEngine::Init()" << endl;
		return false;
	}

	//Initializes the SDL_image extension library and chech to ensure there
	//were no errors during the process
	if((IMG_Init(IMG_INIT_PNG)& IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cout << "IMG_Init Failed @RenderingEngine::Init()" << endl;
		return false;
	}

	//INitializes the SDL_ttf extension library and check to ensure there
	//were no errors during the process
	if(TTF_Init() == -1)
	{
		cout << "TTF_Init Failed @RenderingEngine::Init()" << endl;
		return false;
	}


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "SDL_mixer could not initialize! %s\n"	<< Mix_GetError() << "\n";
	}

	//Initializes the WindowManager
	window_manager_.Init();

	//INitializes the RenderTarget
//	scene_ = RenderTarget(window_manager_.getRenderer(), window_manager_.getWidth(), window_manager_.getHeight());

	return true;
}
	//Sets scene_ as RenderTarget and Cleats the Renderer
void RenderingEngine::Begin()
{
//	scene_.AcquireRenderTarget(window_manager_.getRenderer());
	SDL_RenderClear(window_manager_.getRenderer());
}

//Safely destroys the current scene_::ptr_texture instance, then creates new a 
//instance. Finally, places the renderer onto the window
void RenderingEngine::End()
{
	
//	scene_.Reset(window_manager_.getRenderer(), window_manager_.getWidth(), window_manager_.getHeight());
	SDL_RenderPresent(window_manager_.getRenderer());
}

void RenderingEngine::Clean()
{
	//Quit SDL_TTF Subsystem
	TTF_Quit();

	//Quit SDL_image Subsystem
	IMG_Quit();

	//Quit SDL System
	SDL_Quit();
}

SDL_Texture* RenderingEngine::LoadTexture(SDL_Renderer* r, string imgLocation)
{
	SDL_Texture *newTexture = IMG_LoadTexture(r, imgLocation.c_str());

	//
	//Checks to ensure there were no errors during the creation of the SDL_Texture
	//
	if(newTexture == nullptr)
	{
		//TODO: Handle ERROR
	}

	return newTexture;
}

void RenderingEngine::DrawTexture(SDL_Renderer* r, SDL_Texture *tex, int x, int y, int w, int h)
{
	//If width and height are not passed in, they must be
	//determined prior to drawing
	if (w==0 && h==0)
	{
		//SDL_QueryTexture is used to quwery the attributes of a texture
		//IN the case below, the width and height properties of the texture
		//are stored within w and h, so that the values can
		//then be stored within the destination rectangle below and passed
		//into SDL_RenderCopy/
		SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	}

	// Declare and instantiate pointer to SDL_Rect
	SDL_Rect dst = {x, y, w, h};

	//Draw texture to renderer
	SDL_RenderCopy(r, tex, NULL, &dst);
}

//Creates an SDL_Texture from text string
SDL_Texture* RenderingEngine::CreateTextureFromString(SDL_Renderer* r, const string& text, const SDL_Color& textColor, TTF_Font* font)
{
	//The methods provided by SDL_ttf's extension library return an SDL_Surface,
	//however for the purposes of this application SDL_Texture's are the 
	//preferred type for images. Fortunately converting from an SDL_Surface to
	//SDL_Texture is as simple as invoking SDL_CreateTextureFromSurface.

	//Stores the location in memory of SDL_Surface reutrned by TTF_RenderText_Blended
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);

	//Pointer to and SDL_Texture which will be used to store the textSurface
	//Image once it has been converted to and SDL_Texture type/
	SDL_Texture* finalTex = nullptr;

	//Create texture from surface pixels
	finalTex = SDL_CreateTextureFromSurface(r, textSurface);

	if(finalTex == nullptr)
	{
		cout << "Unable to create texture from rendered text! SDL Error." << SDL_GetError() << endl;
	}

	//Get rid of old surface
	SDL_FreeSurface(textSurface);

	//Returns success
	return finalTex;
}

// Calls SDL_DestroyTexture on tex argument, then sets the 
// value of the ref to pointer to nullpter. So that the
// pointer no longer points to the freed location in memory
void RenderingEngine::DestroyTexture(SDL_Texture*& tex)
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

//Calls SDL_DestroyTexture on tex argument, then sets the 
//value of the ref to pointer to nullptr, So that the 
//pointer no longer points to the freed location in memory
void RenderingEngine::DestroyTexture(TextureBB*& tex)
{
	if(tex)
	{
		SDL_DestroyTexture(tex->tex);	//Safely release the texture from memory
		tex->tex = nullptr;				//Good Pointer Convention
		tex = nullptr;					//Good Pointer Convention
	}
}
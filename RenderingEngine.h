// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#pragma once

#include <iostream>

#include "ScreenUtil.h"
//#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
using std::string;
using std::cout;
using std::endl;

//Convenient struct which pairs to a pointer to an SDL_Texture with an SDL_Rect
//to serve as the texture's bouding box. (See Button.h/Button.cpp)
typedef struct TextureBB
{
public:
	//Pointer to SDL_Texture
	SDL_Texture* tex;

	//Stores the position (x,y) and dimensions (w,h) of tex
	SDL_Rect dimensions;

	//Default Constructors; gives member properties default values
	TextureBB() : tex(nullptr)
	{
		dimensions.x = 0;
		dimensions.y = 0;
		dimensions.h = 0;
		dimensions.w = 0;
	}

} TextureBB;


//The RenderingEngine encapulates the 
//
//
class RenderingEngine
{
//==========================================================
//			Properties			//
//==========================================================

private:
		// Holds an instance of an SDL_Window and SDL_Renderer object.
		// Manages the applicaton window, including events.
	ScreenUtil window_manager_;	//Application Window

//==========================================================
//			Behaviours			//
//==========================================================
public:
	RenderingEngine() {};
	~RenderingEngine() {};

	//INitializes the SDL system, SDL_img & SDL_ttf extention library
	//Constructs the WindowManager object and the RenderTarget
	bool Init();

	//Uploads SDL SubSystems, Frees Associated Memory
	void Clean();

	//Pre-Rendering operation, needs to be called before any draw operataions
	//each frame/tick.
	void Begin();

	//Draws scene_ to the screen
	void RenderScene();

	//Post-rendering operation, needs to be called after all draw operations
	//for each frame/tick
	void End();

	//Accessor method for window_manager
	inline ScreenUtil& getWindow() { return window_manager_; }

	//Accessor method for window_manager_.getRenderer()
	inline SDL_Renderer* getRenderer() { return window_manager_.getRenderer(); }
//
//	Static Rendering Opeations
//
	//Creates and SDL_Texture based on the passed in string and font.
	//	@param text The string sequence to be converted into a textre
	//	@param textColor the color value (RGB) of the text.
	//	@parm font the font used to render @param text
	static SDL_Texture* CreateTextureFromString(SDL_Renderer* r, const string& text, const SDL_Color& textColor, TTF_Font* font);

	// LOads an external image file and converts it into an SDL_Texture
	//	@param r Pointer to the Renderer
	//	@param imgLocation the location on disk of the image to be loaded
	static SDL_Texture* LoadTexture(SDL_Renderer* r, string imgLocation);
	
	//Draws texure to current render target. (scene_ by default)
	//	@param tex Pointer to Texture to be drawn
	//	@param x X Position on Screen
	//	@param y Y Position on Screen
	//	@param w Width of Texture {Optional}
	//	@param h Height of Texture {Optional}
	static void DrawTexture(SDL_Renderer* r, SDL_Texture* tex, int x, int y, int w = 0, int h = 0);

	//Safely destroys an SDL_Texture object and sets the reference to the 
	//argument to nullptr
	//	@param tex Texture to free from memory {Ref to Pointer}
	static void DestroyTexture(SDL_Texture*& tex);


	//Safely destroys an TextureBB object and sets the reference to the 
	//argument to nullptr
	//	@param tex Texture to free from memory {Ref to Pointer}
	static void DestroyTexture(TextureBB*& tex);
};
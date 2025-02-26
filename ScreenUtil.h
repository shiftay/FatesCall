#pragma once

#include <SDL.h>
#include <iostream>

using std::cout;
using std::endl;

class ScreenUtil
{
private:
	SDL_Window* ptr_app_window_;
	SDL_Renderer* ptr_renderer_;

	//Value in pixels of the window's width.
	int width_;

	//Value in pixels of the windows height
	int height_;

	// Used to track whether or not the window has mouse focus
	bool is_mouse_focused_;

	// Used to track whether or not the window has keyboard focus
	bool is_keyboard_focused_;

	//Used to track whether or not the window is fullscreen
	bool is_fullscreen_;

public:
	//Initializes properties to default values, pointers are set to nullptr
	ScreenUtil();
	~ScreenUtil();

	// Creates the application window for SDL and the 2D rendering
	// context for the window. Also responsible for setting renderer
	// scale quality.
	bool Init();

	//Processes all events of type SDL_WINDOWEVENT
	void HandleEvents(SDL_Event* event);

	//Accessors
	inline int getWidth() const				 { return width_; }
	inline int getHeight() const			 { return height_; }
	inline bool isMouseFocused() const	     { return is_mouse_focused_; }
	inline bool isKeyboardFocused() const	 { return is_keyboard_focused_; }
	inline SDL_Window* getWindow() const	 { return ptr_app_window_; }
	inline SDL_Renderer* getRenderer() const { return ptr_renderer_; }
};
#include "ScreenUtil.h"

ScreenUtil::ScreenUtil()
{
	ptr_app_window_ = nullptr;
	ptr_renderer_ = nullptr;

	is_mouse_focused_ = false;
	is_keyboard_focused_ = false;
	is_fullscreen_ = false;
	width_ = 1000;
	height_ = 800;
}

ScreenUtil::~ScreenUtil()
{
	SDL_DestroyRenderer(ptr_renderer_);
	SDL_DestroyWindow(ptr_app_window_);

	is_mouse_focused_ = false;
	is_keyboard_focused_ = false;
	is_fullscreen_ = false;
	width_ = 0;
	height_ = 0;
}


bool ScreenUtil::Init()
{
	// Creates an application window for SDL.
	ptr_app_window_ = SDL_CreateWindow(
		"Untitled Project",							//Window Title(UTTF-8encoding)
		25,											// Initial X position of window
		40,											// Initial Y position of window
		width_,										// Windows width in pixels
		height_,									// Windows height in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);	// Flags

	// nullptr check
	if (!ptr_app_window_)
	{
		cout << "Error Trying to Create Window!" << SDL_GetError() << endl;
	}
	else
	{
		is_mouse_focused_ = true;
		is_keyboard_focused_ = true;
	}

	//Creates a 2D rendering context for a window.
	ptr_renderer_ = SDL_CreateRenderer(
		ptr_app_window_, // The window
		-1, //The index value fo the rendering driver to initialize, or -1 to initialise the first one supporting the requested flags
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE); // Flags

	//null ptr check
	if (!ptr_renderer_)
	{
		cout << "Error Trying to Create Renderer!" << SDL_GetError() << endl;
		return false;
	}
	//smoothed scale rendering
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	return true;
}

// Handles all SDL_WINDOWEVENT events
void ScreenUtil::HandleEvents(SDL_Event* event)
{
	if (event->type == SDL_WINDOWEVENT)
	{

		switch (event->window.event)
		{
			//Get new Dimensions and repaint on window size change
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			width_ = event->window.data1;
			height_ = event->window.data2;
			SDL_RenderPresent(ptr_renderer_);
			break;

			//Repaint on exposure
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(ptr_renderer_);
			break;

			// Mouse Entered window
		case SDL_WINDOWEVENT_ENTER:
			is_mouse_focused_ = true;
			break;

			// Mouse Left window
		case SDL_WINDOWEVENT_LEAVE:
			is_mouse_focused_ = false;
			break;

			// Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			is_keyboard_focused_ = true;
			break;

			//Window has lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			is_keyboard_focused_ = false;
			break;
		}
	}
}

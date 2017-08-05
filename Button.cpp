// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#include "Button.h"

// Attempts to load Button font external resource, on success the Button
// texture is generated and it's bounding box filled with the appropriate
// values. On failure of trying to load the button font an error message
// is displayed with invokes SDL_GetError() for optimum error reporting
Button::Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize) 	// Tracks the current buttonState
{

	ptr_font_ = nullptr;
	current_state_ = NORMAL;

	// Try and load font first in event of failure
	ptr_font_ = TTF_OpenFont("resources/HUD/Sans.ttf", fontSize);

	if(ptr_font_ == nullptr)
	{
		cout << "ERROR @ TTF INIT" << SDL_GetError() << endl;
	}

	// Generate texture from string
	label_texbb_.tex = RenderingEngine::CreateTextureFromString(r, label, textColor, ptr_font_);

	//Fill the values of label_texbb_'s bounding box
	GenerateBoundingBox(label_texbb_);
}

Button::~Button()
{
	TTF_CloseFont(ptr_font_);
	ptr_font_ = nullptr;
}

//Listens for SDL_MOUSEMOTION, SDL_MOUSEBUTTONDOWN and SDL_MOUSEBUTTONUP
// events only. Based on the processed event the Button's state may change.
void Button::HandleEvents(SDL_Event* event)
{
	if(current_state_ != NORMAL)
	{
		current_state_ = NORMAL;
	}

	switch (event->type)
	{
	case SDL_MOUSEMOTION:
		//onHover
		if(isInsideRect(label_texbb_.dimensions, event->motion.x, event->motion.y))
		{
			current_state_ = HOVERING;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		// onClick
		if( isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y))
		{
			current_state_ = CLICKED;
#ifdef DEBUG
			cout << "Button Clicked" << endl;
#endif
		}
		break;
	case SDL_MOUSEBUTTONUP:
		//on Release
		if (isInsideRect(label_texbb_.dimensions, event->button.x, event->button.y))
		{
			current_state_ = RELEASED;
#ifdef DEBUG
			cout << "Button Released" << endl;
#endif
		}
		break;
	}
}

//Uses SDL_QueryTexture method to determine the width and height of the
// texture. All Button objects, by default, are initialized to the
// position of (0,0)
void Button::GenerateBoundingBox(TextureBB& texbb)
{
	int w, h;
	SDL_QueryTexture(texbb.tex, NULL, NULL, &w, &h);

	label_texbb_.dimensions.x = 0; // X Position on screen
	label_texbb_.dimensions.y = 0; // Y position on screen
	label_texbb_.dimensions.w = w; // Width of Texture
	label_texbb_.dimensions.h = h; // Height of Texture

}

// Determines if a given 2D point(x,y) falls within the specified rectangle
// For Example:
//	Given a rectangle with position of (0,0) and width and height of 50.
//	And given a point with position fo (15,25). If 15 is greater than 0 and
//	15 is less than 0+50 and 25 is greater than 0 and 25 is less than 0+50 -
//  our point is inside the rectangle.
bool Button::isInsideRect(const SDL_Rect& rect, const int x, const int y) const
{
	if( x > rect.x && x < rect.x+rect.w && y > rect.y && y < rect.y + rect.h)
	{
		return true;
	}
	else
	{
		return false;
	}
}


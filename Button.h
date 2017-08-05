// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#pragma once

#include "RenderingEngine.h"

//Convenient enumaration type used to represent the current state of the
// Button object. There are a total of four possible states for a button.
enum ButtonState
{
	// Normal is the active state if the conditions for Hovering, clicked
	// and Released are not met.
	NORMAL=0,

	// Hovering is the active state when the mouse cursor's (x,y) position
	// is within the Button's bounding box.
	HOVERING,

	// clicked is teh active state when the mouse cursors(x,y) position
	// is within the buttons bounding box during SDL_MOUSEBUTTONDOWN event.
	CLICKED,

	//Released is the active state when the cursors(x,y) position
	// is within the button's bounding box during an SDL_MOUSEBUTTONUP event
	// typicall the released state follows the clicked state.
	RELEASED,
};



// The button object is a simple Graphical User Interface(GUI) component
class Button
{
//===========================================================================
//				Properties
//===========================================================================
private:
	// Pointer to the Button object's font, used to convert text into an SDL_Texture
	TTF_Font* ptr_font_;

	//A struct with a pointer to an SDL_Texture and a pointer to an SDL_Rect
	// which serves as the texture bounding box.
	TextureBB label_texbb_;

	//Stores the current buttonState(NORMAL,HOVERING,CLICKED,RELEASED)
	ButtonState current_state_;

//===========================================================================
//				Behaviors
//===========================================================================
	//Fills in the appropriate values for the textures bounding box.
	//	@param textbb is a struct composed of a pointer to the SDL_Texture to
	//	generate a bounding box for as well as an SDL_Rect used to store the
	//	bounding box data.
	void GenerateBoundingBox(TextureBB& textbb);

	//Determines if a given 2D point(x,y) falls within the specified rectangle
	//	@param rect The recatnagle to perform the comparison against
	//	@param x The position fot he point to test on the x-axis
	//	@param y The position for the point to test on the y-axis
	//	@return true if the x and y fall within the rect
	//	@return false if the x and y DO NOT fall within the rect
	bool isInsideRect(const SDL_Rect& rect, const int x, const int y) const;

public:
	//Default CTor
	Button() : ptr_font_(nullptr), current_state_(NORMAL) {}

	// Generates a TextureBB object to store the Button objects image and
	// bounding box
	//	@param r Pointer to the renderer
	//	@param label the string sequence to converted
	//	@param fontSize Defines the size of the font used
	Button(SDL_Renderer* r, const string& label, SDL_Color& textColor, const Uint8 fontSize = 42);

	~Button();

	//Handles events for the object
	//	@param event the game's event struct holds the current SDL_Event to
	//	be processed.
	void HandleEvents(SDL_Event* event);

	//Accessor method for Button object's texture
	//	@return label_texbb_.text pointer to an SDL_Texture object
	inline SDL_Texture* getTexture() const { return label_texbb_.tex; }

	//Accessor for _pLabelTex.dimensions
	//	@return label_texbb_.dimensions and SDL_Rect representing the bounding
	// box of the Button.
	inline SDL_Rect getBoundingBox() const { return label_texbb_.dimensions; }

	inline void SetWidth(int newVal) { label_texbb_.dimensions.w = newVal; }
	inline void SetHeight(int newVal) { label_texbb_.dimensions.h = newVal; }

	//Accessor method for _currentState
	inline ButtonState getState() const { return current_state_; }

	// Mutator for label_texbb_.dimensions->x & label_texbb_.dimensions->y
	//	@param x Value representing object's position on screen's x-axis
	//	@param y Value representing object's position on screen's y-axis
	inline void setPosition(const int x, const int y)
	{
		label_texbb_.dimensions.x = x;
		label_texbb_.dimensions.y = y;
	}
};
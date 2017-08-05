#pragma once

#include "Texture.h"

#include <vector>

using std::vector;


class SpriteSheet : public Texture
{
private:
	int x_offset_;
	int y_offset_;

	int num_of_frames;
	int frames_per_line;

	int ss_width_;
	int ss_height_;

	int starting_x;
	int starting_y;


	int current_frame;

	vector<SDL_Rect> sprite_frames;

	void Fill();
public:
	SpriteSheet();
	// Gives the spritesheet the dimensions of the sprites
	//		@Param xoff -- The x offset between sprites
	//		@Param yoff -- The y offset between sprites
	//		@param height -- height of the sprite within
	//		@param width -- width of the sprite
	//		@param fpline -- frames per line
	//      @param numFrames -- Number of frames to be used
	//		@param starting x coord
	//		@param starting y coord
	SpriteSheet(int, int, int, int, int, int, int, int);

	virtual void Draw(SDL_Renderer*);


};

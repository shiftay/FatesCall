#include "SpriteSheet.h"

SpriteSheet::SpriteSheet() {}

SpriteSheet::SpriteSheet(int xoff, int yoff, int height, int width, int fpline, int numFrames, int startX, int startY)
{
	x_offset_ = xoff;
	y_offset_ = yoff;
	ss_height_ = height;
	ss_width_ = width;
	frames_per_line = fpline;
	num_of_frames = numFrames;
	starting_x = startX;
	starting_y = startY;
	current_frame = 0;

	Fill();
}


void SpriteSheet::Draw(SDL_Renderer* r)
{
	if (sprite_frames.empty())
	{
		Fill();
	}

	SDL_Rect holder = { x_, y_, width_, height_ };

	SDL_RenderCopy(r, texture_, &sprite_frames[current_frame], &holder);


	current_frame++;
	if (current_frame >= num_of_frames)
		current_frame = 0;
}


void SpriteSheet::Fill()
{
	SDL_Rect holder = { starting_x, starting_y, ss_width_, ss_height_ };
	sprite_frames.push_back(holder);

	int lines = 1;

	for (int i = 1; i < num_of_frames; i++)
	{
		if (i % (frames_per_line - 1) == 0)
		{
			holder.y += (ss_height_) + (y_offset_);
			holder.x = starting_x;
			lines++;
		}
		else
			holder.x += (ss_width_  + x_offset_);
		sprite_frames.push_back(holder);
	}

}
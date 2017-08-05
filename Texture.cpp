#include "Texture.h"

Texture::Texture() : texture_(nullptr) 
{
	collider.position.x = 0;
	collider.position.y = 0;

	collider.height = 0;
	collider.width = 0;
}


Texture::~Texture()
{
	//SDL_DestroyTexture(texture_);
	//texture_ = nullptr;
	//cout << "in texture DTOR";
}

bool Texture::LoadTexture(SDL_Renderer* r, const string& fileName)
{
	bool success = true;

	// load texture
	texture_ = IMG_LoadTexture(r, fileName.c_str());

	if(texture_ == nullptr) // if nothing is loaded
	{
		success = false;
	}
	
	SDL_QueryTexture(texture_, NULL, NULL, &collider.width, &collider.height);
	
	return success;
}


void Texture::Draw(SDL_Renderer* r)
{
	SDL_Rect holder = { collider.position.x, collider.position.y, collider.width, collider.height };

	SDL_RenderCopy(r, texture_, NULL, &holder);
}

void Texture::Draw(SDL_Renderer* r, SDL_Rect* x)
{
	SDL_RenderCopy(r, texture_, NULL, x);
}
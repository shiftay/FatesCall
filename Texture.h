// Class Texture
// v0.0.1
// Author : Stephen Roebuck
// Date : 21/09/2016
//
//	Holds Texture for various players within the game. 
//	Used throughout game on various actors / environments
//
//v0.0.1
//Author : Giane Carlo
//Date : 29/9/2016
//
//	Created another Draw function and overloaded it.
//
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using std::cout;
using std::string;

struct Point
{
public:
	int x, y;
};

struct Collider
{
public:
	Point position;
	int width, height;
};

// Texture
class Texture
{
protected:
	string name_;
	float scaleX_;
	float scaleY_;
	SDL_Texture* texture_;
	bool visible_;
	Collider collider;

public:
	Texture();
	~Texture();

	bool LoadTexture(SDL_Renderer*, const string&);
	virtual void Draw(SDL_Renderer*, SDL_Rect*);
	virtual void Draw(SDL_Renderer*);

	// Accessors
	inline const string& name() const		{ return name_; }	
	inline float scaleX() const				{ return scaleX_; }
	inline float scaleY() const				{ return scaleY_; }
	inline SDL_Texture* texture() const		{ return texture_; }
	inline bool visible() const				{ return visible_; }
	Collider& Collider()					{ return collider; }

	// Mutators
	inline void name(const string& newVal)  { name_ = newVal; }
	inline void scaleX(const float newVal)	{ scaleX_ = newVal; }
	inline void scaleY(const float newVal)	{ scaleY_ = newVal; }
	inline void visible(const bool newVal)	{ visible_ = newVal; }
};
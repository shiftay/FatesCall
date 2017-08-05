// Author: Giane Carlo
// Class AudioManager
// Date : 3/10/2016
//
// Version : 0.0.1
// 
#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <iostream>

//
//	Class that controls the audio in the game.
//
class AudioManager
{
private:
	Mix_Music* ptr_bgmusic;
	Mix_Chunk* ptr_fireball;
	Mix_Chunk* ptr_blizzard;
	Mix_Chunk* ptr_lightning;

	static AudioManager* ptr_singleton_;


protected:
	AudioManager();

public:	
	~AudioManager();
	// Plays the fireball Sound
	void PlayFB();
	// Plays the Thunderbolt Sound
	void PlayTB();
	// Plays the Frostbolt Sound
	void PlayFrost();

	//Accessor
	Mix_Music* GetBG() { return ptr_bgmusic; }

	static AudioManager* GetInstance();
};



//-----------------------------------------------------
//	To Call the audio file
//-----------------------------------------------------
//	for mix chunks ->           Mix_PlayChannel(-1, ptr_fireball, 0);   
//							    Mix_PlayChannel(-1, ptr_blizzard, 0);   
//								Mix_PlayChannel(-1, ptr_lightning, 0);   
//
//  for bg music ->				Mix_PlayMusic(ptr_bgmusic,-1);
//
//	for stopping the music-> 
//	Example :::::::
//	case SDLK_9:
//	// If there is no music playing
//	if (Mix_PlayingMusic() == 0)
//	{
//		// Play the music
//		Mix_PlayMusic(ptr_bgmusic, -1);
//	}
//	// If music is being played
//	else
//	{
//		// If the music is  being played
//		if (Mix_PausedMusic() == 1)
//		{
//			// Resume the music
//			Mix_ResumeMusic();
//		}
//		// If the music is playing
//		else
//		{
//			// Pause the music
//			Mix_PauseMusic();
//		}
//	}
//	break;
//---------------------------------------------------
// To Initialize
//---------------------------------------------------
//	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
//	{
//		std::cout << "SDL_mixer could not initialize! %s\n"
//		<< Mix_GetError() << "\n";
//	}


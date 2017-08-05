#include "AudioManager.h"

AudioManager* AudioManager::ptr_singleton_ = nullptr;

AudioManager* AudioManager::GetInstance()
{
	if (!ptr_singleton_)
	{
		ptr_singleton_ = new AudioManager();
	}

	return ptr_singleton_;
}



AudioManager::AudioManager()
{
	ptr_bgmusic = Mix_LoadMUS("resources//Audio//RPG.wav");
	ptr_fireball = Mix_LoadWAV("resources//Audio//Fireball.wav");
	ptr_blizzard = Mix_LoadWAV("resources//Audio//Blizzard.wav");
	ptr_lightning = Mix_LoadWAV("resources//Audio//Lightning.wav");
}

AudioManager::~AudioManager()
{
	Mix_FreeChunk(ptr_fireball);
	Mix_FreeChunk(ptr_blizzard);
	Mix_FreeChunk(ptr_lightning);

	ptr_fireball = nullptr;
	ptr_blizzard = nullptr;
	ptr_lightning = nullptr;
	
	//Free the music
	Mix_FreeMusic(ptr_bgmusic);
	ptr_bgmusic = nullptr;

}

void AudioManager::PlayFB()
{
	Mix_PlayChannel(-1, ptr_fireball, 0);
}

void AudioManager::PlayFrost()
{
	Mix_PlayChannel(-1, ptr_blizzard, 0);   
}

void AudioManager::PlayTB()
{
	Mix_PlayChannel(-1, ptr_lightning, 0);   
}
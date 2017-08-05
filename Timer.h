// Author: Stephen Roebuck
// Email: shroebuck@gmail.com
// Twitter: @shiftay416
//
// Last Update: 19/09/2016
// Version: 1.0.1

#pragma once

#include "SDL.h"

//A simple timer object which supports pause and unpausing. Tracks time based
//on the number of ticks passed since the timer object started.
//
//	Timer timer_;		//Declare timer object var
//	timer_.Start();		//Start timer
//	timer.getTicks();	//Returns number of ticks passed since timer started

class Timer
{
	//============================================================//
	//						Properties							  //
	//============================================================//
private:
	//Stores clock time at the moment the timer started.
	unsigned int start_ticks_;

	//The ticks stored when the timer was paused
	unsigned int paused_ticks_;

	//Tracks the timer's status
	bool paused_;

	//Tracks if Start() has been invoked.
	bool started_;

	//============================================================//
	//						Behaviors							  //
	//============================================================//
public:
	//Initializes member variables
	Timer();

	//Starts the timer
	void Start();

	//Stops the timer
	void Stop();

	//Pauses the timer
	void Pause();

	//Unpauses the timer
	void Unpause();

	unsigned int getTicks();	//Returns the number of ticks passed since timer started

	//Accessor method for checking if the timer has been started
	// @return started_
	bool isStarted() const { return started_; }

	//Accessor method for checking if the timer has been paused
	// @return true if both paused_ and started_ is true
	// @return false if either paused_ or started_ is false(or both)
	bool isPaused() const { return paused_ && started_; }
};
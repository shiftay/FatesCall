#include "Actor.h"

bool Actor::IsAlive()
{
	bool alive = true;
	if (Health().Current() <= 0)
		alive = false;
	return alive;
}

int Actor::DetermineDrop()
{
	return rand() % 10;
}
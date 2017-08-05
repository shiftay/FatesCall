// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-10-06
// Version: 1.0.1
#include "Dragon.h"
#include "Player.h"

//
//	Dragon's Left Hand
//
class LeftHand : public Enemy
{
private:
	Timer leftTime;
	bool canMove;
	bool isgoingDown;
	int direction;
	Timer phase2Timer;

	void Hide();
	void Show();

public:
	LeftHand();
	LeftHand(SDL_Renderer*);
	~LeftHand();

	virtual void Attack();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);
	static bool fireblast;
	void Draw(SDL_Renderer* r);
};
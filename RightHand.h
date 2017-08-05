// Author: Denn Mark Laurente
// Email: dennmarklaurente@gmail.com
//
// Last Update: 2016-10-06
// Version: 1.0.1
#include "Dragon.h"
#include "Player.h"


class RightHand : public Enemy
{
private:
	Timer rightTime;
	Timer phase2Timer;

	bool canMove;
	bool isgoingDown;
	int direction;

	void Hide();
	void Show();

public:
	RightHand();
	RightHand(SDL_Renderer*);
	~RightHand();

	virtual void Attack();
	virtual void HandleEvents(SDL_Event*) {}
	virtual void AIMove();
	virtual void HandleCollision(int, int);
	static bool fireblast;
	void Draw(SDL_Renderer* r);
};
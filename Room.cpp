#include "Room.h"

Room::~Room()
{
	exits.clear();
	proj.clear();
	cout << "inside ~room";
}

void Room::EraseUnit(int place)
{
	activeUnits.erase(activeUnits.begin() + place);
}



// fills the exits, used by CTors of derived classes
void Room::FillExits(SDL_Renderer* r)
{
	vector<RoomType> exitTest;

	exitTest.push_back(Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x - 1, Player::testMinimap.PlayerLocation().y)); // top
	exitTest.push_back(Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x + 1, Player::testMinimap.PlayerLocation().y)); // down
	exitTest.push_back(Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x, Player::testMinimap.PlayerLocation().y - 1)); // left
	exitTest.push_back(Player::testMinimap.CheckRoom(Player::testMinimap.PlayerLocation().x, Player::testMinimap.PlayerLocation().y + 1)); // right

	for (int i = 0; i < exitTest.size(); i++)
	{
		if (exitTest[i] != EMPTY)
		{
			switch (i)
			{
			case 0:
				exits.push_back(FillNorth(r));
				break;
			case 1:
				exits.push_back(FillSouth(r));
				break;
			case 2:
				exits.push_back(FillWest(r));
				break;
			case 3:
				exits.push_back(FillEast(r));
				break;
			}
		}
	}
}

Collider Room::FillNorth(SDL_Renderer* r)
{
	Texture holder;
	holder.LoadTexture(r, "resources\\OpenDoor.png");

	holder.Collider().width = 50;
	holder.Collider().height = 50;
	holder.Collider().position.x = 475;
	holder.Collider().position.y = 0;

	Doors.push_back(holder);

	return holder.Collider();
}

Collider Room::FillWest(SDL_Renderer* r)
{
	Texture holder;

	holder.LoadTexture(r, "resources\\OpenDoor.png");

	holder.Collider().width = 50;
	holder.Collider().height = 50;
	holder.Collider().position.x = 0;
	holder.Collider().position.y = 325;

	Doors.push_back(holder);

	return holder.Collider();
}

Collider Room::FillSouth(SDL_Renderer* r)
{
	Texture holder;
	holder.LoadTexture(r, "resources\\OpenDoor.png");

	holder.Collider().width = 50;
	holder.Collider().height = 50;
	holder.Collider().position.x = 475;
	holder.Collider().position.y = 550;

	Doors.push_back(holder);

	return holder.Collider();
}

Collider Room::FillEast(SDL_Renderer* r)
{
	Texture holder;
	holder.LoadTexture(r, "resources\\OpenDoor.png");
	
	holder.Collider().width = 50;
	holder.Collider().height = 50;
	holder.Collider().position.x = 950;
	holder.Collider().position.y = 325;


	Doors.push_back(holder);


	return holder.Collider();
}
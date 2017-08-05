#include "CollisionDetection.h"


void CollisionDetection::HandleEvents(vector<Projectile*> roomProj,vector<Projectile*> projectiles, vector<Actor*> units, Room* currentRoom, vector<Item*> items, Player* player)
{
	CheckProjectiles(projectiles, units, player);
	CheckProjectiles(roomProj, units, player);
	HandleActors(units, player);
//	HandleObstacles(currentRoom, units);
	HandleDoors(currentRoom, player);
	HandleItems(items, player);
}

void CollisionDetection::HandleDoors(Room* currentRoom, Player* player)
{
	for (int i = 0; i < currentRoom->Exits().size(); i++)
	{
		if (IsCollision(currentRoom->Exits()[i], player->GetTexture()->Collider()))
		{
			Player::doorUsed = true;
			switch (currentRoom->Exits()[i].position.x)
			{
			case 0:
				currentRoom->SetDoor(WEST);
				break;
			case 475:
				if (currentRoom->Exits()[i].position.y == 0)
					currentRoom->SetDoor(NORTH);
				else
					currentRoom->SetDoor(SOUTH);
				break;
			case 950:
				currentRoom->SetDoor(EAST);
				break;
			}
		}
	}
}

// Checks collision with items, adds gold or instant heal for food
// and if it goes into the inventory, it makes sure the inventory isnt full
void CollisionDetection::HandleItems(vector<Item*> items, Player* player)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (IsCollision(items[i]->GetTexture().Collider(), player->GetTexture()->Collider()))
		{
			if (items[i]->GetType() == GOLD)
			{
				items[i]->SetPickedUp(true);
				player->GainGold(items[i]->ItemUse());
			}
			else if (items[i]->GetType() == FOOD)
			{
				items[i]->SetPickedUp(true);
				player->Health() += items[i]->ItemUse();
			}
			else if (!player->GetInventory().isFull())
			{
				items[i]->SetPickedUp(true);
				player->HandleCollision(items[i]->GetType());
			}
		}
	}
}


void CollisionDetection::CheckProjectiles(vector<Projectile*> projectiles, vector<Actor*> units, Player* player)
{

	for (int i = 0; i < projectiles.size(); i++)
	{

		if (IsCollision(projectiles[i]->GetTexture()->Collider(), player->GetTexture()->Collider()))
		{
			player->HandleCollision(projectiles[i]->GetType(), projectiles[i]->GetDmg());
			projectiles[i]->HandleCollision(player->Type(), player->GetDamage());
		}

		for (int j = 0; j < units.size(); j++)
		{

				if (IsCollision(projectiles[i]->GetTexture()->Collider(), units[j]->GetTexture()->Collider()))
				{
					// COLLISION LOGIC
					// Need logic to make sure it is active on the screen.
					units[j]->HandleCollision(projectiles[i]->GetType(), projectiles[i]->GetDmg());
					projectiles[i]->HandleCollision(units[j]->Type(), units[j]->GetDamage());
				}

		}
	}
}

void CollisionDetection::HandleActors(vector<Actor*> units, Player* player)
{
	int j = 0;
	
	for (int i = 0; i < units.size(); i++)
	{
		if (IsCollision(player->GetTexture()->Collider(), units[i]->GetTexture()->Collider()))
		{
			player->HandleCollision(units[i]->Type(), units[i]->GetDamage());
		}
	}
}

bool CollisionDetection::IsCollision(Collider a, Collider b)
{
	double left_a, left_b;
	double right_a, right_b;
	double top_a, top_b;
	double bottom_a, bottom_b;
	// rect a
	left_a = a.position.x;
	right_a = a.position.x + a.width;
	top_a = a.position.y;
	bottom_a = a.position.y + a.height;
	// rect b
	left_b = b.position.x;
	right_b = b.position.x + b.width;
	top_b = b.position.y;
	bottom_b = b.position.y + b.height;

	// Collision (intersection) tests
	if ( bottom_a < top_b ) // b is above
		return false;

	if ( top_a > bottom_b ) // b is below
		return false;

	if ( right_a < left_b ) // b is to the right
		return false;

	if ( left_a > right_b ) // b is to the left
		return false;

	return true; // there was a collision
}
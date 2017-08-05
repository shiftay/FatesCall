// Author: Vraj Patel
// Email: vp1994@live.ca
//
// Last Update: 2016-09-30
// Version: 1.0.2
// SHR - Included struct to track
//		 Players Location
//		 Changed DataType to RoomType
//		 for ReturnRoom and map
#pragma once
#include "Texture.h"
#include <stdlib.h> 
#include <time.h>

//	enum for the room for setting and checking 
//	next room
enum RoomType
{
	EMPTY,
	BOSS,
	LOCKED,
	SHOP,
	PUZZLE,
	BASE
};
// struct to hold coords for future
// calculations
struct Coordinates
{
public:
	int x, y;
};

//
//	The minimap's creation tool
//
class Minimap
{
private:
	RoomType array_map[5][5]; 
	Coordinates playerLocation;
	// Helps fill the minimap
	RoomType ReturnRoom(int, int);
	Texture boss, empty, shop, locked, base, playerH;

public:
	Minimap();
	~Minimap(){}
	// Draws the map to the HUD
	void DrawMap(SDL_Renderer*);
	void CleanMap(); // might be needed for potential reuse of the map array
	// Creates the map
	void CreateMap(const int);

	Coordinates& PlayerLocation() { return playerLocation; }

	RoomType CheckRoom(int,int);

};
#include "TileMap.h"
#include "TextureManager.h"


TileMap::TileMap()
	: src{}
	, dest{}
	, dirt{ TextureManager::LoadTexture("Img/dirt.png") }
	, grass{ TextureManager::LoadTexture("Img/grass.png") }
	, water{ TextureManager::LoadTexture("Img/water.png") }
	, map
	{
		{ 0, 0, 0, 0, 0, 0, 0 , 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0 , 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 2 , 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 2 , 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0},
		{ 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0 , 0, 0, 0, 0 ,0}
	}
{
	loadMap(map);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

TileMap::~TileMap()
{
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(water);
}

void TileMap::loadMap(int arr[20][25])
{
	for (int row = 0; row < 20; ++row)
	{
		for (int column = 0; column < 25; ++column)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void TileMap::drawMap()
{
	int type = 0;
	for (int row = 0; row < 20; ++row)
	{
		for (int column = 0; column < 25; ++column)
		{
			type = map[row][column];
			
			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
				case 0:
					TextureManager::Draw(water, src, dest);
					break;
				case 1:
					TextureManager::Draw(grass, src, dest);
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest);
					break;
				default:
					break;
			}
		}
	}
}

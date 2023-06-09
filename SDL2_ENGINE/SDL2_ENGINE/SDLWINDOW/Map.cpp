#include "Map.h"
#include "TextureManager.h"
#include "Game.h"
#include <fstream>
#include <iostream>
#include <sstream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
	std::string line;
	std::fstream mapFile;
	mapFile.open(path);
	
	for (int y = 0; y < sizeY; ++y)
	{
		if (std::getline(mapFile, line))
		{
			std::stringstream ss(line);
			std::string tileStr;
            int srcX, srcY;

            for (int x = 0; x < sizeX; ++x)
            {
                if (!std::getline(ss, tileStr, ','))
                {
                    std::cerr << "Failed to read number at position " << x << " in line " << y << "\n";
                    break;
                }
                try
                {
                    int tile = std::stoi(tileStr);
                    if (tile > 9)
                    {
                        srcX = tile % 10 * 32;
                        srcY = tile / 10 * 32;
                    }
                    else
                    {
						srcX = tile * 32;
                        srcY = 0;
					}
                    Game::AddTile(srcX, srcY, x * 64, y * 64);
                }
                catch (const std::invalid_argument& e)
                {
                    std::cerr << "Invalid argument: " << tileStr << " at position " << x << " in line " << y << "\n";
                    throw;
                }
            }
		}
	}
	mapFile.close();
}

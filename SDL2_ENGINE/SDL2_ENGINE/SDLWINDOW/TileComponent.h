#pragma once
#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include <SDL.h>
#include "ECS.h"
#include "TransformComponent.h"

class TileComponent : public Component
{
public:
	TileComponent() = default;

	TileComponent(int srcX, int srcY, int x, int y, const char* path)
		: texture{ TextureManager::LoadTexture(path)}
		, srcRect{ SDL_Rect() }
		, destRect{ SDL_Rect() }
	{
		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 32;

		destRect.x = x;
		destRect.y = y;
		destRect.w = destRect.h = 64;
	}

	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

};

#endif // !TILECOMPONENT_H
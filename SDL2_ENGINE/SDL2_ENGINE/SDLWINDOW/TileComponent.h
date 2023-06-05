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

	TileComponent(int x, int y, int w, int h, int id)
		: transform{ nullptr }
		, sprite{ nullptr }
		, tileRect{ x, y, w, h }
		, tileID{ id }
		, path{ nullptr }
	{
		switch (tileID)
		{
			case 0:
				path = "Img/water.png";
				break;
			case 1:
				path = "Img/dirt.png";
				break;
			case 2:
				path = "Img/grass.png";
				break;
			default:
				break;
		}
	}

	void init() override
	{
		entity->addComponent<TransformComponent>(static_cast<float>(tileRect.x), static_cast<float>(tileRect.y), tileRect.w, tileRect.h, 1);
		transform = &entity->component<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->component<SpriteComponent>();
	}

	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	char const* path;
};

#endif // !TILECOMPONENT_H
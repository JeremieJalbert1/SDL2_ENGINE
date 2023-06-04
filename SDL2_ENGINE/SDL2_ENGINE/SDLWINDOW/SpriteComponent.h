#pragma once
#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component
{

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
		: transform{ nullptr }
		, texture{ nullptr }
		, srcRect{ SDL_Rect() }
		, destRect{ SDL_Rect() }

	{
		setTexture(path);
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void init() override
	{
		transform = &entity->component<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);

		destRect.w = transform->scale * transform->width;
		destRect.h = transform->scale * transform->height;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};

#endif // !SPRITECOMPONENT_H
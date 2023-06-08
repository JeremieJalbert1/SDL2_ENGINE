#pragma once
#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <map>
#include "SDL.h"
#include "TransformComponent.h"
#include "TextureManager.h"
#include "Animation.h"


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

	SpriteComponent(const char* path, bool isAnimated)
		: transform{ nullptr }
		, texture{ nullptr }
		, srcRect{ SDL_Rect() }
		, destRect{ SDL_Rect() }
		, frames{ frames }
		, speed{ speed }
	{
		animated = isAnimated;
		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		play("Idle");

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
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;
		
		destRect.x = static_cast<int>(transform->position.x) - Game::camera.x;
		destRect.y = static_cast<int>(transform->position.y) - Game::camera.y;

		destRect.w = transform->scale * transform->width;
		destRect.h = transform->scale * transform->height;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void play(const char* animName)
	{
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

	int animIndex = 0;
	std::map<const char*, Animation> animations;
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
};

#endif // !SPRITECOMPONENT_H
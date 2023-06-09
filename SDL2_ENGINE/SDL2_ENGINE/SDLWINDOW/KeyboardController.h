#pragma once
#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "Game.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class KeyboardController : public Component
{
public:
	KeyboardController()
		: transform{ nullptr }
		, sprite{ nullptr }
	{
	}

	TransformComponent* transform;
	SpriteComponent* sprite;

	void init() override
	{
		transform = &entity->component<TransformComponent>();
		sprite = &entity->component<SpriteComponent>();
	}
	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w: 
				transform->velocity.y = -1;
				sprite->play("Walk");
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				sprite->play("Walk");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				sprite->play("Walk");
				sprite->spriteFlip = SDL_FLIP_NONE;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				sprite->play("Walk");
				break;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				sprite->play("Idle");
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				sprite->play("Idle");
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;
			case SDLK_ESCAPE:
				Game::isRunning = false;
				break;
			default:
				break;
			}
		}
	}

};

#endif // !KEYBOARDCONTROLLER_H
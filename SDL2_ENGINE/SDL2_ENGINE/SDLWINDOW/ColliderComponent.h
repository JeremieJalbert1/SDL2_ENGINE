#pragma once
#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <string>
#include "TransformComponent.h"
#include "Game.h"

class ColliderComponent : public Component
{
public:

	ColliderComponent(std::string tag)
		: tag{ tag }
		, collider{ SDL_Rect() }
		, transform{ nullptr }
	{
	}

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->component<TransformComponent>();

		Game::colliders.push_back(this);
	}

	void update() override
	{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);

		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;
};

#endif // !COLLIDERCOMPONENT_H
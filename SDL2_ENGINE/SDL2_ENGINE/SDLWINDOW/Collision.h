#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include "SDL.h"

class Collision
{
public:
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
	//static bool AABB(const TransformComponent& transformA, const TransformComponent& transformB);
};

#endif // !COLLISION_H

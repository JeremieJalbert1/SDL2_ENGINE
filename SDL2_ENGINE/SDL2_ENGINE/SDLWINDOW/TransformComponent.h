#pragma once
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Components.h"

class TransformComponent : public Component
{
public:
	TransformComponent()
		: position{ Vect2D() }
		, velocity{ Vect2D() }
		, speed{}
		, height{}
		, width{}
		, scale{}
	{
	}

	~TransformComponent() = default;

	TransformComponent(Vect2D position, int height, int width, int scale)
		: position{ position }
		, velocity{ Vect2D() }
		, speed{}
		, height{ height }
		, width{ width }
		, scale{ 1 }
	{
	}

	TransformComponent(int scale)
		: position{}
		, velocity{ Vect2D() }
		, speed{}
		, height{}
		, width{}
		, scale{ scale }
	{

	}

	TransformComponent(Vect2D position, int speed, int height, int width, int scale)
		: position{ position }
		, velocity{ Vect2D() }
		, speed{ speed }
		, height{ height }
		, width{ width }
		, scale{ 1 }
	{
	}


	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	Vect2D position;
	Vect2D velocity;

	int speed;
	int height;
	int width;
	int scale;

};

#endif // !TRANSFORMCOMPONENT_H
#pragma once
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "ECS.h"
#include "Vect2D.h"

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
		position.x = 400;
		position.y = 320;
	}

	TransformComponent(Vect2D position, int speed, int height, int width, int scale)
		: position{ position }
		, velocity{ Vect2D() }
		, speed{ speed }
		, height{ height }
		, width{ width }
		, scale{ scale }
	{
	}

	TransformComponent(float x, float y, int height, int width, int scale)
		: position{ Vect2D(x, y) }
		, velocity{ Vect2D() }
		, speed{}
		, height{ height }
		, width{ width }
		, scale{ scale }
	{
	}


	void update() override
	{
	}

	Vect2D position;
	Vect2D velocity;

	int speed;
	int height;
	int width;
	int scale;

};

#endif // !TRANSFORMCOMPONENT_H
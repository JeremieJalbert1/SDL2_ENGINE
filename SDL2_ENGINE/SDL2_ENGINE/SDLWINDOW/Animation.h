#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

struct Animation
{
	Animation()
		: index{ 0 }
		, frames{ 0 }
		, speed{ 0 }
	{
	}

	Animation(int i, int f, int s)
		: index{ i }
		, frames{ f }
		, speed{ s }
	{
	}
	
	int index;
	int frames;
	int speed;

};

#endif // !ANIMATION_H
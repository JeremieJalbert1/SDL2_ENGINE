#pragma once
#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class ColliderComponent;

using CollidersVector = std::vector<ColliderComponent*>;

class Game
{

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static CollidersVector colliders;
	static bool isRunning;

private:
	SDL_Window* window;
};


#endif // !GAME_H

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "tileMap.h"
#include "Components.h"
#include "Collision.h"

TileMap* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::isRunning = false;

Manager manager;
auto& newPlayer(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
	: window(nullptr)
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!...\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);

		if (window)
		{
			std::cout << "Window Created!...\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!...\n";
		}
		isRunning = true;
	}

	map = new TileMap();

	newPlayer.addComponent<TransformComponent>(Vect2D(196, 196), 3, 196, 196, 1);
	newPlayer.addComponent<SpriteComponent>("Img/Person.png");
	newPlayer.addComponent<KeyboardController>();
	newPlayer.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(Vect2D(55, 122), 300, 20, 1);
	wall.addComponent<SpriteComponent>("Img/Wall.png");
	wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();

	if (Collision::AABB(newPlayer.component<ColliderComponent>().collider, wall.component<ColliderComponent>().collider))
	{
		std::cout << "Wall Hit!\n";
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->drawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!...\n";
}

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "Components.h"
#include "Collision.h"
#include "Map.h"

TileMap* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
CollidersVector Game::colliders;
bool Game::isRunning = false;

Manager manager;
Entity& newPlayer(manager.addEntity());
const char* MAPFILE = "Img/terrain_ss.png";

enum groupLabels : std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

std::vector<Entity*>& tiles{ manager.getGroup(groupMap) };
std::vector<Entity*>& players{ manager.getGroup(groupPlayers) };
std::vector<Entity*>& enemies{ manager.getGroup(groupEnemies) };
std::vector<Entity*>& colliders{ manager.getGroup(groupColliders) };

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

	Map::LoadMap("Img/map.map", 25, 20);

	newPlayer.addComponent<TransformComponent>(Vect2D(196, 196), 3, 32, 32, 1);
	newPlayer.addComponent<SpriteComponent>("Img/player_anims.png", true);
	newPlayer.addComponent<KeyboardController>();
	newPlayer.addComponent<ColliderComponent>("player");
	newPlayer.addGroup(groupPlayers);
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

	Vect2D pVelocity = newPlayer.component<TransformComponent>().velocity;
	int pSpeed = newPlayer.component<TransformComponent>().speed;

	for (auto t : tiles)
	{
		t->component<TileComponent>().destRect.x += -(pVelocity.x * pSpeed);
		t->component<TileComponent>().destRect.y += -(pVelocity.y * pSpeed);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for(auto& t : tiles) { t->draw(); }
	for(auto& p : players) { p->draw(); }
	for(auto& e : enemies) { e->draw(); }
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!...\n";
}

void Game::AddTile(int srcX, int srcY, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, x, y, MAPFILE);
	tile.addGroup(groupMap);
}

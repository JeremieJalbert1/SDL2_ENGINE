#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
	: xpos{ x }
	, ypos{ y }
	, objTexture{}
	, srcRect{}
	, destRect{}
{
	objTexture = TextureManager::LoadTexture(textureSheet);
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	srcRect.h = 96;
	srcRect.w = 96;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

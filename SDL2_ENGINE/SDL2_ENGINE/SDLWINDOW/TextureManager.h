#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class TextureManager
{

public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};

#endif // !TEXTUREMANAGER_H


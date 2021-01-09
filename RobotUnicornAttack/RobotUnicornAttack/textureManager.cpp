#include"textureManager.h"


SDL_Texture* TextureManager::Texture(const char* filedir, SDL_Renderer* ren) {
	SDL_Surface* surface;
	surface = IMG_Load(filedir);
	SDL_Texture* texture;
	texture = SDL_CreateTextureFromSurface(ren, surface);
	return texture;
}
#include"background.h"

void Background::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, getTexture(), NULL, NULL);
}
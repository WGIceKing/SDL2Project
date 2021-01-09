#include"platform.h"

void Platform::Render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, Texture, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
	//SDL_RenderCopy(renderer, getTexture(), &getSource(), &getDestination());
}

void Platform::Update() {
	setDestination(xPos = xPos - scrollingSpeed, yPos, 800, 100);
}

void Platform::CreateTexture(const char* filedir, SDL_Renderer* renderer) {
	Texture = TextureManager::Texture(filedir, renderer);
}

void Platform::setScrollingSpeed(int x) {
	scrollingSpeed = x;
}

void Platform::setXY(int x, int y) {
	xPos = x;
	yPos = y;
}

int Platform::getX() {
	return xPos;
}

int Platform::getY() {
	return yPos;
}
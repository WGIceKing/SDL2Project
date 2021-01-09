#include"star.h"

void Star::Render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, Texture, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
}

void Star::Update() {
	setDestination(xPos = xPos - scrollingSpeed, yPos, 100, 100);
}

void Star::CreateTexture(const char* filedir, SDL_Renderer* renderer) {
	Texture = TextureManager::Texture(filedir, renderer);
}

void Star::setXY(int x, int y) {
	xPos = x;
	yPos = y;
}

int Star::getX() {
	return xPos;
}

int Star::getY() {
	return yPos;
}

void Star::setScrollingSpeed(int x) {
	scrollingSpeed = x;
}
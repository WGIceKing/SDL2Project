#include"obstacle.h"

void Obstacle::Render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, Texture, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
}

void Obstacle::Update() {
	setDestination(xPos = xPos - scrollingSpeed, yPos, 100, 100);
}

void Obstacle::CreateTexture(const char* filedir, SDL_Renderer* renderer) {
	Texture = TextureManager::Texture(filedir, renderer);
}

void Obstacle::setXY(int x, int y) {
	xPos = x;
	yPos = y;
}

int Obstacle::getX() {
	return xPos;
}

int Obstacle::getY() {
	return yPos;
}

void Obstacle::setScrollingSpeed(int x) {
	scrollingSpeed = x;
}
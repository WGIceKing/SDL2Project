#include"fairy.h"

void Fairy::Render(SDL_Renderer* renderer) {
	if (taken) {
		SDL_RenderCopyEx(renderer, Texture, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
	}
	else {
		animation++;
		if (animation < 10) {
			SDL_RenderCopyEx(renderer, getTexture(), &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation >= 10 && animation <= 20) {
			SDL_RenderCopyEx(renderer, Particle1, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation >= 20 && animation <= 30) {
			SDL_RenderCopyEx(renderer, Particle2, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation > 30 && animation <= 40) {
			SDL_RenderCopyEx(renderer, Particle3, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation > 40 && animation <= 50) {
			SDL_RenderCopyEx(renderer, Particle4, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		if (animation > 50) {
			animation = 0;
		}
	}
}

void Fairy::setTaken(bool taken1) {
	taken = taken1;
}

bool Fairy::getTaken() {
	return taken;
}

void Fairy::setSwingLimit() {
	swingLimitDown = yPos + swingValue;
	swingLimitUp = yPos - swingValue;
}

void Fairy::setScrollingSpeed(int x) {
	scrollingSpeed = x;
}


void Fairy::Update() {
	if (direction) {
		yPos = yPos - flyingSpeed;
	}
	else {
		yPos = yPos + flyingSpeed;
	}

	if (yPos >= swingLimitDown) {
		direction = true;
	}
	else if (yPos <= swingLimitUp) {
		direction = false;
	}

	xPos = xPos - scrollingSpeed;
	setDestination(xPos, yPos, 60, 60);
}

void Fairy::CreateTexture(const char* filedir, SDL_Renderer* renderer) {
	Texture = TextureManager::Texture(filedir, renderer);
}

void Fairy::setXY(int x, int y) {
	xPos = x;
	yPos = y;
}

int Fairy::getX() {
	return xPos;
}

int Fairy::getY() {
	return yPos;
}

void Fairy::CreateParticle1(const char* filedir, SDL_Renderer* renderer) {
	Particle1 = TextureManager::Texture(filedir, renderer);
}

void Fairy::CreateParticle2(const char* filedir, SDL_Renderer* renderer) {
	Particle2 = TextureManager::Texture(filedir, renderer);
}

void Fairy::CreateParticle3(const char* filedir, SDL_Renderer* renderer) {
	Particle3 = TextureManager::Texture(filedir, renderer);
}

void Fairy::CreateParticle4(const char* filedir, SDL_Renderer* renderer) {
	Particle4 = TextureManager::Texture(filedir, renderer);
}
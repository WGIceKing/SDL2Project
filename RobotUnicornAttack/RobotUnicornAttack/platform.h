#pragma once
#include"object.h"

class Platform :public Object {
private:
	int xPos = 0;
	int yPos = -500;
	SDL_Texture* Texture;
	double scrollingSpeed = 6;

public:
	void Update();
	void setXY(int x, int y);
	void setScrollingSpeed(int x);
	int getX();
	int getY();
	void Render(SDL_Renderer* ren);
	void CreateTexture(const char* filedir, SDL_Renderer* renderer);
};
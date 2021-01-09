#pragma once
#include"object.h"
#define WIDTHa 800

class Obstacle :public Object {
private:
	double force = 0.0;
	//int xPos = WIDTHa + getSource().w;
	int xPos = 0;
	int yPos = 0;;
	SDL_Texture* Texture;
	double scrollingSpeed = 6;

public:
	void setScrollingSpeed(int x);
	void setXY(int x, int y);
	int getX();
	int getY();
	void Update();
	void Render(SDL_Renderer* ren);
	void CreateTexture(const char* filedir, SDL_Renderer* renderer);
};
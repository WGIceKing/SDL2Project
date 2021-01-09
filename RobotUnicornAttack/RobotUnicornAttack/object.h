#pragma once
#include"textureManager.h"
#include<iostream>
#define FLOORLVL 300
#define WIDTHa 800

class Object {
private:
	SDL_Rect source, destination;
	SDL_Texture* Tex;

public:
	Object();
	void setSource(int x, int y, int w, int h);
	void setDestination(int x, int y, int w, int h);
	SDL_Texture* getTexture();
	SDL_Rect& getSource();
	SDL_Rect& getDestination();
	void CreateTexture(const char* fileDIR, SDL_Renderer* renderer);
	void virtual Render(SDL_Renderer* ren) = 0;
};
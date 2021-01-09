#pragma once
#include<SDL_ttf.h>
#include <string>

class TextManager{
private:
	TTF_Font* font;
	SDL_Rect TextRectangle;
	SDL_Texture* fontTexture;

public:
	void CreateFont(const char* filedir, int size);
	void Text(std::string Text, int r, int g, int b, SDL_Renderer* ren);
	void CreateTexture(SDL_Surface* surface, SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer, int x, int y);
};
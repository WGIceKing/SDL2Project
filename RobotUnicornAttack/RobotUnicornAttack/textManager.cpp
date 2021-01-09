#include"textManager.h"

void TextManager::CreateFont(const char* filedir, int size) {
	font = TTF_OpenFont(filedir, size);
}

void TextManager::Text(std::string Text, int r, int g, int b, SDL_Renderer* renderer) {
	char* Txt = new char[Text.size() + 1];
	std::copy(Text.begin(), Text.end(), Txt);
	Txt[Text.size()] = '\0';
	SDL_Color color = { r, g ,b, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, Txt, color);
	CreateTexture(textSurface, renderer);
	SDL_FreeSurface(textSurface);
	delete Txt;
	Txt = 0;
}

void TextManager::CreateTexture(SDL_Surface* surface, SDL_Renderer* renderer) {
	fontTexture = SDL_CreateTextureFromSurface(renderer, surface);
}

void TextManager::Render(SDL_Renderer* renderer, int x, int y) {
	TextRectangle.x = x;
	TextRectangle.y = y;
	SDL_QueryTexture(fontTexture, NULL, NULL, &TextRectangle.w, &TextRectangle.h);
	SDL_RenderCopy(renderer, fontTexture, NULL, &TextRectangle);
}
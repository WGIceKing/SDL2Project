#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"background.h"

class Menu {
private:
	bool clicked;
	Background MainMenuBackground;

public:
	Menu();
	~Menu();
	void Init(SDL_Renderer* renderer);
	int MenuEvent(SDL_Event& event);
	void Render(SDL_Renderer* renderer);
	bool getClicked();
};

#include"menu.h"

Menu::Menu() {
	clicked = false;
}

void Menu::Init(SDL_Renderer* renderer) {
	MainMenuBackground.CreateTexture("Textures/menuBackground.jpg", renderer);
}

int Menu::MenuEvent(SDL_Event& event) {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		return -1;
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN && event.motion.x > 300 && event.motion.x < 600 && event.motion.y > 100 && event.motion.y < 260) {
		clicked = true;
	}
	return 0;
}

void Menu::Render(SDL_Renderer* renderer) {
	MainMenuBackground.Render(renderer);
}

bool Menu::getClicked() {
	return clicked;
}

Menu::~Menu() {
	clicked = false;
}
#pragma once
#include<SDL.h>
#include<SDL_image.h>

class CollisionManager {
private:

public:
	static bool CheckCollision(SDL_Rect* A, SDL_Rect* B);
	static bool CheckCollisionBellow(SDL_Rect A, SDL_Rect B);
	//static bool CheckCollisionFront(SDL_Rect A, SDL_Rect B);
};
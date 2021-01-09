#include"collisionManager.h"

bool CollisionManager::CheckCollision(SDL_Rect* A, SDL_Rect* B) {
	SDL_bool Collision = SDL_HasIntersection(A, B);
	if(Collision) {
		return true;
	}
	else {
		return false;
	}
}

bool CollisionManager::CheckCollisionBellow(SDL_Rect A, SDL_Rect B) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A.x;
	leftB = B.x;
	rightA = A.x + A.w;
	rightB = B.x + B.w;
	topA = A.y;
	topB = B.y;
	bottomA = A.y + A.h;
	bottomB = B.y + B.h;

	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}
	if (topA >= bottomB) {
		return false;
	}
	if (bottomA <= topB) {
		return false;
	}
	if (bottomA > topB + B.h / 3) {
		return false;
	}

	return true;
}

/*bool CollisionManager::CheckCollisionFront(SDL_Rect A, SDL_Rect B) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A.x;
	leftB = B.x;
	rightA = A.x + A.w;
	rightB = B.x + B.w;
	topA = A.y;
	topB = B.y;
	bottomA = A.y + A.h;
	bottomB = B.y + B.h;

	if (rightA >= leftB && bottomA >= bottomB || topA <= topB) {

	}

}*/
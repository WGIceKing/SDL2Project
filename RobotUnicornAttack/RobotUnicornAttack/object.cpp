#include"object.h"

Object::Object() {
	Tex = NULL;
}

SDL_Texture* Object::getTexture() {
	return Tex;
}

SDL_Rect& Object::getSource() {
	return source;
}

SDL_Rect& Object::getDestination() {
	return destination;
}

void Object::setSource(int x, int y, int w, int h) {
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}

void Object::setDestination(int x, int y, int w, int h) {
	destination.x = x;
	destination.y = y;
	destination.w = w;
	destination.h = h;
}

void Object::CreateTexture(const char* filedir, SDL_Renderer* ren) {
	Tex = TextureManager::Texture(filedir, ren);
}
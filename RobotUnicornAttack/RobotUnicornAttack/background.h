#pragma once
#include"object.h"

class Background :public Object {
public:
	void Render(SDL_Renderer* ren);
};
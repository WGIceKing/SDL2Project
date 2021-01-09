#pragma once
#include"object.h"

class Fairy :public Object {
private:
	int xPos;
	int yPos;
	int swingLimitUp;
	int swingLimitDown;
	int swingValue = 150;
	bool direction = false; //false - go up, true - go down
	SDL_Texture* Texture;
	SDL_Texture* Particle1;
	SDL_Texture* Particle2;
	SDL_Texture* Particle3;
	SDL_Texture* Particle4;
	double scrollingSpeed = 6;
	double flyingSpeed = 3;
	int animation = 0;
	bool taken = false;

public:
	void setXY(int x, int y);
	void setSwingLimit();
	void setScrollingSpeed(int x);
	int getX();
	int getY();
	void Update();
	void setTaken(bool taken1);
	bool getTaken();
	void Render(SDL_Renderer* ren);
	void CreateTexture(const char* filedir, SDL_Renderer* renderer);
	void CreateParticle1(const char* filedir, SDL_Renderer* renderer);
	void CreateParticle2(const char* filedir, SDL_Renderer* renderer);
	void CreateParticle3(const char* filedir, SDL_Renderer* renderer);
	void CreateParticle4(const char* filedir, SDL_Renderer* renderer);
};

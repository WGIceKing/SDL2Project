#pragma once
#include"object.h"

class Player:public Object{
private:
	double gravity = 0.5;
	int yPos = 300;
	int xPos = 26;
	int gravityTurnedOff = 0;
	int jumpCounts = 0;

	bool duringJump = false;
	double accelerator = 0;
	double accelerator2 = 0;
	double jumpTick = -15;
	double jumpTimer;
	double lastJump = 0;
	double jumpStart;

	double force = 0.5;
	bool duringDash = false;
	double Dashaccelerator = 0;
	double Dashaccelerator2 = 0;
	double DashTick = -5;
	double DashTimer;
	double lastDash = 0;
	int animation;
	SDL_Texture* Texture1;
	SDL_Texture* Texture2;
	SDL_Texture* Texture3;
	SDL_Texture* JumpTexture;

public:
	void Update();
	void GetJumpTime();
	void Jump();
	int getXPos();
	int getYPos();
	bool JumpStatus();
	void Render(SDL_Renderer* ren);
	void setXY(int x, int y);
	void JumpOperations();
	void GravityTurnedOfF();
	void SetGravity(int x);
	void StopGravity();
	void StopForce();
	void CreateTexture1(const char* filedir, SDL_Renderer* renderer);
	void CreateTexture2(const char* filedir, SDL_Renderer* renderer);
	void CreateTexture3(const char* filedir, SDL_Renderer* renderer);
	void CreateJumpTexture(const char* filedir, SDL_Renderer* renderer);
};
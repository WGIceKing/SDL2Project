#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"player.h"
#include"background.h"
#define _CRT_SECURE_NO_WARNINGS
#include"obstacle.h"
#include"textManager.h"
#include"collisionManager.h"
#include"platform.h"
#include"fairy.h"
#include"star.h"
#include"menu.h"

class GameLoop {
private:
	int platformNumber;
	int obstacleNumber;
	int fairyNumber;
	int starNumber;

	int xPosFilePlatform;
	int yPosFilePlatform;
	int* xPossitionPlatform = NULL;
	int* yPossitionPlatform = NULL;

	int xPosFileObstacle;
	int yPosFileObstacle;
	int* xPossitionObstacle = NULL;
	int* yPossitionObstacle = NULL;

	int xPosFileFairy;
	int yPosFileFairy;
	int* xPossitionFairy = NULL;
	int* yPossitionFairy = NULL;

	int xPosFileStar;
	int yPosFileStar;
	int* xPossitionStar = NULL;
	int* yPossitionStar = NULL;

	Player p;
	Background b;
	Obstacle* obstacleList = NULL;
	Platform* platformList = NULL;
	Fairy* fairyList = NULL;
	Star* starList = NULL;
	Menu startMenu;

	TextManager time;
	TextManager score;

	const int HEIGHT = 640;
	const int WIDTH = 800;
	int scoreCount = 0;
	int currentlyCollidedWith;
	bool GameStatus;
	bool OnPlatform = false;
	bool* collidedWithFairy = NULL;
	bool* collidedWithStar = NULL;
	bool* particleAnimation = NULL;
	bool collidable = true;
	bool duringDash = false;
	double dashStart;
	double dashLimit = 0;
	double worldTime = 0;

	SDL_Window* window;
	SDL_Event event;
	SDL_Renderer* renderer;
	FILE* fp;

public:

	GameLoop();
	bool getGameStatus();
	void CreateStartMenu();
	void OpenLevelFile(FILE* fp);
	void CreatePlatformList(int platformNumber);
	void CreateObstacleList(int obstacleNumber);
	void CreateFairyList(int fairyeNumber);
	void CreateStarList(int starNumber);
	void Update();
	void CollisionDetection(bool OnPlatform);
	void SetDefaultPositions();
	void SetWorldTime(double x);
	void ResetValues();
	void CreateTextures();
	void Init();
	void Event();
	void Render();
	void Clear();
};
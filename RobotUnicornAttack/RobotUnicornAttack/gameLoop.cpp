#define _CRT_SECURE_NO_WARNINGS
#include"gameLoop.h"
#include <cmath>
#include <stdio.h>

GameLoop::GameLoop() {
	window = NULL;
	renderer = NULL;
	GameStatus = false;
}

bool GameLoop::getGameStatus() {
	return GameStatus;
}

void GameLoop::Init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_CreateWindow("Robot Unicorn Attack", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

	OpenLevelFile(fp);

	CreatePlatformList(platformNumber);
	CreateObstacleList(obstacleNumber);
	CreateFairyList(fairyNumber);
	CreateStarList(starNumber);

	SetDefaultPositions();
	CreateTextures();
}

void GameLoop::CreateStartMenu() {
	startMenu.Init(renderer);
	while (!(startMenu.getClicked())) {
		if (startMenu.MenuEvent(event) == -1) {
			GameStatus = false;
			break;
		}
		SDL_RenderClear(renderer);
		startMenu.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}

void GameLoop::SetDefaultPositions() {
	p.setSource(0, 0, 64, 64);
	p.setDestination(10, HEIGHT / 2, 64 * 2, 64 * 2);
	p.setXY(26, 300);

	for (int i = 0; i < obstacleNumber; i++) {
		obstacleList[i].setSource(10, 10, 624, 418);
		obstacleList[i].setDestination(10, 10, 150, 200);
		obstacleList[i].setXY(xPossitionObstacle[i], yPossitionObstacle[i]);
	}

	for (int i = 0; i < platformNumber; i++) {
		platformList[i].setSource(10, 10, 900, 470);
		//platformList[i].setSource(0, 0, 1306, 232);
		platformList[i].setDestination(-10, 350, 810, 100);
		platformList[i].setXY(xPossitionPlatform[i], yPossitionPlatform[i]);
	}

	for (int i = 0; i < fairyNumber; i++) {
		fairyList[i].setSource(0, 0, 1200, 1200);
		fairyList[i].setDestination(10, 10, 60, 60);
		fairyList[i].setXY(xPossitionFairy[i], yPossitionFairy[i]);
		fairyList[i].setSwingLimit();
	}

	for (int i = 0; i < starNumber; i++) {
		starList[i].setSource(10, 10, 300, 300);
		starList[i].setDestination(10, 10, 150, 150);
		starList[i].setXY(xPossitionStar[i], yPossitionStar[i]);
	}
}

void GameLoop::CreateTextures() {
	if (!window) {
		std::cout << "Window error" << std::endl;
	}
	else {
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			GameStatus = true;
			p.CreateTexture("Textures/horse2.png", renderer);
			p.CreateTexture1("Textures/horse3.png", renderer);
			p.CreateTexture2("Textures/horse4.png", renderer);
			p.CreateTexture3("Textures/horse1.png", renderer);
			p.CreateJumpTexture("Textures/horseJump.png", renderer);
			b.CreateTexture("Textures/background.jpg", renderer);
			for (int i = 0; i < obstacleNumber; i++) {
				obstacleList[i].CreateTexture("Textures/stalagmite.jpg", renderer);
			}

			for (int i = 0; i < platformNumber; i++) {
				platformList[i].CreateTexture("Textures/platformFinal.png", renderer);
			}

			for (int i = 0; i < fairyNumber; i++) {
				fairyList[i].CreateTexture("Textures/fairy.png", renderer);
				fairyList[i].CreateParticle1("Textures/particle1.png", renderer);
				fairyList[i].CreateParticle2("Textures/particle2.png", renderer);
				fairyList[i].CreateParticle3("Textures/particle3.png", renderer);
				fairyList[i].CreateParticle4("Textures/particle4.png", renderer);
				collidedWithFairy[i] = false;
				particleAnimation[i] = false;
			}

			for (int i = 0; i < starNumber; i++) {
				starList[i].CreateTexture("Textures/starObstacle.png", renderer);
				collidedWithStar[i] = false;
			}

			time.CreateFont("Fonts/calibrib.ttf", 24);
			score.CreateFont("Fonts/calibrib.ttf", 24);
		}
	}
}


void GameLoop::OpenLevelFile(FILE* fp) {
	fp = fopen("Levels/lvl1.txt", "r");
	fscanf(fp, "%d %d %d %d", &platformNumber, &obstacleNumber, &fairyNumber, &starNumber);

	xPossitionPlatform = (int*)malloc(platformNumber * sizeof(int));
	yPossitionPlatform = (int*)malloc(platformNumber * sizeof(int));
	
	xPossitionObstacle = (int*)malloc(obstacleNumber * sizeof(int));
	yPossitionObstacle = (int*)malloc(obstacleNumber * sizeof(int));

	xPossitionFairy = (int*)malloc(fairyNumber * sizeof(int));
	yPossitionFairy = (int*)malloc(fairyNumber * sizeof(int));

	xPossitionStar = (int*)malloc(starNumber * sizeof(int));
	yPossitionStar = (int*)malloc(starNumber * sizeof(int));

	collidedWithFairy = (bool*)malloc(fairyNumber * sizeof(bool));
	collidedWithStar = (bool*)malloc(starNumber * sizeof(bool));
	particleAnimation = (bool*)malloc(fairyNumber * sizeof(bool));


	for (int i = 0; i < platformNumber; i++) {
		fscanf(fp, "%d %d", &xPossitionPlatform[i], &yPossitionPlatform[i]);
	}

	for (int i = 0; i < obstacleNumber; i++) {
		fscanf(fp, "%d %d", &xPossitionObstacle[i], &yPossitionObstacle[i]);
	}

	for (int i = 0; i < fairyNumber; i++) {
		fscanf(fp, "%d %d", &xPossitionFairy[i], &yPossitionFairy[i]);
	}

	for (int i = 0; i < starNumber; i++) {
		fscanf(fp, "%d %d", &xPossitionStar[i], &yPossitionStar[i]);
	}

	fclose(fp);
}

void GameLoop::CreatePlatformList(int platformNumber) {
	platformList = new Platform[platformNumber];
	for (int i = 0; i < platformNumber; i++) {
		platformList[i] =  Platform();
	}
}

void GameLoop::CreateObstacleList(int obstacleNumber) {
	obstacleList = new Obstacle[obstacleNumber];
	for (int i = 0; i < obstacleNumber; i++) {
		obstacleList[i] = Obstacle();
	}
}

void GameLoop::CreateFairyList(int fairyNumber) {
	fairyList = new Fairy[fairyNumber];
	for (int i = 0; i < fairyNumber; i++) {
		fairyList[i] = Fairy();
	}
}

void GameLoop::CreateStarList(int starNumber) {
	starList = new Star[starNumber];
	for (int i = 0; i < starNumber; i++) {
		starList[i] = Star();
	}
}

void GameLoop::Event() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		GameStatus = false;
	}
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			GameStatus = false;
		}
		else if (event.key.keysym.sym == SDLK_z && event.key.repeat == 0) {
			if (!p.JumpStatus()) {
				p.GetJumpTime();
				p.Jump();
			}
			else {
				p.Update();
			}
		}
		else if (event.key.keysym.sym == SDLK_x) {
			dashStart = SDL_GetTicks();
			duringDash = true;
			for (int i = 0; i < platformNumber; i++) {
				platformList[i].setScrollingSpeed(16);
			}
			for (int i = 0; i < obstacleNumber; i++) {
				obstacleList[i].setScrollingSpeed(16);
			}
			for (int i = 0; i < fairyNumber; i++) {
				fairyList[i].setScrollingSpeed(16);
			}
			for (int i = 0; i < starNumber; i++) {
				starList[i].setScrollingSpeed(16);
			}
		}
		else if (event.key.keysym.sym == SDLK_n) {
			p.StopGravity();
			SetDefaultPositions();
			ResetValues();
			worldTime = 0;
		}
	}
	if (event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == SDLK_x) {
			duringDash = false;
			for (int i = 0; i < platformNumber; i++) {
				platformList[i].setScrollingSpeed(6);
			}
			for (int i = 0; i < obstacleNumber; i++) {
				obstacleList[i].setScrollingSpeed(6);
			}
			for (int i = 0; i < fairyNumber; i++) {
				fairyList[i].setScrollingSpeed(6);
			}
			for (int i = 0; i < starNumber; i++) {
				starList[i].setScrollingSpeed(6);
			}
		}
	}
}

void GameLoop::Update() {
	scoreCount = scoreCount + 1;

	std::string t;
	t = "Time: " + std::to_string(worldTime);
	time.Text(t, 0, 0, 0, renderer);

	std::string s;
	s = "Score: " + std::to_string(scoreCount);
	score.Text(s, 0, 0, 0, renderer);

	p.Update();

	if (duringDash) {
		p.StopGravity();
		p.GravityTurnedOfF();
	}

	if (p.getYPos() > 1500) {
		p.StopGravity();
		SetDefaultPositions();
		SDL_Delay(1000);
	}

	for (int i = 0; i < obstacleNumber; i++) {
		obstacleList[i].Update();
	}

	for (int i = 0; i < platformNumber; i++) {
		platformList[i].Update();
	}

	for (int i = 0; i < fairyNumber; i++) {
		fairyList[i].Update();
	}

	for (int i = 0; i < starNumber; i++) {
		starList[i].Update();
	}
	CollisionDetection(OnPlatform);
}

void GameLoop::CollisionDetection(bool OnPlatform) {
	
	for (int i = 0; i < platformNumber; i++) {
		if (CollisionManager::CheckCollisionBellow(p.getDestination(), platformList[i].getDestination())) {
			p.StopGravity();
			p.GravityTurnedOfF();
		}
	}

	for (int i = 0; i < obstacleNumber; i++) {
		if (CollisionManager::CheckCollision(&p.getDestination(), &obstacleList[i].getDestination()) && collidable) {
			p.StopGravity();
			SetDefaultPositions();
			SDL_Delay(1000);
		}
	}

	for (int i = 0; i < fairyNumber; i++) {
		if (CollisionManager::CheckCollision(&p.getDestination(), &fairyList[i].getDestination()) && !(collidedWithFairy[i])) {
			scoreCount = scoreCount + 500;
			collidedWithFairy[i] = true;
		}
	}

	for (int i = 0; i < starNumber; i++) {
		if (CollisionManager::CheckCollision(&p.getDestination(), &starList[i].getDestination()) && !duringDash && !(collidedWithStar[i])) {
			/*p.StopGravity();
			SetDefaultPositions();
			SDL_Delay(1000);*/
			GameStatus = false;
		}
		else if (CollisionManager::CheckCollision(&p.getDestination(), &starList[i].getDestination()) && duringDash && !(collidedWithStar[i])) {
			scoreCount = scoreCount + 2000;
			collidedWithStar[i] = true;
		}
	}
}

void GameLoop::Render() {
	SDL_RenderClear(renderer);
	b.Render(renderer);
	p.Render(renderer);
	for (int i = 0; i < obstacleNumber; i++) {
		obstacleList[i].Render(renderer);
	}

	for (int i = 0; i < platformNumber; i++) {
		if (platformList[platformNumber - 1].getX() < -800) {
			SetDefaultPositions();
		}
		else {
			platformList[i].Render(renderer);
		}
	}

	for (int i = 0; i < fairyNumber; i++) {
		if (!(collidedWithFairy[i])) {
			fairyList[i].Render(renderer);
		}
	}

	for (int i = 0; i < starNumber; i++) {
		if (!(collidedWithStar[i])) {
			starList[i].Render(renderer);
		}
	}

	time.Render(renderer, WIDTH / 2, 100);
	score.Render(renderer, WIDTH / 2, 120);
	SDL_RenderPresent(renderer);
}

void GameLoop::SetWorldTime(double x) {
	worldTime = x;
}

void GameLoop::ResetValues() {
	scoreCount = 0;
	worldTime -= worldTime;
}

void GameLoop::Clear() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
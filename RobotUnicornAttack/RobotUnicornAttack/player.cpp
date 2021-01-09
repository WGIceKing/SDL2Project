#include"player.h"
#include"gameLoop.h"

void Player::Render(SDL_Renderer* renderer) {
	animation++;
	if (duringJump == true) {
		if (animation <= 180) {
			SDL_RenderCopyEx(renderer, JumpTexture, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		if (animation > 180) {
			animation = 0;
		}
	}
	else {

		if (animation < 10) {
			SDL_RenderCopyEx(renderer, getTexture(), &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation >= 10 && animation <= 20) {
			SDL_RenderCopyEx(renderer, Texture1, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation > 20 && animation <= 30) {
			SDL_RenderCopyEx(renderer, Texture2, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		else if (animation > 30) {
			SDL_RenderCopyEx(renderer, Texture3, &getSource(), &getDestination(), 0, NULL, SDL_FLIP_NONE);
		}
		if (animation > 40) {
			animation = 0;
		}
	}
}

void Player::GravityTurnedOfF() {
	gravityTurnedOff++;
	jumpCounts = 0;
}

void Player::GetJumpTime() {
	jumpStart = SDL_GetTicks();
}

int Player::getXPos() {
	return xPos;
}

int Player::getYPos() {
	return yPos;
}

void Player::setXY(int x, int y) {
	xPos = x;
	yPos = y;
}

void Player::SetGravity(int x) {
	gravityTurnedOff = x;
}

void Player::StopGravity() {
	if (gravityTurnedOff >= 1) {
		accelerator = 0;
		accelerator2 = 0;
		setDestination(xPos, yPos, 64 * 2, 64 * 2);
	}
}

void Player::StopForce() {
	xPos = 25;
	Dashaccelerator = 0;
	Dashaccelerator2 = 0;
	setDestination(xPos, yPos, 64 * 2, 64 * 2);
}

void Player::Update() {
	JumpOperations();
}

void Player::JumpOperations() {
	//JUMP
	if (duringJump == true) {
		//std::cout << "inJump" << std::endl;
	}

	if (duringJump == true) {
		//std::cout << "inJump" << std::endl;
	}

	else {
		accelerator = accelerator + 0.025;
		accelerator2 = accelerator2 + 0.025;
		yPos = yPos + gravity + accelerator + accelerator2;
		setDestination(xPos, yPos, 64 * 2, 64 * 2);
	}

	if (JumpStatus()) {
		accelerator = 0;
		accelerator2 = 0;
		accelerator = accelerator + 0.025;
		accelerator2 = accelerator2 + 0.025;
		jumpTick = jumpTick + gravity;
		yPos = yPos + gravity + accelerator + jumpTick + accelerator2;
		setDestination(xPos, yPos, 64 * 2, 64 * 2);
		if (jumpTick > 0) {
			duringJump = false;
			jumpTick = -15;
		}
	}
	else {
		duringJump = false;
		accelerator = accelerator + 0.025;
		accelerator2 = accelerator2 + 0.025;
		yPos = yPos + gravity + accelerator + accelerator2;
		setDestination(xPos, yPos, 64 * 2, 64 * 2);
	}
}

void Player::Jump() {
	if (jumpCounts < 1) {
		duringJump = true;
		jumpCounts++;
		gravityTurnedOff = 0;
		accelerator = 0;
		accelerator2 = 0;
	}
	else {
		Update();
	}
}

bool Player::JumpStatus() {
	return duringJump;
}

void Player::CreateTexture1(const char* filedir, SDL_Renderer* renderer) {
	Texture1 = TextureManager::Texture(filedir, renderer);
}

void Player::CreateTexture2(const char* filedir, SDL_Renderer* renderer) {
	Texture2 = TextureManager::Texture(filedir, renderer);
}

void Player::CreateTexture3(const char* filedir, SDL_Renderer* renderer) {
	Texture3 = TextureManager::Texture(filedir, renderer);
}

void Player::CreateJumpTexture(const char* filedir, SDL_Renderer* renderer) {
	JumpTexture = TextureManager::Texture(filedir, renderer);
}
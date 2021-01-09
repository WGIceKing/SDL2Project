#include"gameLoop.h"
#include"player.h"

GameLoop* g = new GameLoop();

int main(int argc, char** argv) {

	double first;
	double last = 0;

	double delta;
	double worldTime = 0;
	int t1, t2;

	g->Init();
	g->CreateStartMenu();
	t1 = SDL_GetTicks();
	while (g->getGameStatus()) {

		t2 = SDL_GetTicks();
		delta = (t2 - t1) * 0.001;
		t1 = t2;
		worldTime += delta;
		g->SetWorldTime(worldTime);

		g->Render();
		g->Event();
		g->Update();
		first = SDL_GetTicks();
		if (first - last < 15) {
			SDL_Delay(15 - (first - last));
			//std::cout << 1000 / (16.7 - (first - last)) + (first - last) << std::endl;
		}
		last = first;
	}
	g->Clear();
	return 0;
}



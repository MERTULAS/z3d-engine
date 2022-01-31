#include "engine/Zed_Engine.h"

Zed_Engine* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Zed_Engine();
	game->Init("Z3D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

	while (game->Running()) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();
	return 0;
}

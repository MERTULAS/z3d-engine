#include "Zed_Engine.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Zed_Engine::Zed_Engine() {
	renderer = nullptr;
	window = nullptr;
	this->isRunning = NULL;
	this->cnt = 0;
}

Zed_Engine::~Zed_Engine() {

}

void Zed_Engine::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if (window) {
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}

	SDL_Surface* tmpSurface = IMG_Load("src/assets/untitled.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Zed_Engine::HandleEvents() {
	SDL_Event event;    
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		this->isRunning = false;
		break;
	default:
		break;
	}
}

void Zed_Engine::Update() {
	cnt++;

	destR.h = 32;
	destR.w = 32;
	destR.x = cnt >> 1;
}

void Zed_Engine::Render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);

	SDL_RenderPresent(renderer);
}

void Zed_Engine::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;

	std::cout << cnt << std::endl;
}
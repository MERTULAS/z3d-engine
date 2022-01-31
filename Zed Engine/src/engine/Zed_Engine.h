#pragma once
#ifndef  Zed_Engine_hpp
#define Zed_Engine_hpp
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Zed_Engine {
private:
	int cnt;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Zed_Engine();
	~Zed_Engine();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running() { return this->isRunning; }
};

#endif // ! Zed_Engine_hpp

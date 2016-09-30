#include "graphics.h"

/********************************************
** Graphics
** Constructor
********************************************/
Graphics::Graphics()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

/********************************************
** ~Graphics
** Destructor
********************************************/
Graphics::~Graphics()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
#include "game.h"

Game::Game()
{
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
			}
		}
	}
	SDL_Quit();
};

Game::~Game()
{

}
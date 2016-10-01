#include "game.h"
#include "graphics.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Graphics graphics;

	bool quit = false;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.h = 400;
	sourceRect.w = 600;
	destRect.x = 100;
	destRect.y = 100;
	destRect.h = 400;
	destRect.w = 600;

	SDL_Texture* texture = graphics.loadTexture("../PongFromScratch/Content/vault-boy.png");

	while (!quit)
	{
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}
		}
		graphics.render(texture, &sourceRect, &destRect);
	}
	
}

Game::~Game()
{

}
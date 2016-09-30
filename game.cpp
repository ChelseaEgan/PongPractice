#include "game.h"
#include "graphics.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Graphics graphics;
	
	this->ball = Ball(graphics, "../PongFromScratch/Content/ball.png", 0, 0, 28, 28, 100, 100);

	bool quit = false;

	while (!quit)
	{
		if(SDL_PollEvent(&event))
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
		this->draw(graphics);
	}
	SDL_Quit();
};

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	this->ball.draw(graphics, 100, 100);
	graphics.flip();
}

Game::~Game()
{

}
#include "game.h"
#include "graphics.h"
#include "input.h"

Game::Game()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Call game initialization
	this->gameLoop();
}

void Game::gameLoop()
{
	Graphics graphics;

	Input input;

	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//game loop:
	while (true)
	{
		input.beginNewFrame();

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN) //key has been pressed
			{
				if (event.key.repeat == 0) //makes sure key is not held down
				{
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) //key has been released
			{
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) //when program ends or user clicks “x”
			{
				return; //window closes and game loop ends
			}
			if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) //escape key was pressed
			{
				return; //window closes and game loop ends
			}
		}
				
		/*this->draw(graphics);*/
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear(); //clear screen
	this->_ball.draw(graphics);
	graphics.flip(); //draw to screen
}

Game::~Game()
{}
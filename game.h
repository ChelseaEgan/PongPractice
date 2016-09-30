#ifndef GAME_H
#define GAME_H

/********************************************
** Game Class
** Handles main game loop
********************************************/

#include <SDL.h>
#include<SDL_image.h>

#include "graphics.h"
#include "ball.h"

class Game
{
private:
	SDL_Event event;
	Ball ball;
	void draw(Graphics &graphics);
public:
	Game();
	~Game();

};

#endif // !GAME_H

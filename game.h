#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include"ball.h"
#include "paddles.h"

class Game
{
private:
	Ball _ball;
public:
	Game();
	void gameLoop();
	void draw(Graphics &graphics);
	~Game();
};

#endif
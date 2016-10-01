#ifndef GAME_H
#define GAME_H

/********************************************
** Game Class
** Handles main game loop
********************************************/

#include <SDL.h>
#include<SDL_image.h>

#include "graphics.h"

class Game
{
private:
	SDL_Rect sourceRect;
	SDL_Rect destRect;
public:
	Game();
	~Game();

};

#endif // !GAME_H

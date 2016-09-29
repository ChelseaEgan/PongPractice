#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

/********************************************
** Graphics Class
** Handles logic for graphics and SDL
********************************************/

class Graphics
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
public:
	Graphics();
	~Graphics();
};

#endif // !GRAPHICS_H

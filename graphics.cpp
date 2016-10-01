#include "graphics.h"

#include <SDL.h>
#include <SDL_image.h>

#include<iostream>
/********************************************
** Graphics
** Constructor: creates window and renderer
********************************************/
Graphics::Graphics()
{
	//create a centered window of size 800x600
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (window == NULL)
	{
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
	}
	//create the renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
	}
	//set the size of the renderer to the same size as the window
	SDL_RenderSetLogicalSize(renderer, 800, 600);
	//set color of renderer to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

/********************************************
** ~Graphics
** Destructor: destroys window and renderer
********************************************/
Graphics::~Graphics()
{
	//destroy window
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;

	//quit SDL
	IMG_Quit();
	SDL_Quit();
}

/********************************************
** SDL_Renderer* getRenderer
** Returns renderer for other functions to 
** use
********************************************/
SDL_Renderer* Graphics::getRenderer() const
{
	return this->renderer;
}

/********************************************
** SDL_Texture* loadTexture
** Loads a PNG image to the renderer
********************************************/
SDL_Texture* Graphics::loadTexture(const std::string &str)
{
	texture = IMG_LoadTexture(this->renderer, str.c_str());

	if (texture == NULL) //if the image does not load
	{
		std::cout << "Failed to load texture " << str << "error: " << SDL_GetError() << std::endl;
		return NULL;
	}

	return this->texture;

}
/********************************************
** void render
** renders the loaded texture to the window
********************************************/
void Graphics::render(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect*destRect)
{
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, texture, sourceRect, destRect);
	SDL_RenderPresent(this->renderer);
}

/********************************************
** void clear
** Clears the renderer
********************************************/
void Graphics::clear()
{
	SDL_RenderClear(this->renderer);
}
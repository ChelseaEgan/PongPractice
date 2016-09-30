#include "graphics.h"

#include <SDL.h>
#include <SDL_image.h>

#include<iostream>
/********************************************
** Graphics
** Constructor
********************************************/
Graphics::Graphics()
{
	SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

/********************************************
** ~Graphics
** Destructor
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

SDL_Texture* Graphics::loadImage(const std::string &filePath)
{
	surface = IMG_Load(filePath.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->renderer);
}
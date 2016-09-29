/***********************************************
** Graphics Class
** Holds all info dealing with graphics for the
** game
***********************************************/
#include "graphics.h"

#include <SDL.h>
#include <SDL_image.h>

/***********************************************
** Graphics Constructor
** Initializes window and renderer
***********************************************/
Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Pong");
}

/***********************************************
** ~Graphics Destructor
** Destroys window
***********************************************/

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}

/***********************************************
** SDL_Surface* loadImage
** loads image into the _spriteSheets map if it
** doesn't already exist
***********************************************/
SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	if (this->_spriteSheets.count(filePath) == 0) //check if it has already been loaded
	{
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str()); //load image
	}
	return this->_spriteSheets[filePath]; //returns image
}

/*********************************************************
* void blitSurface
* Draws images (source) to a certain part of the screen
* based on destinationRectangle
*********************************************************/
void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

/*********************************************************
* void flip
* Renders everything to the screen
*********************************************************/
void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

/*********************************************************
* void clear
* Clears the screen
*********************************************************/
void Graphics::clear()
{
	SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->_renderer);
}

/***********************************************
** SDL_Renderer* getRenderer
** returns pointer to the renderer
***********************************************/
SDL_Renderer* Graphics::getRenderer() const
{
	return this->_renderer;
}
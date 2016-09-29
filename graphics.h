#ifndef GRAPHICS_H
#define GRAPHICS_H

/***********************************************
** Graphics Class
** Creates and destroys the window and renderer
***********************************************/
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Graphics
{
private:
	SDL_Window* _window; //where the renderer draws to
	SDL_Renderer* _renderer; //what draws to the window
	std::map<std::string, SDL_Surface*> _spriteSheets; //hold in graphics object every sprite sheet loaded in game

public:
	/***********************************************
	** Graphics Constructor
	** Initializes window and renderer
	***********************************************/
	Graphics();

	/***********************************************
	** ~Graphics Destructor
	** Destroys window
	***********************************************/
	~Graphics();

	/***********************************************
	** SDL_Surface* loadImage
	** loads image into the _spriteSheets map if it
	** doesn't already exist
	***********************************************/
	SDL_Surface* loadImage(const std::string &filePath);

	/*********************************************************
	* void blitSurface
	* Draws images (source) to a certain part of the screen
	* based on destinationRectangle
	*********************************************************/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*********************************************************
	* void flip
	* Renders everything to the screen
	*********************************************************/
	void flip();

	/*********************************************************
	* void clear
	* Clears the screen
	*********************************************************/
	void clear();

	/*********************************************************
	* SDL_Renderer* getRenderer
	* Returns the renderer
	*********************************************************/
	SDL_Renderer* getRenderer() const;
};

#endif

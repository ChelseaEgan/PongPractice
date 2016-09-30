#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>

#include<string>
#include <map>

struct SDL_Window;
struct SDL_Renderer; 

/********************************************
** Graphics Class
** Handles logic for graphics and SDL
********************************************/

class Graphics
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
public:
	Graphics();
	~Graphics();
	SDL_Texture* loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle);
	void flip();
	void clear();
	SDL_Renderer* getRenderer() const;
};

#endif // !GRAPHICS_H

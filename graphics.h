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
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
public:
	Graphics();
	~Graphics();
	SDL_Renderer* getRenderer() const;
	void clear();
	SDL_Texture* loadTexture(const std::string &str);
	void render(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect);
};

#endif // !GRAPHICS_H

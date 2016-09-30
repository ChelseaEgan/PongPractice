#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>

class Graphics;

#include <string>
#include <iostream>

class Ball
{
protected:
	SDL_Rect sourceRect;
	SDL_Texture* texture;
	float x, y;
public:
	Ball();
	Ball(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float x, float y);
	~Ball();
	void draw(Graphics &graphics, int x, int y);
};

#endif
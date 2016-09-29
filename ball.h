#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class Graphics;
/***********************************************
** Ball Class
** Position, direction and speed of ball
***********************************************/

class Ball
{
private:
	const float BALL_SPEED = 900;
	float x, y, width, height; //position and dimensions
	float dirx, diry; //direction of movement
	SDL_Texture* _spriteSheet;
	SDL_Rect _sourceRect;
public:
	Ball();
	Ball(Graphics &graphics, const std::string &filePath, float sourceX, float sourceY, float width, 
		float height, float posX, float posY);
	~Ball();
	void update(float delta);
	void draw(Graphics &graphics);
	void setDirection(float dirx, float diry);
};
#endif // !BALL_H

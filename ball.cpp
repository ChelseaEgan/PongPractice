#include "ball.h"
#include "graphics.h"

Ball::Ball()
{

}

Ball::Ball(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, 
	int height, float posX, float posY) :
	x(posX),
	y(posY)
{
	this->sourceRect.x = sourceX;
	this->sourceRect.y = sourceY;
	this->sourceRect.w = width;
	this->sourceRect.h = height;
	this->texture = graphics.loadImage(filePath);
	if (this->texture == NULL)
	{
		std::cout << "\nError: Unable to load image\n";
	}
}

Ball::~Ball()
{

}

void Ball::draw(Graphics &graphics, int x, int y)
{
	SDL_Rect destinationRectangle = { x, y, this->sourceRect.w, this->sourceRect.h };
	graphics.blitSurface(this->texture, &this->sourceRect, &destinationRectangle);
}
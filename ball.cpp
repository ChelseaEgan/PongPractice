#include "ball.h"
#include "graphics.h"
#include <cmath>
/***********************************************
** Ball Class
** Implementation
** Position, direction and speed of ball
***********************************************/

/***********************************************
** Ball
** default constructor
***********************************************/
Ball::Ball()
{
}

/***********************************************
** Ball
** constructor
** sets initial position, dimensions, direction
** and creates render
***********************************************/
Ball::Ball(Graphics &graphics, const std::string &filePath, float sourceX, float sourceY, float width, 
	float height, float posX, float posY) :
	x(posX),
	y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;
	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL)
	{
		std::cout << "\nError: unable to load image\n";
	}
}

/***********************************************
** Ball
** destructor
** destroys ball image
***********************************************/
Ball::~Ball()
{
}

/***********************************************
** void update
** Moves ball based on time
***********************************************/
void Ball::update(float delta)
{
}

/***********************************************
** void render
** sets the rectangle for the render
***********************************************/
void Ball::draw(Graphics &graphics)
{
	SDL_Rect destinationRectangle;
	destinationRectangle.x = (int)(x + 0.5f); //round float to nearest int
	destinationRectangle.y = (int)(y + 0.5f); //round float to nearest int
	destinationRectangle.w = this->_sourceRect.w;
	destinationRectangle.h = this->_sourceRect.h;
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

/***********************************************
** void setDirection
** normalizes direction vector and multiply with
** BALL_SPEED
***********************************************/
void Ball::setDirection(float dirx, float diry)
{
}
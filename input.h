#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL.h>
#include <SDL_image.h>

class Input
{
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
public:
	void beginNewFrame();
	void keyDownEvent(const SDL_Event &event);
	void keyUpEvent(const SDL_Event &event);
	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
};

#endif

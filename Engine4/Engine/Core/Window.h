#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include "Debug.h"
class Window
{
public:
	Window();
	~Window();
	bool OnCreate(std::string name_, int wight_, int height_);
	void OnDestroy();
	int GetWight() const;
	int GetHeight() const;
	SDL_Window* GetWindow() const;
private:
	void SetPreAttributes();
	void SetPostAttributes();
	int wight;
	int height;
	SDL_Window* window;
	SDL_GLContext context;
};

#endif // !WINDOW_H

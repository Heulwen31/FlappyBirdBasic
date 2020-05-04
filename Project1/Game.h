#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "GameObject.h"

class Game
{
public:
	Game();
	~Game();


	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void render2();
	void clean();
	bool VaCham();
	bool running() { return isRunning; }
	

	static SDL_Renderer* renderer;


	static SDL_Event event;

	
private:
	bool isRunning = false;
	SDL_Window* window;
	
};

#endif // !Game_h

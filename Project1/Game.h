#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
class Game
{
public:
	Game();
	~Game();


	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }


	static SDL_Renderer* renderer;

private:
	bool isRunning = false;
	SDL_Window* window;
	int cnt = 0;
};

#endif // !Game_h

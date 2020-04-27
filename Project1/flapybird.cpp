
#include "Game.h"
using namespace std;
Game* game = nullptr;

int main(int argc, char* argv[])
{
	int a = 100;
	const int FPS = 60;
	const int frameDelay = a / FPS;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("con cac", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Error\n";
	}
	Mix_Music* music = Mix_LoadMUS("audio/can.mp3");
	while (game->running() && game->VaCham() == false)
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		if (!Mix_PlayingMusic())
		{
			Mix_PlayMusic(music, -1);
		}
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	SDL_Delay(2000);
	game->render2();
	SDL_Delay(10000);
	game->clean();
	return 0;
}
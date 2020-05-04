
#include "Game.h"
using namespace std;
Game* game = nullptr;

int main(int argc, char* argv[])
{
	int a = 1000;
	const int FPS = 60;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Error\n";
	}
	Mix_Music* music = Mix_LoadMUS("audio/else.mp3");
	while (game->running() && game->VaCham() == false)
	{
		int frameDelay = a / FPS;
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
			cout << frameDelay - frameTime << endl;
			SDL_Delay((frameDelay - frameTime));
			if (frameDelay - frameTime >= 3)
			{
				a -= 1;
			}
		}
	}
	Mix_FreeMusic(music);
	SDL_Delay(2000);
	game->render2();
	SDL_Delay(2000);
	game->render2();
	return 0;
	
}
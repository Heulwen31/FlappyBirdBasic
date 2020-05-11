#include "Game.h"
using namespace std;
Game* game = nullptr;

int main(int argc, char* argv[])
{
game_again:
	int a = 1000;
	const int FPS = 60;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	game->render3();
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&game->event) != 0)
		{
			if (game->event.type == SDL_QUIT)
			{ 
				quit = true;
			}
			else if (game->event.type == SDL_KEYDOWN)
			{
				if (game->event.key.keysym.sym == SDLK_SPACE)
				{
					quit = true;
				}
			}
		}
	}

	Mix_ResumeMusic();
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

	Mix_PauseMusic();

	game->render2();
	bool x = false;
	while (!x)
	{
		while (SDL_PollEvent(&game->event) != 0)
		{
			if (game->event.type == SDL_QUIT)
			{
				quit = true;
				Mix_FreeMusic(music);
				game->clean();
			}
			else if (game->event.type == SDL_KEYDOWN)
			{
				if (game->event.key.keysym.sym == SDLK_SPACE)
				{
					quit = true;
					game->clean();
					goto game_again;
				}
				else if (game->event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
					game->clean();
				}
			}
		}
	}
	return 0;
	
}
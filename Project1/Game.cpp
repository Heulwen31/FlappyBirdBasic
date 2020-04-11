#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
using namespace std;

SDL_Texture* backgroud;
GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

Map* map;

Game::Game()
{
}
Game::~Game()
{
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Correct \n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "Correct Window\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "renderer correct\n";
		}
		isRunning = true;
	}
	backgroud = TextureManager::LoadTexture("image/bh.jpg");
	player = new GameObject("image/bird.png",0,0);
	map = new Map();
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

	player->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroud, NULL, NULL);
	map->DrawMap();
	
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

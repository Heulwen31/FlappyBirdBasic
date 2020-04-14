#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"


using namespace std;

SDL_Texture* backgroud;
GameObject* player;
Map* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


GameObject* enemy1;
GameObject* enemy2;
GameObject* enemy3;
GameObject* enemy4;
GameObject* enemy5;
GameObject* enemy6;
GameObject* enemy7;
GameObject* enemy8;
GameObject* enemy9;
GameObject* enemy10;

int x = 0;
int y = 320;

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
	backgroud = TextureManager::LoadTexture("image/bg.jpg");
	player = new GameObject("image/bird.png",x,y);
	enemy1 = new GameObject("image/enemy.png", 300, 150);
	enemy2 = new GameObject("image/enemy.png", 100, 100);
	enemy3 = new GameObject("image/enemy.png", 150, 30);
	enemy4 = new GameObject("image/enemy.png", 250, 400);
	enemy5 = new GameObject("image/enemy.png", 490, 320);
	enemy6 = new GameObject("image/enemy.png", 5600, 100);
	enemy7 = new GameObject("image/enemy.png", 600, 1600);
	enemy8 = new GameObject("image/enemy.png", 470, 274);
	enemy9 = new GameObject("image/enemy.png", 300, 284);
	enemy10 = new GameObject("image/enemy.png", 350, 10);
	map = new Map();
}
void Game::handleEvents()
{
	
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
	enemy1->Update_Enemy();
	enemy2->Update_Enemy();
	enemy3->Update_Enemy();
	enemy4->Update_Enemy();
	enemy5->Update_Enemy();
	enemy6->Update_Enemy();
	enemy7->Update_Enemy();
	enemy8->Update_Enemy();
	enemy9->Update_Enemy();
	enemy10->Update_Enemy();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroud, NULL, NULL);
	map->DrawMap();
	enemy1->Render();
	enemy2->Render();
	enemy3->Render();
	enemy4->Render();
	enemy5->Render();
	enemy6->Render();
	enemy7->Render();
	enemy8->Render();
	enemy9->Render();
	enemy10->Render();
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

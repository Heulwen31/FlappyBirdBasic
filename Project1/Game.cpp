#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"



using namespace std;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


SDL_Texture* backgroud;

SDL_Texture* bg;

// Người chơi
GameObject* player;


// Mỗi nguy hiểm
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


	// Load nền cóntinue
	backgroud = TextureManager::LoadTexture("image/bk.jpg");

	// load nen  kh game ket thuc
	bg = TextureManager::LoadTexture("image/go.jpg");

	//Nhân vật 
	player = new GameObject("image/bird.png",700,500);

	// Mối hiểm họa
	enemy1 = new GameObject("image/enemy.png", 300, rand() % 800 + 1);
	enemy2 = new GameObject("image/enemy.png", 100, rand() % 800 + 1);
	enemy3 = new GameObject("image/enemy.png", 150, rand() % 800 + 1);
	enemy4 = new GameObject("image/enemy.png", 250, rand() % 800 + 1);
	enemy5 = new GameObject("image/enemy.png", 490, rand() % 800 + 1);
	enemy6 = new GameObject("image/enemy.png", 5600,rand() % 800 + 1);
	enemy7 = new GameObject("image/enemy.png", 600, rand() % 800 + 1);
	enemy8 = new GameObject("image/enemy.png", 470, rand() % 800 + 1);
	enemy9 = new GameObject("image/enemy.png", 300, rand() % 800 + 1);
	enemy10 = new GameObject("image/enemy.png",350, rand() % 800 + 1);

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
;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, backgroud, NULL, NULL);
	
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

void Game::render2()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg, NULL, NULL);
	SDL_RenderPresent(renderer);
}



void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::VaCham()
{
	return player->Check(player->destRect, enemy1->destRect) == false 
	&& player->Check(player->destRect, enemy2->destRect) == false
	&& player->Check(player->destRect, enemy3->destRect) == false 
	&& player->Check(player->destRect, enemy4->destRect) == false 
	&& player->Check(player->destRect, enemy5->destRect) == false 
	&& player->Check(player->destRect, enemy6->destRect) == false 
	&& player->Check(player->destRect, enemy7->destRect) == false 
	&& player->Check(player->destRect, enemy8->destRect) == false 
	&& player->Check(player->destRect, enemy9->destRect) == false 
	&& player->Check(player->destRect, enemy10->destRect) == false ? false : true;
}




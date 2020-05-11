#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"


GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	int a = 2;
	if (xpos <= 800 && xpos >= 0 && ypos >= 0 && ypos <= 640)
	{
		if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_UP:
				ypos-=a;
                break;

            case SDLK_DOWN:
				ypos+=a;
                break;

            case SDLK_LEFT:
				xpos-=a;
                break;

            case SDLK_RIGHT:
				xpos+=a;
                break;

            default:
                break;
            }
        }
	}
	else if ((xpos < 0 || xpos > 800) && (ypos >= 0 && ypos <= 640))
	{
		if (xpos < 0)
		{
			xpos = 800;
		}
		else if (xpos > 800)
		{
			xpos = 0;
		}
	}
	else if ((ypos < 0 || ypos > 640) && (xpos >= 0 && xpos <= 800))
	{
		if (ypos < 0)
		{
			ypos = 640;
		}
		else if (ypos > 640)
		{
			ypos = 0;
		}
	}
	
    
	srcRect.h = 50;
	srcRect.w = 48;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::Update_Enemy()
{
	int a = 3;
	xpos-=a;
	if (xpos <= -32)
	{
		xpos = 800;
		ypos = rand() % 800 + 1;
	}
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

bool GameObject::Check(SDL_Rect& a, SDL_Rect& b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (bottomA <= topB) {
		return false;
	}
	if (topA >= bottomB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}
	return true;
}

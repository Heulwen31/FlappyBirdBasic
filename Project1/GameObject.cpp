#include "GameObject.h"
#include "TextureManager.h"


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
	if (xpos <= 800 && xpos >= 0)
	{
		if (Game::event.type == SDL_KEYDOWN)
        {
            //Select surfaces based on key press
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_UP:
				ypos--;
                break;

            case SDLK_DOWN:
				ypos++;
                break;

            case SDLK_LEFT:
				xpos--;
                break;

            case SDLK_RIGHT:
				xpos++;
                break;

            default:
                break;
            }
        }
	}
	else
	{
		if (xpos >= 800)
		{
			xpos = 0;
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
	xpos--;
	if (xpos == -32)
	{
		xpos = 800;
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

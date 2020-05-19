#pragma once
#ifndef TextureManger
#define TextureManger

#include "Game.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
	
};



#endif // !TextureManger



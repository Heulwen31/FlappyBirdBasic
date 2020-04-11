#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	Uint32 color_key = SDL_MapRGB(tempSurface->format, 0, 0xFF, 0xFF);
	SDL_SetColorKey(tempSurface, SDL_TRUE, color_key);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
}

#include <iostream>
#include "Texture.h"
#include "Text.h"

Texture::Texture(int width, int height)
{
	m_dimension.x = width;
	m_dimension.y = height;
}

bool Texture::Load(const std::string& filename, Screen& screen)
{
	SDL_Surface* TextureData = IMG_Load(filename.c_str());

	if (!TextureData)
	{
		std::cout << SDL_GetError() << std::endl;
		std::cout << "Error Loading Texture" << std::endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), TextureData);
	return true;
}

void Texture::Unload()
{
	SDL_DestroyTexture(m_texture);
}

void Texture::SetDimention(int width, int height)
{
	m_dimension.x = width;
	m_dimension.y = height;
}

void Texture::Render(Screen& screen, int x, int y)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.w = m_dimension.x;
	src.h = m_dimension.y;

	dst.x = x;
	dst.y = y;
	dst.w = m_dimension.x;
	dst.h = m_dimension.y;

	SDL_Point centrePoint;
	centrePoint.x = m_dimension.x / 2;
	centrePoint.y = m_dimension.y / 2;

	SDL_RenderCopyEx(screen.GetRenderer(), m_texture, &src, &dst, 0.0, &centrePoint, SDL_FLIP_NONE);

}

Vector<int> Texture::GetDimention()
{
	return m_dimension;
}
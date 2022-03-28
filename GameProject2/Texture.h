#pragma once
#include <string>
#include <SDL_image.h>
#include "Vector.h"
#include "Screen.h"

class Texture
{

public:

	Texture(int width = 0, int height = 0);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void SetDimention(int width, int height);
	void Render(Screen& screen, int x = 0, int y = 0);
	Vector<int> GetDimention();

private:

	SDL_Texture* m_texture = nullptr;
	Vector<int> m_dimension;

};


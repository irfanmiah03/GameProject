#pragma once
#include "Input.h"
#include "Screen.h"
#include "Texture.h"
#include "Vector.h"

class Player
{

public:

	Player(Screen& screen);
	~Player();

	void Update();
	bool Render(Screen& screen);

private:

	int m_velocity;

	Texture m_idle;
	Texture m_walk;
	Texture m_star;

	Vector<int> m_position;
	Vector<int> m_directionWalk;
	Vector<int> m_directionStand;

};

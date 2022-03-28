#include "Player.h"

//Player Constructor
Player::Player(Screen& screen)
{
	m_star.Load("../GameProject2/Assets/Images/star.PNG", screen);
	m_star.SetDimention(250, 250);
	m_position.x = 0;
	m_position.y = 665;

	m_velocity = 5;
}

//Player Destructor
Player::~Player()
{

}

//Player Update every frame
//Player Movements, Sprite Animations and Mechanics
void Player::Update()
{

	if (m_position.x > 1920 - m_star.GetDimention().x)
	{
		m_position.x = 1920 - m_star.GetDimention().x;
	}

	if (m_position.x < 0)
	{
		m_position.x = 0;
	}

	if (m_position.y > (1080 - 165) - m_star.GetDimention().y)
	{
		m_position.y = (1080 - 165) - m_star.GetDimention().y;
	}

	if (m_position.y < 0)
	{
		m_position.y = 0;
	}


	if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)
	{
		m_position.x = m_position.x + m_velocity;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)
	{
		m_position.x = m_position.x - m_velocity;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
	{
		m_position.y = m_position.y - m_velocity;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
	{
		m_position.y = m_position.y + m_velocity;
	}
}

//Player Render
//Updating Sprites on Screen
bool Player::Render(Screen& screen)
{
	m_star.Render(screen, m_position.x, m_position.y);

	return true;
}

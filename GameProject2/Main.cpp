#include <iostream>

#include "Background.h"
#include "Input.h"
#include "Music.h"
#include "Player.h"
#include "Screen.h"
#include "Texture.h"
#include "Text.h"

bool isGameRunning = true;
int x = 1920;
int y = 1080;
bool bond = false;

int main(int argc, char* argv[])
{
	// initializes the screen
	Screen screen;
	screen.Initialize();

	//Background background 1
	Texture background(1920, 1080);
	background.Load("../GameProject2/Assets/Images/background.PNG", screen);

	//Background background 2
	Texture background2(1920, 1080);
	background2.Load("../GameProject2/Assets/Images/background2.PNG", screen);

	//Player
	Player m_player(screen);


	Texture mushroom(250, 250);
	mushroom.Load("../GameProject2/Assets/Images/mushroom.PNG", screen);
	mushroom.SetDimention(250, 250);


	//coin.cpp
	//Texture mushroom(150, 150);
	//mushroom.Load("../assets/star.PNG", screen);
	//mushroom.SetDimention(x, y);
	//Player.PlayerTexture(screen);
	//added to player.cpp



	//in music.cpp
	Music music;
	music.Initialize();
	music.Load("../GameProject2/Assets/audio/bond.wav");
	music.SetVolume(0.5f);

	//text.cpp change 'score' to hp
	//change font website 1001 fonts
	Text score;
	score.Initiliaze();
	score.Load("../GameProject2/Assets/Fonts/AkutePersonalUse-Bold.otf");
	score.SetSize(350, 50);
	score.SetColor(0, 0, 0);
	score.SetString("Health: 100%");

	Text play;
	play.Initiliaze();
	play.Load("../GameProject2/Assets/Fonts/AkutePersonalUse-Bold.otf");
	play.SetSize(350, 50);
	play.SetColor(0, 0, 0);
	play.SetString("press 2 to play");


	// Main Game Loop
	while (isGameRunning)

	{
		//refreshes the screen
		screen.Refresh();

		//returns pointer to class
		Input::Instance()->Update();

		//closes window
		isGameRunning = !(Input::Instance()->IsWindowClosed());


		if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) == true)
		{
			music.Play();
		}

		//should go into player.cpp player keys


		if (Input::Instance()->IsKeyPressed(HM_KEY_2) == true)
		{
			bond = true;
			//music, inside parenthese is for a loop
			music.Play(/*Music::Loop:Ongoing*/);
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_1) == true)
		{
			bond = false;
		}


		if (bond == true)
		{
			//seconded background

			background2.Render(screen, 0, 0);
			m_player.Update();
			m_player.Render(screen);
			play.Render(screen, 100, 100);
			mushroom.Render(screen, 800, 285);

		}
		else if (bond == false)
		{
			//background

			background.Render(screen, 0, 0);
			score.Render(screen, 300, 300);

		}
		screen.Present();



	}

	// closes the game
	screen.Shutdown();
	music.Shutdown();
	return 0;
}



//sdl rect // box colider
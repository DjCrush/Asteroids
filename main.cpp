#include <SDL.h>
#include <SDL_audio.h>
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "MyGraphicsLib.h"

#define _USE_MATH_DEFINES 
#include <math.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int BPP = 4;
const int DEPTH = 32;


SDL_Surface* screen;

int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{

	SDL_Window* window = NULL;
	SDL_Event event;
	bool done = false;
	const Uint8 *keystate;
	int leftk, rightk, upk, downk, spacek;
	bool player_fire = false;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;
	window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!(screen = SDL_GetWindowSurface(window)))
	{
		SDL_Quit();
		return 1;
	}

	Player player(screen);
	Bullet bullet(screen);

	while (!done)
	{


		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) done = true;
	
		keystate = SDL_GetKeyboardState(NULL);
		for (int i = 0; i < 255; i++)
		{
			cout << keystate[i] << "  " << endl;
		}
		leftk = keystate[SDL_SCANCODE_LEFT];
		rightk = keystate[SDL_SCANCODE_RIGHT];
		downk = keystate[SDL_SCANCODE_DOWN];
		upk = keystate[SDL_SCANCODE_UP];
		spacek = keystate[SDL_SCANCODE_SPACE];
		if (leftk)
		{
			player.Rotate(-1);
		}

		if (rightk)
		{
			player.Rotate(1);
		}

		if (upk) 
		{ 
			player.Move(); 
		}

		if (spacek && !player_fire) 
		{
			bullet.AddBullet(player); 
			player_fire = true;
		}

		if (!spacek && player_fire)
		{
			player_fire = false;
		}


		ClearScreen(screen);
		player.Update();
		bullet.Update();
	

		SDL_UpdateWindowSurface(window);
		
	}

	SDL_Quit();
	return 0;

}

#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MyGraphicsLib.h"
#include <vector>
#include <cmath>

SDL_Surface* screen;
int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
	SDL_Window* window = NULL;
	SDL_Event event;
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;
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
	Player player;
	for (int i = 0; i < 10; i++)
	{
		enemies.push_back(new Enemy());
	}
	while (!done)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) done = true;
		keystate = SDL_GetKeyboardState(NULL);
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
			bullets.push_back(new Bullet(player.GetCoordX() + sin(player.GetAngle() * M_PI / 180) * 24, player.GetCoordY() - cos(player.GetAngle() * M_PI / 180) * 24, player.GetAngle()));
			player_fire = true;
		}
		if (!spacek && player_fire)
		{
			player_fire = false;
		}
		ClearScreen();
		for (auto it = bullets.begin(); it != bullets.end(); it++)
		{
			(*it)->Draw();
		}
		for (auto it = bullets.begin(); it != bullets.end();)
		{
			(*it)->Update();
			if ((*it)->GetCoordX() < 0 || (*it)->GetCoordX() > SCREEN_WIDTH - 1 || (*it)->GetCoordY() < 0 || (*it)->GetCoordY() > SCREEN_HEIGHT - 1)
			{
				it = bullets.erase(it);
				delete (*it);
			}
			else
			{
				it++;
			}
		}
		for (auto it = enemies.begin(); it != enemies.end(); it++)
		{
			(*it)->Draw();
			(*it)->Update();
		}
		player.Update();
		SDL_UpdateWindowSurface(window);
		SDL_Delay(10);
	}
	SDL_Quit();
	return 0;
}

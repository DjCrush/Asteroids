#include "Game.h"
#include <memory>
#undef main

constexpr double DEG = 0.01745329251994329576923690768489;

int main()
{
	std::unique_ptr<Game> game(new Game());
	game->init("Asteroids", 100, 100, 1800, 900, 0);
	while (game->gameIsRunning())
	{
		game->handleEvents();
		game->update();
		game->collides();
		game->render();
	}
	game->clean();
	return 0;
}

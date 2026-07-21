#ifndef GAME_H
#define GAME_H

#include <list>
#include <SDL.h>
#include <memory>
#include "Bullet.h"
#include "Ship.h"
#include "Asteroid.h"

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void handleEvents();
	void update();
	void collides();
	bool gameIsRunning() const;
	void render();
	void clean();
private:
	SDL_Window* m_pWindow = nullptr;
	SDL_Renderer* m_pRenderer = nullptr;
	bool m_bRunning = false;
	int m_iScreenWidth = 1800;
	int m_iScreenHeight = 900;
	Ship m_objShip;
	std::list<std::unique_ptr<Bullet>> m_lBullets;
	std::list<std::unique_ptr<Asteroid>> m_lAsteroids;
};
#endif // !GAME_H


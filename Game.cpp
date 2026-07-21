#include "Game.h"


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return false;
	}
	if ((m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags)) == nullptr)
	{
		return false;
	}
	if ((m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0)) == nullptr)
	{
		return false;
	}
	m_bRunning = true;
	m_iScreenWidth = width;
	m_iScreenHeight = height;
	for (int i = 0; i < 20; ++i)
	{
		m_lAsteroids.emplace_back(new Asteroid(m_pRenderer, 10, 10 * 5 * i, 40));
	}
	return true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_LEFT:
					m_objShip.setRotate(-1);
					break;
				case SDLK_RIGHT:
					m_objShip.setRotate(1);
					break;
				case SDLK_UP:
					m_objShip.setThrust(true, m_pRenderer);
					break;
				case SDLK_SPACE:
					m_lBullets.emplace_back(new Bullet(m_pRenderer, m_objShip.getCoordX(), m_objShip.getCoordY(), m_objShip.getAngle()));
					break;
			}
		}
		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_LEFT:
				case SDLK_RIGHT:
					m_objShip.setRotate(0);
					break;
				case SDLK_UP:
					m_objShip.setThrust(false, m_pRenderer);
					break;
			}
		}
	}
}

void Game::update()
{
	m_objShip.update();
	for (auto it = m_lBullets.begin(); it != m_lBullets.end();)
	{
		(*it)->update();
		double dBulX = (*it)->getCoordX();
		double dBulY = (*it)->getCoordY();
		if (dBulX < 0 || dBulY < 0 || dBulX > m_iScreenWidth || dBulY > m_iScreenHeight)
		{
			it = m_lBullets.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = m_lAsteroids.begin(); it != m_lAsteroids.end(); ++it)
	{
		(*it)->update();
	}

	collides();
}

void Game::collides()
{

	for (auto itBul = m_lBullets.begin(); itBul != m_lBullets.end();)
	{
		double dBX = (*itBul)->getCoordX();
		double dBY = (*itBul)->getCoordY();
		bool isErase = false;
		for (auto itAst = m_lAsteroids.begin(); itAst != m_lAsteroids.end(); ++itAst)
		{
			double dAX = (*itAst)->getCoordX();
			double dAY = (*itAst)->getCoordY();
			double dAR = (*itAst)->getRadius();
			if ((dAX - dBX) * (dAX - dBX) + (dAY - dBY) * (dAY - dBY) <= dAR * dAR)
			{
				itAst = m_lAsteroids.erase(itAst);
				if (dAR == 40)
				{
					m_lAsteroids.emplace_back(new Asteroid(m_pRenderer, dAX, dAY, 15));
					m_lAsteroids.emplace_back(new Asteroid(m_pRenderer, dAX, dAY, 25));
				}
				isErase = true;
				break;
			}
		}
		if (isErase)
		{
			itBul = m_lBullets.erase(itBul);
		}
		else
		{
			++itBul;
		}
	}
}

bool Game::gameIsRunning() const
{
	return m_bRunning;
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_pRenderer); // clear the renderer to the render color
	for (auto it = m_lBullets.begin(); it != m_lBullets.end(); ++it)
	{
		(*it)->render();
	}
	for (auto it = m_lAsteroids.begin(); it != m_lAsteroids.end(); ++it)
	{
		(*it)->render();
	}
	m_objShip.render(m_pRenderer);

	SDL_RenderPresent(m_pRenderer); // render to the screen
}

void Game::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
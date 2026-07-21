#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* renderer, int x, int y, int radius)
	: m_pRenderer(renderer),
	m_dCoordX(x),
	m_dCoordY(y),
	m_iRadius(radius)
{
	if (radius == 40)
	{
		int q = rand() % 4;
		switch (q)
		{
		case 0:
			m_dCoordX = 0;
			m_dCoordY = rand() % 900;
			m_ddX = (rand() % 5) / 30.0 + 0.15;
			m_ddY = (rand() % 10) / 30.0 - 0.5;
			break;
		case 1:
			m_dCoordX = rand() % 1800;
			m_dCoordY = 899;
			m_ddX = (rand() % 5) / 30.0 - 0.25;
			m_ddY = (rand() % 10) / 30.0 - 0.5;
			break;
		case 2:
			m_dCoordX = 1799;
			m_dCoordY = rand() % 900;
			m_ddX = (rand() % 5) / 30.0 - 0.15;
			m_ddY = (rand() % 10) / 30.0 - 0.5;
			break;
		case 3:
			m_dCoordX = rand() % 1800;
			m_dCoordY = 0;
			m_ddX = (rand() % 5) / 30.0 - 0.25;
			m_ddY = (rand() % 10) / 30.0 + 0.5;
			break;
		}
	}
	else
	{
		m_dCoordX = x;
		m_dCoordY = y;
		m_ddX = (rand() % 5) / 30.0 - 0.25;
		m_ddY = (rand() % 10) / 30.0 + 0.5;
	}
}

double Asteroid::getCoordX() const
{
	return m_dCoordX;
}

double Asteroid::getCoordY() const
{
	return m_dCoordY;
}

int Asteroid::getRadius() const
{
	return m_iRadius;
}

void Asteroid::update()
{
	m_dCoordX += m_ddX;
	m_dCoordY += m_ddY;
	if (m_dCoordX < 0.0)
	{
		m_dCoordX += 1800.0;
	}
	if (m_dCoordX > 1799.0)
	{
		m_dCoordX -= 1800.0;
	}
	if (m_dCoordY < 0.0)
	{
		m_dCoordY += 900.0;
	}
	if (m_dCoordY > 899.0)
	{
		m_dCoordY -= 900.0;
	}
}

void Asteroid::render() const
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
	int x = 0, y = m_iRadius, gap = 0, delta = (2 - (m_iRadius << 1));
	while (y >= 0)
	{
		SDL_RenderDrawPoint(m_pRenderer, m_dCoordX + x, m_dCoordY + y);
		SDL_RenderDrawPoint(m_pRenderer, m_dCoordX + x, m_dCoordY - y);
		SDL_RenderDrawPoint(m_pRenderer, m_dCoordX - x, m_dCoordY - y);
		SDL_RenderDrawPoint(m_pRenderer, m_dCoordX - x, m_dCoordY + y);
		gap = ((delta + y) << 1) - 1;
		if (delta < 0 && gap <= 0)
		{
			++x;
			delta += (x << 1) + 1;
			continue;
		}
		if (delta > 0 && gap > 0)
		{
			--y;
			delta -= (y << 1) + 1;
			continue;
		}
		++x;
		delta += ((x - y) << 1);
		--y;
	}
}
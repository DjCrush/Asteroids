#include "Ship.h"

Ship::Ship() :
	m_dCoordX(1800 / 2),
	m_dCoordY(900 / 2),
	m_dDX(0.0),
	m_dDY(0.0),
	m_iAngleRotation(0),
	m_iSpeed(0.0),
	m_iRotationDirection(0),
	m_arPoints{ { {0.0, -20.0}, {10, 20.0}, {-10.0, 20.0} } }
{}

void Ship::render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, m_arPoints[0].first + m_dCoordX, m_arPoints[0].second + m_dCoordY, 
				m_arPoints[1].first + m_dCoordX, m_arPoints[1].second + m_dCoordY);
	SDL_RenderDrawLine(renderer, m_arPoints[1].first + m_dCoordX, m_arPoints[1].second + m_dCoordY, 
				m_arPoints[2].first + m_dCoordX, m_arPoints[2].second + m_dCoordY);
	SDL_RenderDrawLine(renderer, m_arPoints[2].first + m_dCoordX, m_arPoints[2].second + m_dCoordY, 
				m_arPoints[0].first + m_dCoordX, m_arPoints[0].second + m_dCoordY);

	if(m_bThrust)
	{
		double length = (rand() % 10) / 10.0 + 1;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, m_arPoints[1].first + m_dCoordX, m_arPoints[1].second + m_dCoordY,
						-length * m_arPoints[0].first + m_dCoordX, -length * m_arPoints[0].second + m_dCoordY);
		SDL_RenderDrawLine(renderer, m_arPoints[2].first + m_dCoordX, m_arPoints[2].second + m_dCoordY,
					-length * m_arPoints[0].first + m_dCoordX, -length * m_arPoints[0].second + m_dCoordY);
	}
}

void Ship::setRotate(int rotationDirection)
{
	m_iRotationDirection = rotationDirection;
}

void Ship::setThrust(bool isAvailable, SDL_Renderer* renderer)
{
	m_bThrust = isAvailable;
	if(isAvailable)
	{
		m_dDX += sin(m_iAngleRotation * M_PI / 180.0) * 0.01;
		m_dDY += -cos(m_iAngleRotation * M_PI / 180.0) * 0.01;
	}

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, m_arPoints[0].first + m_dCoordX, m_arPoints[0].second + m_dCoordY,
		m_arPoints[1].first + m_dCoordX, m_arPoints[1].second + m_dCoordY);
}

void Ship::update()
{
	m_dCoordX += m_dDX;
	m_dCoordY += m_dDY;
	if(m_dCoordX < 0.0)
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
	if (m_iRotationDirection != 0)
	{
		m_iAngleRotation += m_iRotationDirection;
		if (m_iAngleRotation > 359)
		{
			m_iAngleRotation -= 360;
		}
		if (m_iAngleRotation < 0)
		{
			m_iAngleRotation += 359;
		}
		double dRad = 0.01745329251994329576923690768489;
		if (m_iRotationDirection < 0)
		{
			dRad = -dRad;
		}
		const double dCos = cos(dRad);
		const double dSin = sin(dRad);
		for (auto& [x, y] : m_arPoints)
		{
			const double dTemp = x * dCos - y * dSin;
			y = x * dSin + y * dCos;
			x = dTemp;
		}
	}
}

double Ship::getCoordX() const
{
	return m_dCoordX;
}

double Ship::getCoordY() const
{
	return m_dCoordY ;
}

int Ship::getAngle() const
{
	return m_iAngleRotation;
}